/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstracts an interrupt vector table. Allows to configure handler routines */
/* for every hardware and software interrupt and every CPU exception.        */
/*****************************************************************************/

/* Add your code here */ 

#include "machine/plugbox.h"
#include "device/cgastr.h"

Panic Plugbox::panic;

Plugbox::Plugbox() 
{
	unsigned int i = 0;
	while (i < plugboxSize) 
	{
		gates[i] = &Plugbox::panic;
		i++;
	}
}

void Plugbox::assign (unsigned int slot, Gate& gate)
{
	gates[slot] = &gate;
};
	
Gate& Plugbox::report (unsigned int slot)
{
	return *(gates[slot]);
};

Plugbox plug;
