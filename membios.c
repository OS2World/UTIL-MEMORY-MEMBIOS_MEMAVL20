/****************************************************************************

	MemBios.C - Module to display BIOS extended memory available

	This module queries and reports the number of bytes of Extended
	memory that the BIOS INT 15, Function 88 reports.

	Note that this program should be run only when no memory
	manager is present.  It should also not be run in an OS/2 VDM.

	history
	04-28-92 ras - CR P920026, initial entry

****************************************************************************/
#include <dos.h>			// DOS general defines
#include <stdlib.h>			// standard functions
#include <stdio.h>			// standard i/o

// start function
int	main( )
	
  {	// define automatics
	union	REGS	Regs;			// intdos regs

	// ask BIOS for extended memory count
	// using INT 15, function 88
	// which returns kb available in ax
	Regs.x.ax = 0x8800;
	int86( 0x15, &Regs, &Regs );

	// display result
	if ( Regs.x.ax == 0 )
	{   // none available, warn
	    printf( "\nNo extended memory available, remove any" );
	    printf( "\nDOS Memory Managers and try again." );
	}
	else
	{   // got some memory reported, display it
	    printf( "\nINT 15, function 88 reports Extended Memory: %ld", 
		    (unsigned long) Regs.x.ax * 1024 );
	}

	// exit to caller
	return( 0 );
  }
