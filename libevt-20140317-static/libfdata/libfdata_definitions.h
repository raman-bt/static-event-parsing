/*
 * The internal definitions
 *
 * Copyright (c) 2010-2014, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBFDATA_INTERNAL_DEFINITIONS_H )
#define _LIBFDATA_INTERNAL_DEFINITIONS_H

#include <common.h>

/* Define HAVE_LOCAL_LIBFDATA for local use of libfdata
 */
#if !defined( HAVE_LOCAL_LIBFDATA )
#include <libfdata/definitions.h>

/* The definitions in <libfdata/definitions.h> are copied here
 * for local use of libfdata
 */
#else
#define LIBFDATA_VERSION						20140206

/* The libfdata version string
 */
#define LIBFDATA_VERSION_STRING						"20140206"

/* The library flag definitions
 */
enum LIBFDATA_FLAGS
{
	/* The data handle is not managed by the library
	 */
        LIBFDATA_FLAG_DATA_HANDLE_NON_MANAGED				= 0x00,

	/* The data handle is managed by the library
	 */
        LIBFDATA_FLAG_DATA_HANDLE_MANAGED				= 0x01,

	/* The mapped ranges need to be calculated
	 */
	LIBFDATA_FLAG_CALCULATE_MAPPED_RANGES				= 0x80
};

/* The buffer data flag definitions
 */
enum LIBFDATA_BUFFER_DATA_FLAGS
{
	LIBFDATA_BUFFER_DATA_FLAG_NON_MANAGED				= LIBFDATA_FLAG_DATA_HANDLE_NON_MANAGED,
	LIBFDATA_BUFFER_DATA_FLAG_MANAGED				= LIBFDATA_FLAG_DATA_HANDLE_MANAGED
};

/* The list element value flag definitions
 */
enum LIBFDATA_LIST_ELEMENT_VALUE_FLAGS
{
	LIBFDATA_LIST_ELEMENT_VALUE_FLAG_NON_MANAGED			= LIBFDATA_FLAG_DATA_HANDLE_NON_MANAGED,
	LIBFDATA_LIST_ELEMENT_VALUE_FLAG_MANAGED			= LIBFDATA_FLAG_DATA_HANDLE_MANAGED
};

/* The range flag definitions
 */
enum LIBFDATA_RANGE_FLAGS
{
	/* The range is sparse
	 */
        LIBFDATA_RANGE_FLAG_IS_SPARSE					= 0x00000001UL,

	/* The range is compressed
	 */
        LIBFDATA_RANGE_FLAG_IS_COMPRESSED				= 0x00000002UL,

	/* User defined flags
	 */
        LIBFDATA_RANGE_FLAG_USER_DEFINED_1				= 0x00000100UL,
        LIBFDATA_RANGE_FLAG_USER_DEFINED_2				= 0x00000200UL,
        LIBFDATA_RANGE_FLAG_USER_DEFINED_3				= 0x00000400UL,
        LIBFDATA_RANGE_FLAG_USER_DEFINED_4				= 0x00000800UL,
        LIBFDATA_RANGE_FLAG_USER_DEFINED_5				= 0x00001000UL,
        LIBFDATA_RANGE_FLAG_USER_DEFINED_6				= 0x00002000UL,
        LIBFDATA_RANGE_FLAG_USER_DEFINED_7				= 0x00004000UL,
        LIBFDATA_RANGE_FLAG_USER_DEFINED_8				= 0x00008000UL,
};

#define LIBFDATA_RANGE_FLAG_MAXIMUM \
	LIBFDATA_RANGE_FLAG_USER_DEFINED_8

/* The read flag definitions
 */
enum LIBFDATA_READ_FLAGS
{
	/* Ignore data cached by the library
	 */
        LIBFDATA_READ_FLAG_IGNORE_CACHE					= 0x01
};

/* The reference type definitions
 */
enum LIBFDATA_REFERENCE_TYPES
{
	LIBFDATA_REFERENCE_TYPE_BUFFER					= 1,
	LIBFDATA_REFERENCE_TYPE_STREAM					= 2
};

/* The reference flag definitions
 */
enum LIBFDATA_REFERENCE_FLAGS
{
	LIBFDATA_REFERENCE_FLAG_NON_MANAGED				= LIBFDATA_FLAG_DATA_HANDLE_NON_MANAGED,
	LIBFDATA_REFERENCE_FLAG_MANAGED					= LIBFDATA_FLAG_DATA_HANDLE_MANAGED
};

/* The segment data flag definitions
 */
enum LIBFDATA_SEGMENT_DATA_FLAGS
{
	LIBFDATA_SEGMENT_DATA_FLAG_NON_MANAGED				= LIBFDATA_FLAG_DATA_HANDLE_NON_MANAGED,
	LIBFDATA_SEGMENT_DATA_FLAG_MANAGED				= LIBFDATA_FLAG_DATA_HANDLE_MANAGED
};

/* The tree node comparison definitions
 */
enum LIBFDATA_TREE_NODE_COMPARE_DEFINITIONS
{
	/* The first node value is less than the second node value
	 */
        LIBFDATA_TREE_NODE_COMPARE_LESS,

	/* The first and second node values are equal
	 */
        LIBFDATA_TREE_NODE_COMPARE_EQUAL,

	/* The first node value is greater than the second node value
	 */
        LIBFDATA_TREE_NODE_COMPARE_GREATER
};

/* The tree node flag definitions
 */
enum LIBFDATA_TREE_NODE_FLAGS
{
	/* The node is virtual
	 */
	LIBFDATA_TREE_NODE_FLAG_IS_VIRTUAL				= 0x02,

	/* The node is deleted
	 */
	LIBFDATA_TREE_NODE_FLAG_IS_DELETED				= 0x04,

	/* The node is a leaf
	 */
	LIBFDATA_TREE_NODE_FLAG_IS_LEAF					= 0x08,

	/* The sub nodes data range was set
	 */
	LIBFDATA_TREE_NODE_FLAG_SUB_NODES_DATA_RANGE_SET		= 0x10,

	/* The sub nodes have been read
	 */
	LIBFDATA_TREE_NODE_FLAG_SUB_NODES_READ				= 0x20,

	/* The node data has been read (at least once)
	 */
	LIBFDATA_TREE_NODE_FLAG_NOTE_DATA_READ				= 0x40
};

/* The tree node insert flag definitions
 */
enum LIBFDATA_TREE_NODE_INSERT_FLAGS
{
	/* Allow duplicate sub node values
	 */
	LIBFDATA_TREE_NODE_INSERT_FLAG_NON_UNIQUE_SUB_NODE_VALUES	= 0x00,

	/* Only allow unique sub node values, no duplicates
	 */
	LIBFDATA_TREE_NODE_INSERT_FLAG_UNIQUE_SUB_NODE_VALUES		= 0x01,
};

/* The tree node value flag definitions
 */
enum LIBFDATA_TREE_NODE_VALUE_FLAGS
{
	LIBFDATA_TREE_NODE_VALUE_FLAG_NON_MANAGED			= LIBFDATA_FLAG_DATA_HANDLE_NON_MANAGED,
	LIBFDATA_TREE_NODE_VALUE_FLAG_MANAGED				= LIBFDATA_FLAG_DATA_HANDLE_MANAGED
};

/* The vector element value flag definitions
 */
enum LIBFDATA_VECTOR_ELEMENT_VALUE_FLAGS
{
	LIBFDATA_VECTOR_ELEMENT_VALUE_FLAG_NON_MANAGED			= LIBFDATA_FLAG_DATA_HANDLE_NON_MANAGED,
	LIBFDATA_VECTOR_ELEMENT_VALUE_FLAG_MANAGED			= LIBFDATA_FLAG_DATA_HANDLE_MANAGED
};

#endif

/* The list flag definitions
 */
enum LIBFDATA_LIST_FLAGS
{
	LIBFDATA_LIST_FLAG_HAS_MAPPED_OFFSET				= 0x10
};

/* The list element flag definitions
 */
enum LIBFDATA_LIST_ELEMENT_FLAGS
{
	LIBFDATA_LIST_ELEMENT_FLAG_HAS_MAPPED_SIZE			= 0x10
};

#endif

