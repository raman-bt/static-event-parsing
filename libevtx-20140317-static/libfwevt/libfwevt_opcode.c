/*
 * Opcode functions
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

#include <common.h>
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libfwevt_libcerror.h"
#include "libfwevt_libcnotify.h"
#include "libfwevt_libuna.h"
#include "libfwevt_opcode.h"
#include "libfwevt_types.h"

#include "fwevt_template.h"

/* Creates an opcode
 * Make sure the value opcode is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwevt_opcode_initialize(
     libfwevt_opcode_t **opcode,
     libcerror_error_t **error )
{
	libfwevt_internal_opcode_t *internal_opcode = NULL;
	static char *function                       = "libfwevt_opcode_initialize";

	if( opcode == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid opcode.",
		 function );

		return( -1 );
	}
	if( *opcode != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid opcode value already set.",
		 function );

		return( -1 );
	}
	internal_opcode = memory_allocate_structure(
	                   libfwevt_internal_opcode_t );

	if( internal_opcode == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create opcode.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     internal_opcode,
	     0,
	     sizeof( libfwevt_internal_opcode_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear opcode.",
		 function );

		goto on_error;
	}
	*opcode = (libfwevt_opcode_t *) internal_opcode;

	return( 1 );

on_error:
	if( internal_opcode != NULL )
	{
		memory_free(
		 internal_opcode );
	}
	return( -1 );
}

/* Frees an opcode
 * Returns 1 if successful or -1 on error
 */
int libfwevt_opcode_free(
     libfwevt_opcode_t **opcode,
     libcerror_error_t **error )
{
	libfwevt_internal_opcode_t *internal_opcode = NULL;
	static char *function                       = "libfwevt_opcode_free";

	if( opcode == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid opcode.",
		 function );

		return( -1 );
	}
	if( *opcode != NULL )
	{
		internal_opcode = (libfwevt_internal_opcode_t *) *opcode;
		*opcode         = NULL;

		memory_free(
		 internal_opcode );
	}
	return( 1 );
}

/* Reads the opcode
 * Returns 1 if successful or -1 on error
 */
int libfwevt_opcode_read(
     libfwevt_opcode_t *opcode,
     const uint8_t *data,
     size_t data_size,
     size_t data_offset,
     libcerror_error_t **error )
{
/* TODO
	libfwevt_internal_opcode_t *internal_opcode = NULL;
*/
	fwevt_template_opcode_t *wevt_opcode        = NULL;
	static char *function                       = "libfwevt_opcode_read";
	uint32_t opcode_data_offset                 = 0;
	uint32_t opcode_data_size                   = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	libcstring_system_character_t *value_string = NULL;
	size_t value_string_size                    = 0;
	uint32_t value_32bit                        = 0;
	int result                                  = 0;
#endif

	if( opcode == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid opcode.",
		 function );

		return( -1 );
	}
/* TODO
	internal_opcode = (libfwevt_internal_opcode_t *) opcode;
*/

	if( data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid data.",
		 function );

		return( -1 );
	}
	if( data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid data size value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( data_offset >= data_size )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid data offset value out of bounds.",
		 function );

		return( -1 );
	}
	if( ( data_size < sizeof( fwevt_template_opcode_t ) )
	 || ( data_offset > ( data_size - sizeof( fwevt_template_opcode_t ) ) ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: invalid data value too small.",
		 function );

		return( -1 );
	}
	wevt_opcode = (fwevt_template_opcode_t *) &( data[ data_offset ] );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: opcode data:\n",
		 function );
		libcnotify_print_data(
		 (uint8_t *) wevt_opcode,
		 sizeof( fwevt_template_opcode_t ),
		 0 );
	}
#endif
	byte_stream_copy_to_uint32_little_endian(
	 wevt_opcode->data_offset,
	 opcode_data_offset );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		byte_stream_copy_to_uint32_little_endian(
		 wevt_opcode->identifier,
		 value_32bit );
		libcnotify_printf(
		 "%s: identifier\t\t\t\t\t: %" PRIu32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 wevt_opcode->message_identifier,
		 value_32bit );
		libcnotify_printf(
		 "%s: message identifier\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		libcnotify_printf(
		 "%s: data offset\t\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 opcode_data_offset );
	}
#endif
	if( opcode_data_offset > 0 )
	{
		if( opcode_data_offset >= data_size )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid opcode data offset value out of bounds.",
			 function );

			goto on_error;
		}
		if( ( opcode_data_size > data_size )
		 || ( ( opcode_data_offset + opcode_data_size ) > data_size ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid opcode data size value out of bounds.",
			 function );

			goto on_error;
		}
		byte_stream_copy_to_uint32_little_endian(
		 &( data[ opcode_data_offset ] ),
		 opcode_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: data:\n",
			 function );
			libcnotify_print_data(
			 &( data[ opcode_data_offset ] ),
			 opcode_data_size,
			 0 );
		}
#endif
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: data size\t\t\t\t\t\t: %" PRIu32 "\n",
			 function,
			 opcode_data_size );
		}
		opcode_data_offset += 4;
		opcode_data_size   -= 4;
#endif

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_size_from_utf16_stream(
				  &( data[ opcode_data_offset ] ),
				  opcode_data_size,
				  LIBUNA_ENDIAN_LITTLE,
				  &value_string_size,
				  error );
#else
			result = libuna_utf8_string_size_from_utf16_stream(
				  &( data[ opcode_data_offset ] ),
				  opcode_data_size,
				  LIBUNA_ENDIAN_LITTLE,
				  &value_string_size,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
				 "%s: unable to determine size of data string.",
				 function );

				goto on_error;
			}
			if( ( value_string_size > (size_t) SSIZE_MAX )
			 || ( ( sizeof( libcstring_system_character_t ) * value_string_size )  > (size_t) SSIZE_MAX ) )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
				 "%s: invalid data string size value exceeds maximum.",
				 function );

				goto on_error;
			}
			value_string = libcstring_system_string_allocate(
					value_string_size );

			if( value_string == NULL )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_MEMORY,
				 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
				 "%s: unable to create data string.",
				 function );

				goto on_error;
			}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_copy_from_utf16_stream(
				  (libuna_utf16_character_t *) value_string,
				  value_string_size,
				  &( data[ opcode_data_offset ] ),
				  opcode_data_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#else
			result = libuna_utf8_string_copy_from_utf16_stream(
				  (libuna_utf8_character_t *) value_string,
				  value_string_size,
				  &( data[ opcode_data_offset ] ),
				  opcode_data_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
				 "%s: unable to set data string.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: name\t\t\t\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 value_string );

			memory_free(
			 value_string );

			value_string = NULL;
		}
#endif
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "\n" );
	}
#endif
	return( 1 );

on_error:
#if defined( HAVE_DEBUG_OUTPUT )
	if( value_string != NULL )
	{
		memory_free(
		 value_string );
	}
#endif
	return( -1 );
}

