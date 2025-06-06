/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          C O R O U T I N E                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Represents the abstraction of a coroutine.                                */
/* In the constructor, we set up the initial context of the coroutine. go()  */
/* activates the first coroutine. All further coroutine switches should be   */
/* initiated by resume().                                                    */
/* To be able to save the context at a couroutine switch, every Coroutine    */
/* object contains a struct toc that stores the values of all non-volatile   */
/* registers.                                                                */
/*****************************************************************************/

#ifndef __Coroutine_include__
#define __Coroutine_include__

#include "machine/toc.h"

class Coroutine {
public:
	Coroutine(const Coroutine &copy) = delete; // prevent copying
	Coroutine& operator=(const Coroutine&) = delete; // prevent assignment
/* Add your code here */ 
	Coroutine (void* tos);
	void go();
	void resume (Coroutine& next);
	virtual void action () = 0;
protected:
	struct toc regs;
};

#endif
