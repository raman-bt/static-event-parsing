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
#include <memory.h>
#include <types.h>

#if defined( HAVE_UNISTD_H )
#include <unistd.h>
#endif

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "evtexport.h"

//#include "evtinput.h"
#include "evtoutput.h"
//#include "evttools_libcerror.h"
//#include "evttools_libclocale.h"
//#include "evttools_libcnotify.h"
#include "evttools_libcstring.h"
#include "evttools_libcsystem.h"
#include "libbfio_definitions.h"
//#include "evttools_libevt.h"
//#include "export_handle.h"
//#include "log_handle.h"

//export_handle_t *evtexport_export_handle = NULL;
//int evtexport_abort                      = 0;

/* Prints the executable usage information
 */
void usage_fprint(
      FILE *stream )
{
	if( stream == NULL )
	{
		return;
	}
	fprintf( stream, "Use evtexport to export items stored in a Windows Event\n"
	                 "Log (EVT) file.\n\n" );

	fprintf( stream, "Usage: evtexportapp [ -c codepage ] [ -l log_file ] [ -m mode ]\n"
					 "                 [ -o output_file_pathname ]\n"
	                 "                 [ -p resource_files_path ] [ -r registy_files_path ]\n"
	                 "                 [ -s system_file ] [ -S software_file ]\n"
	                 "                 [ -t event_log_type ] [ -hvV ] source\n\n" );

	fprintf( stream, "\tsource: the source file\n\n" );

	fprintf( stream, "\t-c:     codepage of ASCII strings, options: ascii, windows-874,\n"
	                 "\t        windows-932, windows-936, windows-949, windows-950,\n"
	                 "\t        windows-1250, windows-1251, windows-1252 (default),\n"
	                 "\t        windows-1253, windows-1254, windows-1255, windows-1256\n"
	                 "\t        windows-1257 or windows-1258\n" );
	fprintf( stream, "\t-h:     shows this help\n" );
	fprintf( stream, "\t-l:     logs information about the exported items\n" );
	fprintf( stream, "\t-m:     export mode, option: all, items (default), recovered\n"
	                 "\t        'all' exports the (allocated) items and recovered items,\n"
	                 "\t        'items' exports the (allocated) items and 'recovered' exports\n"
	                 "\t        the recovered items\n" );
	fprintf( stream, "\t-o:     filename of the output file. If ommitted, output is written to console\n");
	fprintf( stream, "\t-p:     search PATH for the resource files (default is the current\n"
	                 "\t        working directory)\n" );
	fprintf( stream, "\t-r:     name of the directory containing the SOFTWARE and SYSTEM\n"
	                 "\t        (Windows) Registry file\n" );
	fprintf( stream, "\t-s:     filename of the SYSTEM (Windows) Registry file.\n"
	                 "\t        This option overrides the path provided by -r\n" );
	fprintf( stream, "\t-S:     filename of the SOFTWARE (Windows) Registry file.\n"
	                 "\t        This option overrides the path provided by -r\n" );
	fprintf( stream, "\t-t:     event log type, options: application, security, system\n"
	                 "\t        if not specified the event log type is determined based\n"
	                 "\t        on the filename.\n" );
	fprintf( stream, "\t-v:     verbose output to stderr\n" );
	fprintf( stream, "\t-V:     print version\n" );
}

/* Signal handler for evtexport
 */
//void evtexport_signal_handler(
//      libcsystem_signal_t signal LIBCSYSTEM_ATTRIBUTE_UNUSED )
//{
//	libcerror_error_t *error = NULL;
//	static char *function    = "evtexport_signal_handler";
//
//	LIBCSYSTEM_UNREFERENCED_PARAMETER( signal )
//
//	evtexport_abort = 1;
//
//	if( evtexport_export_handle != NULL )
//	{
//		if( export_handle_signal_abort(
//		     evtexport_export_handle,
//		     &error ) != 1 )
//		{
//			libcnotify_printf(
//			 "%s: unable to signal export handle to abort.\n",
//			 function );
//
//			libcnotify_print_error_backtrace(
//			 error );
//			libcerror_error_free(
//			 &error );
//		}
//	}
//	/* Force stdin to close otherwise any function reading it will remain blocked
//	 */
//	if( libcsystem_file_io_close(
//	     0 ) != 0 )
//	{
//		libcnotify_printf(
//		 "%s: unable to close stdin.\n",
//		 function );
//	}
//}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain( int argc, wchar_t * const argv[] )
#else
int main( int argc, char * const argv[] )
#endif
{
	libcerror_error_t *error                                        = NULL;
	libcstring_system_character_t *output_filename					= NULL;
	libcstring_system_character_t *source							= NULL;
	libcstring_system_integer_t option                              = 0;
	int result														= 0;
	int verbose                                                     = 0;
	FILE * outfile                                                  = NULL;

	// allocate options structure
	evtexport_options_t *pOptions =  memory_allocate_structure(evtexport_options_t);
	if( pOptions == NULL )
	{
		fprintf(
		 stderr,
		 "Failed to allocate memory for Options.\n" );

		goto on_error;
	}
	if( memory_set(
	     pOptions,
	     0,
	     sizeof( evtexport_options_t ) ) == NULL )
	{
		fprintf(
		 stderr,
		 "Failed to clear memory for Options.\n" );

		memory_free(
		 pOptions );

		goto on_error;
	}


	while( ( option = libcsystem_getopt(
	                   argc,
	                   argv,
					   _LIBCSTRING_SYSTEM_STRING( "c:hl:m:o:p:r:s:S:t:vV" ) ) ) != (libcstring_system_integer_t) -1 )
	{
		switch( option )
		{
			case (libcstring_system_integer_t) '?':
			default:
				fprintf(
				 stderr,
				 "Invalid argument: %" PRIs_LIBCSTRING_SYSTEM "\n",
				 argv[ optind - 1 ] );

				usage_fprint(
				 stdout );

				return( EXIT_FAILURE );

			case (libcstring_system_integer_t) 'c':
				pOptions->option_ascii_codepage = optarg;

				break;

			case (libcstring_system_integer_t) 'h':
				usage_fprint(
				 stdout );

				return( EXIT_SUCCESS );

			case (libcstring_system_integer_t) 'l':
				pOptions->option_log_filename = optarg;

				break;

			case (libcstring_system_integer_t) 'm':
				pOptions->option_export_mode = optarg;

				break;

			
			case (libcstring_system_integer_t) 'p':
				pOptions->option_resource_files_path = optarg;

				break;

			case (libcstring_system_integer_t) 'r':
				pOptions->option_registry_directory_name = optarg;

				break;

			case (libcstring_system_integer_t) 's':
				pOptions->option_system_registry_filename = optarg;

				break;

			case (libcstring_system_integer_t) 'S':
				pOptions->option_software_registry_filename = optarg;

				break;

			case (libcstring_system_integer_t) 't':
				pOptions->option_event_log_type = optarg;

				break;

			case (libcstring_system_integer_t) 'v':
				pOptions->option_verbose = 1;

				break;

			case (libcstring_system_integer_t) 'o':
				output_filename = optarg;

				break;

			
			case (libcstring_system_integer_t) 'V':
				evtoutput_copyright_fprint(
				 stdout );

				return( EXIT_SUCCESS );
		}
	}
	if( optind == argc )
	{
		fprintf(
		 stderr,
		 "Missing source file.\n" );

		usage_fprint(
		 stdout );

		return( EXIT_FAILURE );
	}
	source = argv[ optind ];


	// create/open outfile if one is specified
	if (NULL != output_filename) {

	 fprintf(
			stderr,
			"evtexportapp: output file name is : %" PRIs_LIBCSTRING_SYSTEM "\n", output_filename );

	#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		// fopen() cannot handle wide filenames
		outfile = _wfopen(output_filename, L"w+");
	#else
		outfile = fopen(output_filename, "w+");
	#endif

	if (NULL == outfile) {
		fprintf(
			stderr,
			"evtexportapp: failed to create output file: %s .\n", output_filename );
		goto on_error;
	}
	}
	else {	
	outfile = NULL;
	}

	// use the api to export the evt log
	result = evtexport(
		source,
		outfile,
		pOptions
	);

 if (NULL != output_filename) {
	 fclose(outfile);
 }

 if (0 != result) {
	 fprintf(
		 stderr,
		 "evtexport() failed.\n" );

		goto on_error;
 }
 return( EXIT_SUCCESS );

on_error:
	
		fprintf(
		 stderr,
		 "EvtExportApp failed to export the event log.\n" );
	return( EXIT_FAILURE );
}

