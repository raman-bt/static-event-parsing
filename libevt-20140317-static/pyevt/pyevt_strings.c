/*
 * Python object definition of the strings sequence and iterator
 *
 * Copyright (C) 2011-2014, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <memory.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyevt_libcerror.h"
#include "pyevt_libevt.h"
#include "pyevt_python.h"
#include "pyevt_record.h"
#include "pyevt_strings.h"

PySequenceMethods pyevt_strings_sequence_methods = {
	/* sq_length */
	(lenfunc) pyevt_strings_len,
	/* sq_concat */
	0,
	/* sq_repeat */
	0,
	/* sq_item */
	(ssizeargfunc) pyevt_strings_getitem,
	/* sq_slice */
	0,
	/* sq_ass_item */
	0,
	/* sq_ass_slice */
	0,
	/* sq_contains */
	0,
	/* sq_inplace_concat */
	0,
	/* sq_inplace_repeat */
	0
};

PyTypeObject pyevt_strings_type_object = {
	PyObject_HEAD_INIT( NULL )

	/* ob_size */
	0,
	/* tp_name */
	"pyevt._strings",
	/* tp_basicsize */
	sizeof( pyevt_strings_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyevt_strings_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	&pyevt_strings_sequence_methods,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
        /* tp_flags */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_ITER,
	/* tp_doc */
	"internal pyevt strings sequence and iterator object",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	(getiterfunc) pyevt_strings_iter,
	/* tp_iternext */
	(iternextfunc) pyevt_strings_iternext,
	/* tp_methods */
	0,
	/* tp_members */
	0,
	/* tp_getset */
	0,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pyevt_strings_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Creates a new strings object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyevt_strings_new(
           pyevt_record_t *record_object,
           PyObject* (*get_string_by_index)(
                        pyevt_record_t *record_object,
                        int string_index ),
           int number_of_strings )
{
	pyevt_strings_t *pyevt_strings = NULL;
	static char *function          = "pyevt_strings_new";

	if( record_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid record object.",
		 function );

		return( NULL );
	}
	if( get_string_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid get string by index function.",
		 function );

		return( NULL );
	}
	/* Make sure the strings values are initialized
	 */
	pyevt_strings = PyObject_New(
	                  struct pyevt_strings,
	                  &pyevt_strings_type_object );

	if( pyevt_strings == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize strings.",
		 function );

		goto on_error;
	}
	if( pyevt_strings_init(
	     pyevt_strings ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize strings.",
		 function );

		goto on_error;
	}
	pyevt_strings->record_object       = record_object;
	pyevt_strings->get_string_by_index = get_string_by_index;
	pyevt_strings->number_of_strings   = number_of_strings;

	Py_IncRef(
	 (PyObject *) pyevt_strings->record_object );

	return( (PyObject *) pyevt_strings );

on_error:
	if( pyevt_strings != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyevt_strings );
	}
	return( NULL );
}

/* Intializes a strings object
 * Returns 0 if successful or -1 on error
 */
int pyevt_strings_init(
     pyevt_strings_t *pyevt_strings )
{
	static char *function = "pyevt_strings_init";

	if( pyevt_strings == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings.",
		 function );

		return( -1 );
	}
	/* Make sure the strings values are initialized
	 */
	pyevt_strings->record_object       = NULL;
	pyevt_strings->get_string_by_index = NULL;
	pyevt_strings->string_index        = 0;
	pyevt_strings->number_of_strings   = 0;

	return( 0 );
}

/* Frees a strings object
 */
void pyevt_strings_free(
      pyevt_strings_t *pyevt_strings )
{
	static char *function = "pyevt_strings_free";

	if( pyevt_strings == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings.",
		 function );

		return;
	}
	if( pyevt_strings->ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings - missing ob_type.",
		 function );

		return;
	}
	if( pyevt_strings->ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings - invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	if( pyevt_strings->record_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyevt_strings->record_object );
	}
	pyevt_strings->ob_type->tp_free(
	 (PyObject*) pyevt_strings );
}

/* The strings len() function
 */
Py_ssize_t pyevt_strings_len(
            pyevt_strings_t *pyevt_strings )
{
	static char *function = "pyevt_strings_len";

	if( pyevt_strings == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings.",
		 function );

		return( -1 );
	}
	return( (Py_ssize_t) pyevt_strings->number_of_strings );
}

/* The strings getitem() function
 */
PyObject *pyevt_strings_getitem(
           pyevt_strings_t *pyevt_strings,
           Py_ssize_t item_index )
{
	PyObject *string_object = NULL;
	static char *function   = "pyevt_strings_getitem";

	if( pyevt_strings == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings.",
		 function );

		return( NULL );
	}
	if( pyevt_strings->get_string_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings - missing get string by index function.",
		 function );

		return( NULL );
	}
	if( pyevt_strings->number_of_strings < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings - invalid number of strings.",
		 function );

		return( NULL );
	}
	if( ( item_index < 0 )
	 || ( item_index >= (Py_ssize_t) pyevt_strings->number_of_strings ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid invalid item index value out of bounds.",
		 function );

		return( NULL );
	}
	string_object = pyevt_strings->get_string_by_index(
	                 pyevt_strings->record_object,
	                 (int) item_index );

	return( string_object );
}

/* The strings iter() function
 */
PyObject *pyevt_strings_iter(
           pyevt_strings_t *pyevt_strings )
{
	static char *function = "pyevt_strings_iter";

	if( pyevt_strings == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings.",
		 function );

		return( NULL );
	}
	Py_IncRef(
	 (PyObject *) pyevt_strings );

	return( (PyObject *) pyevt_strings );
}

/* The strings iternext() function
 */
PyObject *pyevt_strings_iternext(
           pyevt_strings_t *pyevt_strings )
{
	PyObject *string_object = NULL;
	static char *function   = "pyevt_strings_iternext";

	if( pyevt_strings == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings.",
		 function );

		return( NULL );
	}
	if( pyevt_strings->get_string_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings - missing get string by index function.",
		 function );

		return( NULL );
	}
	if( pyevt_strings->string_index < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings - invalid string index.",
		 function );

		return( NULL );
	}
	if( pyevt_strings->number_of_strings < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid strings - invalid number of strings.",
		 function );

		return( NULL );
	}
	if( pyevt_strings->string_index >= pyevt_strings->number_of_strings )
	{
		PyErr_SetNone(
		 PyExc_StopIteration );

		return( NULL );
	}
	string_object = pyevt_strings->get_string_by_index(
	                 pyevt_strings->record_object,
	                 pyevt_strings->string_index );

	if( string_object != NULL )
	{
		pyevt_strings->string_index++;
	}
	return( string_object );
}

