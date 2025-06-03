/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            E N T R A N T                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* A coroutine that is managed by the Scheduler.                             */
/*****************************************************************************/

#ifndef __entrant_include__
#define __entrant_include__

/* Add your code here */
#include "object/chain.h"
#include "thread/coroutine.h"

class Entrant: public Chain, Coroutine
/* Add your code here */ 
{
public:
	Entrant(const Entrant &copy) = delete; // prevent copying
	Entrant& operator=(const Entrant&) = delete; // prevent assignment
	//Entrant(void* tos) {Coroutine(tos);};

/* Add your code here */ 
};

#endif
