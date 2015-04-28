/*
 * Python object definition of the libevt file flags
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
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyevt_file_flags.h"
#include "pyevt_libevt.h"
#include "pyevt_python.h"
#include "pyevt_unused.h"

PyTypeObject pyevt_file_flags_type_object = {
	PyObject_HEAD_INIT( NULL )

	/* ob_size */
	0,
	/* tp_name */
	"pyevt.file_flags",
	/* tp_basicsize */
	sizeof( pyevt_file_flags_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyevt_file_flags_free,
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
	0,
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
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pyevt file flags object (wraps LIBEVT_FILE_FLAGS)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
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
	(initproc) pyevt_file_flags_init,
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

/* Initializes the type object
 * Returns 1 if successful or -1 on error
 */
int pyevt_file_flags_init_type(
     PyTypeObject *type_object )
{
	if( type_object == NULL )
	{
		return( -1 );
	}
	type_object->tp_dict = PyDict_New();

	if( type_object->tp_dict == NULL )
	{
		return( -1 );
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "IS_DIRTY",
             PyInt_FromLong(
              LIBEVT_FILE_FLAG_IS_DIRTY ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "HAS_WRAPPED",
             PyInt_FromLong(
              LIBEVT_FILE_FLAG_HAS_WRAPPED ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "IS_FULL",
             PyInt_FromLong(
              LIBEVT_FILE_FLAG_IS_FULL ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "ARCHIVE",
             PyInt_FromLong(
              LIBEVT_FILE_FLAG_ARCHIVE ) ) != 0 )
	{
		goto on_error;
	}
	return( 1 );

on_error:
	if( type_object->tp_dict != NULL )
	{
		Py_DecRef(
		 type_object->tp_dict );

		type_object->tp_dict = NULL;
	}
	return( -1 );
}

/* Creates a new file flags object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyevt_file_flags_new(
           void )
{
	pyevt_file_flags_t *pyevt_file_flags = NULL;
	static char *function                = "pyevt_file_flags_new";

	pyevt_file_flags = PyObject_New(
	                    struct pyevt_file_flags,
	                    &pyevt_file_flags_type_object );

	if( pyevt_file_flags == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize file flags.",
		 function );

		goto on_error;
	}
	if( pyevt_file_flags_init(
	     pyevt_file_flags ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize file flags.",
		 function );

		goto on_error;
	}
	return( (PyObject *) pyevt_file_flags );

on_error:
	if( pyevt_file_flags != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyevt_file_flags );
	}
	return( NULL );
}

/* Intializes a file flags object
 * Returns 0 if successful or -1 on error
 */
int pyevt_file_flags_init(
     pyevt_file_flags_t *pyevt_file_flags )
{
	static char *function = "pyevt_file_flags_init";

	if( pyevt_file_flags == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file flags.",
		 function );

		return( -1 );
	}
	return( 0 );
}

/* Frees a file flags object
 */
void pyevt_file_flags_free(
      pyevt_file_flags_t *pyevt_file_flags )
{
	static char *function = "pyevt_file_flags_free";

	if( pyevt_file_flags == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file flags.",
		 function );

		return;
	}
	if( pyevt_file_flags->ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file flags - missing ob_type.",
		 function );

		return;
	}
	if( pyevt_file_flags->ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file flags - invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	pyevt_file_flags->ob_type->tp_free(
	 (PyObject*) pyevt_file_flags );
}

