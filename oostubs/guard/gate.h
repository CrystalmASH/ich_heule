/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Class of objects that handle interrupts.                                  */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__

/* Add your code here */ 
class Gate

{
public: 
	Gate() = default;
	Gate(const Gate &copy) = delete; // prevent copying
	Gate& operator=(const Gate&) = delete; // prevent assignment
	virtual void trigger() = 0;
};

#endif
