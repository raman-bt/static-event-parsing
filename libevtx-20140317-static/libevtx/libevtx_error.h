/*
 * Error functions
 *
 * Copyright (c) 2011-2014, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBEVTX_INTERNAL_ERROR_H )
#define _LIBEVTX_INTERNAL_ERROR_H

#include <common.h>
#include <types.h>

#include <stdio.h>

#if !defined( HAVE_LOCAL_LIBEVTX )
#include <libevtx/error.h>
#endif

#include "libevtx_extern.h"

#if defined( __cplusplus )
extern "C" {
#endif

#if !defined( HAVE_LOCAL_LIBEVTX )

LIBEVTX_EXTERN \
void libevtx_error_free(
      libevtx_error_t **error );

LIBEVTX_EXTERN \
int libevtx_error_fprint(
     libevtx_error_t *error,
     FILE *stream );

LIBEVTX_EXTERN \
int libevtx_error_sprint(
     libevtx_error_t *error,
     char *string,
     size_t size );

LIBEVTX_EXTERN \
int libevtx_error_backtrace_fprint(
     libevtx_error_t *error,
     FILE *stream );

LIBEVTX_EXTERN \
int libevtx_error_backtrace_sprint(
     libevtx_error_t *error,
     char *string,
     size_t size );

#endif

#if defined( __cplusplus )
}
#endif

#endif

