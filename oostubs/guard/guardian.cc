/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The system's central interrupt handling routine.                          */
/* The parameter specifies the number of the interrupt that occurred.        */
/*****************************************************************************/

/* INCLUDES */
#include "guard/gate.h"
#include "machine/plugbox.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "guard/guard.h"



/* FUNCTIONS */

extern "C" void guardian (unsigned int slot);

/* GUARDIAN: Low-level interrupt handling. We will extend this function at */
/*           a later point in time.                                        */

void guardian (unsigned int slot)
{
	//kout<<"interrupt"<<endl;
	Gate* gate;
	gate = &plug.report(slot);
	bool epilogueRequested = gate->prologue();
	if (epilogueRequested) 
	{
		//kout<<"epilogue bitte"<<endl;
		guard.relay(gate);
	}
	cpu_idle();
}
