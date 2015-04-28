/*
 * Definitions for libevt
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

#if !defined( _LIBEVT_DEFINITIONS_H )
#define _LIBEVT_DEFINITIONS_H

#include <libevt/types.h>

#define LIBEVT_VERSION					20140317

/* The version string
 */
#define LIBEVT_VERSION_STRING				"20140317"

/* The access flags definitions
 * bit 1        set to 1 for read access
 * bit 2        set to 1 for write access
 * bit 3-8      not used
 */
enum LIBEVT_ACCESS_FLAGS
{
	LIBEVT_ACCESS_FLAG_READ				= 0x01,
/* Reserved: not supported yet */
	LIBEVT_ACCESS_FLAG_WRITE			= 0x02
};

/* The file access macros
 */
#define LIBEVT_OPEN_READ				( LIBEVT_ACCESS_FLAG_READ )
/* Reserved: not supported yet */
#define LIBEVT_OPEN_WRITE				( LIBEVT_ACCESS_FLAG_WRITE )
/* Reserved: not supported yet */
#define LIBEVT_OPEN_READ_WRITE				( LIBEVT_ACCESS_FLAG_READ | LIBEVT_ACCESS_FLAG_WRITE )

/* The event type definitions
 */
enum LIBEVT_EVENT_TYPES
{
	LIBEVT_EVENT_TYPE_ERROR				= 0x0001,
	LIBEVT_EVENT_TYPE_WARNING			= 0x0002,
	LIBEVT_EVENT_TYPE_INFORMATION			= 0x0004,
	LIBEVT_EVENT_TYPE_AUDIT_SUCCESS			= 0x0008,
	LIBEVT_EVENT_TYPE_AUDIT_FAILURE			= 0x0010,
};

/* The event file flags
 */
enum LIBEVT_FILE_FLAGS
{
	LIBEVT_FILE_FLAG_IS_DIRTY			= 0x00000001UL,
	LIBEVT_FILE_FLAG_HAS_WRAPPED			= 0x00000002UL,
	LIBEVT_FILE_FLAG_IS_FULL			= 0x00000004UL,
	LIBEVT_FILE_FLAG_ARCHIVE			= 0x00000008UL
};

#endif
