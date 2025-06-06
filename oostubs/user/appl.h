/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/


#include "thread/coroutine.h"

#ifndef __application_include__
#define __application_include__

/*
class Application
 
{

public:
	Application (const Application &copy) = delete; // prevent copying
	Application& operator=(const Application&) = delete; // prevent assignment
/* Add your code here */ 
	//Application();
	//void action ();
//};

class Application : public Coroutine {
public:
    Application(void* tos, char* name, Coroutine* next)
        : Coroutine(tos), name(name), next(next)/*, /*caller(nullptr)*/ {}

    void action() override;

	//Coroutine* caller;

private:
    char* name;
    Coroutine* next;
      // 👈 neu
};

#endif
