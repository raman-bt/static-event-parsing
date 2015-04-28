/*
 * File functions
 *
 * Copyright (c) 2008-2014, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBCDIRECTORY_DEFINITIONS_H )
#define _LIBCDIRECTORY_DEFINITIONS_H

#include <common.h>
#include <types.h>

#if defined( __cplusplus )
extern "C" {
#endif

#define LIBCDIRECTORY_VERSION		 		20140105

/* The libcdirectory version string
 */
#define LIBCDIRECTORY_VERSION_STRING			"20140105"

/* The directory entry type definitions
 */
enum LIBCDIRECTORY_ENTRY_TYPES
{
	LIBCDIRECTORY_ENTRY_TYPE_UNDEFINED,
	LIBCDIRECTORY_ENTRY_TYPE_DEVICE,
	LIBCDIRECTORY_ENTRY_TYPE_DIRECTORY,
	LIBCDIRECTORY_ENTRY_TYPE_FILE,
	LIBCDIRECTORY_ENTRY_TYPE_LINK,
	LIBCDIRECTORY_ENTRY_TYPE_PIPE,
	LIBCDIRECTORY_ENTRY_TYPE_SOCKET
};

/* The directory entry compare flags
 */
enum LIBCDIRECTORY_COMPARE_FLAGS
{
	LIBCDIRECTORY_COMPARE_FLAG_NO_CASE		= 0x01
};

#if defined( __cplusplus )
}
#endif

#endif

