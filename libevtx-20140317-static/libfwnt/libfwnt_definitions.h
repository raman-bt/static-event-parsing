/*
 * The internal definitions
 *
 * Copyright (c) 2009-2014, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( LIBFWNT_INTERNAL_DEFINITIONS_H )
#define LIBFWNT_INTERNAL_DEFINITIONS_H

#include <common.h>
#include <types.h>

/* Define HAVE_LOCAL_LIBFWNT for local use of libfwnt
 */
#if !defined( HAVE_LOCAL_LIBFWNT )
#include <libfwnt/definitions.h>

/* The definitions in <libfwnt/definitions.h> are copied here
 * for local use of libfwnt
 */
#else
#include <byte_stream.h>

#define LIBFWNT_VERSION					20140105

/* The version string
 */
#define LIBFWNT_VERSION_STRING				"20140105"


/* The endian definitions
 */
#define LIBFWNT_ENDIAN_BIG				_BYTE_STREAM_ENDIAN_BIG
#define LIBFWNT_ENDIAN_LITTLE				_BYTE_STREAM_ENDIAN_LITTLE

/* The security identifier (SID) authorities
 */
enum LIBFWNT_SECURITY_IDENTIFIER_AUTHORITIES
{
	LIBFWNT_AUTHORITY_NULL				= 0x00,
	LIBFWNT_AUTHORITY_WORLD				= 0x01,
	LIBFWNT_AUTHORITY_LOCAL				= 0x02,
	LIBFWNT_AUTHORITY_CREATOR			= 0x03,
	LIBFWNT_AUTHORITY_NON_UNIQUE			= 0x04,
	LIBFWNT_AUTHORITY_NT_AUTHORITY			= 0x05,

	LIBFWNT_AUTHORITY_EXCHANGE_2007			= 0x09
};

#endif

/* TODO add equivalent security descriptor control flags definitions
0x0001 SE_OWNER_DEFAULTED
0x0002 SE_GROUP_DEFAULTED
0x0004 SE_DACL_PRESENT
0x0008 SE_DACL_DEFAULTED
0x0010 SE_SACL_PRESENT
0x0100 SE_DACL_AUTO_INHERIT_REQ
0x0200 SE_SACL_AUTO_INHERIT_REQ
0x0400 SE_DACL_AUTO_INHERITED
0x0800 SE_SACL_AUTO_INHERITED
0x1000 SE_DACL_PROTECTED
0x2000 SE_SACL_PROTECTED
0x4000 SE_RM_CONTROL_VALID
0x8000 SE_SELF_RELATIVE
*/

#endif

