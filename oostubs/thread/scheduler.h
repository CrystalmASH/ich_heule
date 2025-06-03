/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "thread/dispatch.h"
#include "object/queue.h"
#include "thread/entrant.h"
/* Add your code here */ 

class Scheduler: public Dispatcher
/* Add your code here */ 
{
	private:
	Queue readyList;
	Entrant* current = nullptr;
public:
	Scheduler(const Scheduler &copy) = delete; // prevent copying
	Scheduler& operator=(const Scheduler&) = delete; // prevent assignment
	Scheduler() = default;
	void ready(Entrant& that);
	void schedule();
	void exit();
	void kill(Entrant& that);
	void resume();
/* Add your code here */ 
 
};

#endif
