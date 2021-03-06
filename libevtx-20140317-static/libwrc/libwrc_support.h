/*
 * Support functions
 *
 * Copyright (c) 2011-2012, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBWRC_SUPPORT_H )
#define _LIBWRC_SUPPORT_H

#include <common.h>
#include <types.h>

#include "libwrc_extern.h"
#include "libwrc_libbfio.h"
#include "libwrc_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

#if !defined( HAVE_LOCAL_LIBWRC )

LIBWRC_EXTERN \
const char *libwrc_get_version(
             void );

LIBWRC_EXTERN \
int libwrc_get_access_flags_read(
     void );

LIBWRC_EXTERN \
int libwrc_get_codepage(
     int *codepage,
     libcerror_error_t **error );

LIBWRC_EXTERN \
int libwrc_set_codepage(
     int codepage,
     libcerror_error_t **error );

#endif /* !defined( HAVE_LOCAL_LIBWRC ) */

#if defined( __cplusplus )
}
#endif

#endif

