/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/

#ifndef __panic_include__
#define __panic_include__

/* INCLUDES */

#include "guard/gate.h"


class Panic: public Gate
/* Add your code here */ 
{
public:
	Panic (const Panic &copy) = delete; // prevent copying
	Panic& operator=(const Panic&) = delete; // prevent assignment
	Panic ();
	bool prologue() override;
/* Add your code here */ 
 
};

#endif
