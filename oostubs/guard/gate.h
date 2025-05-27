/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Class of objects that handle interrupts.                                  */
/*****************************************************************************/


#include "object/chain.h"

#ifndef __Gate_include__
#define __Gate_include__

/* Add your code here */ 
class Gate : public Chain{
private:
	bool queueFlag = false;
public: 
	Gate() = default;
	Gate(const Gate &copy) = delete; // prevent copying
	Gate& operator=(const Gate&) = delete; // prevent assignment
	virtual bool prologue() = 0;
	virtual bool epilogue() {};
	void queued(bool q) {queueFlag = q;};
	bool queued() {return queueFlag;};
};

#endif
