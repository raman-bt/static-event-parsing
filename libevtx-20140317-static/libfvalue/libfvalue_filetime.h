/*
 * Filetime functions
 *
 * Copyright (c) 2010-2013, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBFVALUE_FILETIME_H )
#define _LIBFVALUE_FILETIME_H

#include <common.h>
#include <types.h>

#include "libfvalue_libcerror.h"
#include "libfvalue_libfdatetime.h"

#if defined( __cplusplus )
extern "C" {
#endif

int libfvalue_filetime_copy_from_integer(
     libfdatetime_filetime_t *filetime,
     uint64_t integer_value,
     size_t integer_value_size,
     libcerror_error_t **error );

int libfvalue_filetime_copy_to_integer(
     libfdatetime_filetime_t *filetime,
     uint64_t *integer_value,
     size_t *integer_value_size,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

