/****************************************************************************

	MemAvl20.C - Module to display several OS/2 2.0 Memory Statistics

	This module queries and reports the following OS/2 values:

	QSV_TOTPHYSMEM		total bytes of physical memory
	QSV_TOTRESMEM		total bytes occupied by resident pages
	QSV_TOTAVAILMEM		total bytes of virtual memory available

	Note that the 6.304 Toolkit On-line docs show these values as
	being reported in pages.  It appears they are really byte
	values (or else my PC is hiding a lot of memory<g>).

	history
	04-28-92 ras - CR P920026, initial entry

****************************************************************************/
#define INCL_DOS
#include <os2.h>			// OS/2 definitions
#ifdef NULL				// Watcom definition different
 #undef NULL				// so clear OS/2 version
#endif
#include <stdlib.h>			// standard functions
#include <stdio.h>			// standard i/o

// start function
int	main( )
	
  {	// define automatics
	ULONG		qStatus;		// OS/2 status
  	ULONG		qValue[3];		// query values

	// ask OS/2 for physical memory count
	qStatus = DosQuerySysInfo( QSV_TOTPHYSMEM,
				   QSV_TOTAVAILMEM,
				   &qValue[0],
				   sizeof(qValue) );

	// check error
	if ( qStatus != 0 )
	{   // failed, report
	    printf( "\nDosQuerySysInfo failed, status of %ld", qStatus );
	    exit( qStatus );
	}

	// display result
	printf( "\nDosQuerySysInfo reports Physical memory: %ld", 
		qValue[0] );
	printf( "\n                        Resident memory: %ld", 
		qValue[1] );
	printf( "\n                           Avail memory: %ld", 
		qValue[2] );

	// exit to caller
	return( 0 );
  }
