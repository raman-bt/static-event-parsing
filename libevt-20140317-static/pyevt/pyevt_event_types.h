/*
 * Python object definition of the libevt event types
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

#if !defined( _PYEVT_EVENT_TYPES_H )
#define _PYEVT_EVENT_TYPES_H

#include <common.h>
#include <types.h>

#include "pyevt_libevt.h"
#include "pyevt_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyevt_event_types pyevt_event_types_t;

struct pyevt_event_types
{
	/* Python object initialization
	 */
	PyObject_HEAD
};

extern PyTypeObject pyevt_event_types_type_object;

int pyevt_event_types_init_type(
     PyTypeObject *type_object );

PyObject *pyevt_event_types_new(
           void );

int pyevt_event_types_init(
     pyevt_event_types_t *pyevt_event_types );

void pyevt_event_types_free(
      pyevt_event_types_t *pyevt_event_types );

#if defined( __cplusplus )
}
#endif

#endif

