/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/
/* Add your code here */ 
/* Add your code here */ 
 
#include "device/panic.h"
#include "device/cgastr.h"
	
	CGA_Stream panicOutput;
	
	extern "C" void cpu_halt();
	

	Panic::Panic() {};
	
	void Panic::trigger() 
	{
		// TODO: print error message
		panicOutput << endl << "unknown exception occured. stopping CPU..." << endl;
		cpu_halt();
	};
	
	
	
	
