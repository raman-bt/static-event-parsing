/*
 * Extracts items from a Windows Event Log (EVT) file
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
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_UNISTD_H )
#include <unistd.h>
#endif

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "evtexport.h"

#include "evtinput.h"
#include "evtoutput.h"
#include "evttools_libcerror.h"
#include "evttools_libclocale.h"
#include "evttools_libcnotify.h"
#include "evttools_libcstring.h"
#include "evttools_libcsystem.h"
#include "evttools_libevt.h"
#include "export_handle.h"
#include "log_handle.h"




/**
 * evtexport - API to export an evt file  (Windows XP or older)
 *
 * @param input a_source_filename full path of the event log tp be parsed
 * @param input a_outfile handle to the output file. If null, the output is sent to console
 * @param input a_options additional options affecting event parsing
 *
 * @returns 0 if success, -1 if error.
 */
int evtexport(
     const libcstring_system_character_t *a_source_filename,
	 const FILE *a_outfile,
	 const evtexport_options_t *a_options )
{
	export_handle_t *evtexport_export_handle			= NULL;
	libcerror_error_t *error                            = NULL;
	log_handle_t *log_handle                            = NULL;
	char *program                                       = "libevtexport";
	int result                                          = 0;
	FILE *outfile_handle								= NULL;

	if( NULL == a_source_filename )	// Make sure we have a source file
	{
		fprintf( 
			stderr,
			"Missing source file.\n" );
		return -1;
	}

	if( NULL == a_options )			// Make sure we have the options spec
	{
		fprintf( 
			stderr,
			"Missing Options specification.\n" );
		return -1;
	}

	libcnotify_stream_set(
	 stderr,
	 NULL );
	libcnotify_verbose_set(
	 1 );

	if( libclocale_initialize(
	     "evttools",
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to initialize locale values.\n" );

		goto on_error;
	}
	if( libcsystem_initialize(
	     _IONBF,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to initialize system values.\n" );

		goto on_error;
	}

	evtoutput_version_fprint(
	 stdout,
	 program );


	libcnotify_verbose_set(
		a_options->option_verbose );

	libevt_notify_set_stream(
		stderr,					
		NULL );

	libevt_notify_set_verbose(
		a_options->option_verbose );

	if( log_handle_initialize(
	     &log_handle,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to initialize log handle.\n" );

		goto on_error;
	}

	if (a_outfile)
		fprintf( stderr, "evtexport: Writing output to given file....\n" );
	else 
		fprintf( stderr, "evtexport: Writing output to console....\n" );

	// set the output stream to the given file if specified. If its null, the output handle will be set to stdout
	outfile_handle = a_outfile;

	if( export_handle_initialize(
	     &evtexport_export_handle,
		 outfile_handle,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to initialize export handle.\n" );

		goto on_error;
	}
	if( a_options->option_ascii_codepage != NULL )
	{
		result = export_handle_set_ascii_codepage(
		          evtexport_export_handle,
		          a_options->option_ascii_codepage,
		          &error );

		if( result == -1 )
		{
			fprintf(
			 stderr,
			 "Unable to set ASCII codepage in export handle.\n" );

			goto on_error;
		}
		else if( result == 0 )
		{
			fprintf(
			 stderr,
			 "Unsupported ASCII codepage defaulting to: windows-1252.\n" );
		}
	}
	if( a_options->option_event_log_type != NULL )
	{
		result = export_handle_set_event_log_type(
		          evtexport_export_handle,
		          a_options->option_event_log_type,
		          &error );

		if( result == -1 )
		{
			fprintf(
			 stderr,
			 "Unable to set event log type in export handle.\n" );

			goto on_error;
		}
	}
	if( a_options->option_export_mode != NULL )
	{
		result = export_handle_set_export_mode(
			  evtexport_export_handle,
			  a_options->option_export_mode,
			  &error );

		if( result == -1 )
		{
			fprintf(
			 stderr,
			 "Unable to set export mode.\n" );

			goto on_error;
		}
		else if( result == 0 )
		{
			fprintf(
			 stderr,
			 "Unsupported export mode defaulting to: items.\n" );
		}
	}
	if( ( a_options->option_event_log_type == NULL )
	 || ( result == 0 ) )
	{
		result = export_handle_set_event_log_type_from_filename(
			  evtexport_export_handle,
			  a_source_filename,
			  &error );

		if( result == -1 )
		{
			fprintf(
			 stderr,
			 "Unable to set event log type from filename in export handle.\n" );

			goto on_error;
		}
	}
	if( a_options->option_resource_files_path != NULL )
	{
		if( export_handle_set_resource_files_path(
		     evtexport_export_handle,
		     a_options->option_resource_files_path,
		     &error ) != 1 )
		{
			fprintf(
			 stderr,
			 "Unable to set resource files path in export handle.\n" );

			goto on_error;
		}
	}
	if( a_options->option_software_registry_filename != NULL )
	{
		if( export_handle_set_software_registry_filename(
		     evtexport_export_handle,
		     a_options->option_software_registry_filename,
		     &error ) != 1 )
		{
			fprintf(
			 stderr,
			 "Unable to set software registry filename in export handle.\n" );

			goto on_error;
		}
	}
	if( a_options->option_system_registry_filename != NULL )
	{
		if( export_handle_set_system_registry_filename(
		     evtexport_export_handle,
		     a_options->option_system_registry_filename,
		     &error ) != 1 )
		{
			fprintf(
			 stderr,
			 "Unable to set system registry filename in export handle.\n" );

			goto on_error;
		}
	}
	if( a_options->option_registry_directory_name != NULL )
	{
		if( export_handle_set_registry_directory_name(
		     evtexport_export_handle,
		     a_options->option_registry_directory_name,
		     &error ) != 1 )
		{
			fprintf(
			 stderr,
			 "Unable to set registry directory name in export handle.\n" );

			goto on_error;
		}
	}
	if( a_options->option_preferred_language != NULL )
	{
/* TODO set preferred language identifier from input */
		if( export_handle_set_preferred_language_identifier(
		     evtexport_export_handle,
		     0x0409,
		     &error ) != 1 )
		{
			fprintf(
			 stderr,
			 "Unable to set preferred language identifier in export handle.\n" );

			goto on_error;
		}
	}
	if( log_handle_open(
	     log_handle,
	     a_options->option_log_filename,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to open log file: %" PRIs_LIBCSTRING_SYSTEM ".\n",
		 a_options->option_log_filename );

		goto on_error;
	}
	if( export_handle_open_input(
	     evtexport_export_handle,
	     a_source_filename,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to open: %" PRIs_LIBCSTRING_SYSTEM ".\n",
		 a_source_filename );

		goto on_error;
	}
	result = export_handle_export_file(
	          evtexport_export_handle,
	          log_handle,
	          &error );

	if( result == -1 )
	{
		fprintf(
		 stderr,
		 "Unable to export file.\n" );

		goto on_error;
	}
	if( export_handle_close_input(
	     evtexport_export_handle,
	     &error ) != 0 )
	{
		fprintf(
		 stderr,
		 "Unable to close export handle.\n" );

		goto on_error;
	}
	if( export_handle_free(
	     &evtexport_export_handle,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to free export handle.\n" );

		goto on_error;
	}
	if( log_handle_close(
	     log_handle,
	     &error ) != 0 )
	{
		fprintf(
		 stderr,
		 "Unable to close log handle.\n" );

		goto on_error;
	}
	if( log_handle_free(
	     &log_handle,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to free log handle.\n" );

		goto on_error;
	}
	if( result == 0 )
	{
		fprintf(
		 stdout,
		 "No records to export.\n" );
	}
	return( 0 );

on_error:
	if( error != NULL )
	{
		libcnotify_print_error_backtrace(
		 error );
		libcerror_error_free(
		 &error );
	}
	if( evtexport_export_handle != NULL )
	{
		export_handle_free(
		 &evtexport_export_handle,
		 NULL );
	}
	if( log_handle != NULL )
	{
		log_handle_free(
		 &log_handle,
		 NULL );
	}
	return( -1 );

}
