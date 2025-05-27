/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Using this class, we can synchronize activities with a critical section   */
/* with interrupt handlers that also access this critical section. This      */
/* synchronization takes place along the prologue/epilogue model.            */
/*****************************************************************************/
#include "guard/locker.h"
#include "guard/gate.h"
#include "object/queue.h"
#include "machine/cpu.h"
#include "object/chain.h"


#ifndef __Guard_include__
#define __Guard_include__

/* Add your code here */ 

class Guard : public Locker {
public:
	Guard (const Guard &copy) = delete; // prevent copying
	Guard& operator=(const Guard&) = delete; // prevent assignment
	Guard ();
/* Add your code here */ 
	Queue epilogues;
	Locker locker;
	int number;
	Chain *chain;
	Gate* gate;
	void leave();
	void relay(Gate* item);
};

extern Guard guard;
#endif
