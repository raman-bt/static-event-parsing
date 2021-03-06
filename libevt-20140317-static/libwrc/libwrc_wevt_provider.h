/*
 * WEVT provider functions
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

#if !defined( _LIBWRC_INTERNAL_WEVT_PROVIDER_H )
#define _LIBWRC_INTERNAL_WEVT_PROVIDER_H

#include <common.h>
#include <types.h>

#include "libwrc_extern.h"
#include "libwrc_libcerror.h"
#include "libwrc_libfwevt.h"
#include "libwrc_resource.h"
#include "libwrc_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libwrc_internal_wevt_provider libwrc_internal_wevt_provider_t;

struct libwrc_internal_wevt_provider
{
	/* The provider descriptor
	 */
	libfwevt_provider_t *provider_descriptor;
};

int libwrc_wevt_provider_initialize(
     libwrc_wevt_provider_t **provider,
     libfwevt_provider_t *provider_descriptor,
     libcerror_error_t **error );

LIBWRC_EXTERN \
int libwrc_wevt_provider_free(
     libwrc_wevt_provider_t **provider,
     libcerror_error_t **error );

LIBWRC_EXTERN \
int libwrc_wevt_provider_get_number_of_events(
     libwrc_wevt_provider_t *provider,
     int *number_of_events,
     libcerror_error_t **error );

LIBWRC_EXTERN \
int libwrc_wevt_provider_get_event(
     libwrc_wevt_provider_t *provider,
     int event_index,
     libwrc_wevt_event_t **event,
     libcerror_error_t **error );

LIBWRC_EXTERN \
int libwrc_wevt_provider_get_event_by_identifier(
     libwrc_wevt_provider_t *provider,
     uint32_t event_identifier,
     libwrc_wevt_event_t **event,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

