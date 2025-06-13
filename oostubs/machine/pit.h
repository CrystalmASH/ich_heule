/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#include "machine/io_port.h"
#ifndef __pit_include__
#define __pit_include__

class PIT {
public:
	PIT(const PIT &copy) = delete; // prevent copying
	PIT& operator=(const PIT&) = delete; // prevent assignment
/* Add your code here */ 
public:
	PIT(int us) {
		interval (us);
	}
	int interval();
	void interval(int us);
};

#endif
