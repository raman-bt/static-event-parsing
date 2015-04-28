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

#if !defined( _PYEVT_FILE_FLAGS_H )
#define _PYEVT_FILE_FLAGS_H

#include <common.h>
#include <types.h>

#include "pyevt_libevt.h"
#include "pyevt_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyevt_file_flags pyevt_file_flags_t;

struct pyevt_file_flags
{
	/* Python object initialization
	 */
	PyObject_HEAD
};

extern PyTypeObject pyevt_file_flags_type_object;

int pyevt_file_flags_init_type(
     PyTypeObject *type_object );

PyObject *pyevt_file_flags_new(
           void );

int pyevt_file_flags_init(
     pyevt_file_flags_t *pyevt_file_flags );

void pyevt_file_flags_free(
      pyevt_file_flags_t *pyevt_file_flags );

#if defined( __cplusplus )
}
#endif

#endif

