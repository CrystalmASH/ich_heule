/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

/* Add your code here */ 
#include "thread/scheduler.h"


void Scheduler::ready(Entrant& that)
{
	readyList.enqueue(&that);
	};

void Scheduler::schedule()
{
	Entrant *process = static_cast<Entrant*>(readyList.dequeue());
	if (process) {
		current = process;
		process->Entrant::go();
		}
	else {
		current = nullptr;
		}
	};

void Scheduler::exit()
{
	Entrant *process = static_cast<Entrant*>(readyList.dequeue());
	if (process) {
		current = process;
		process->Entrant::go();
		}
	else {
		current = nullptr;
		}
	};

void Scheduler::kill(Entrant& that)
{
	readyList.remove(&that);
	};

void Scheduler::resume()
{
	//maybe this has to add the old process again
	readyList.enqueue(current);
	Entrant* oldProcess;
	Entrant* newProcess = static_cast<Entrant*>(readyList.dequeue());
	current = newProcess;
	oldProcess->Entrant::resume(newProcess);
};
/* Add your code here */ 
/* Add your code here */ 
