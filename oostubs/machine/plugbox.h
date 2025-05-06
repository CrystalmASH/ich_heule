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

#ifndef __Plugbox_include__
#define __Plugbox_include__
#define timer = 32
#define keyboard = 33

#include "guard/gate.h"
#include "device/panic.h"

class Plugbox {
private:
	constexpr static unsigned int plugboxSize = 64;
	Gate *gates[plugboxSize];

public:
	static Panic panic;
	Plugbox(const Plugbox &copy) = delete; // prevent copying
	Plugbox& operator=(const Plugbox&) = delete; // prevent assignment
	Plugbox();
	void assign (unsigned int slot, Gate& gate);
	Gate& report (unsigned int slot);
};

#endif
