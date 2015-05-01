/*
 * Common input functions for the evtxtools
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

#if !defined( _EVTXEXPORT_H )
#define _EVTXEXPORT_H

#include <common.h>
#include <types.h>

#include "evtxtools_libcerror.h"
#include "evtxtools_libcstring.h"

#if defined( __cplusplus )
extern "C" {
#endif


typedef struct evtxexport_options evtxexport_options_t;

struct evtxexport_options
{
	libcstring_system_character_t *option_ascii_codepage;
	libcstring_system_character_t *option_event_log_type;
	libcstring_system_character_t *option_export_format;
	libcstring_system_character_t *option_export_mode;
	libcstring_system_character_t *option_log_filename;
	libcstring_system_character_t *option_resource_files_path;
	libcstring_system_character_t *option_preferred_language;
	libcstring_system_character_t *option_registry_directory_name;
	libcstring_system_character_t *option_software_registry_filename;
	libcstring_system_character_t *option_system_registry_filename;
	
	int option_use_template_definition;
	int option_verbose;
};

// API to export an evtx file
int evtxexport(
     const libcstring_system_character_t *source_filename,
	 const FILE *output_file,
	 const evtxexport_options_t *options
);

#if defined( __cplusplus )
}
#endif

#endif

