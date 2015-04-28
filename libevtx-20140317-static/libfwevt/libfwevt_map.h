/*
 * Map functions
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

#if !defined( _LIBFWEVT_INTERNAL_MAP_H )
#define _LIBFWEVT_INTERNAL_MAP_H

#include <common.h>
#include <types.h>

#include "libfwevt_extern.h"
#include "libfwevt_libcerror.h"
#include "libfwevt_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfwevt_internal_map libfwevt_internal_map_t;

struct libfwevt_internal_map
{
	/* The identifier
	 */
	uint16_t identifier;
};

LIBFWEVT_EXTERN \
int libfwevt_map_initialize(
     libfwevt_map_t **map,
     libcerror_error_t **error );

LIBFWEVT_EXTERN \
int libfwevt_map_free(
     libfwevt_map_t **map,
     libcerror_error_t **error );

LIBFWEVT_EXTERN \
int libfwevt_map_read(
     libfwevt_map_t *map,
     const uint8_t *data,
     size_t data_size,
     size_t data_offset,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif
