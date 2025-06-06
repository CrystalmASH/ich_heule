/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Handles timer interrupts by managing a time slice and triggering a        */
/* process switch if necessary.                                              */
/*****************************************************************************/

#include "device/watch.h"
#include "machine/pic.h"
#include "machine/plugbox.h"

/* Add your code here */ 

Watch::Watch(int us) : PIT(us){

}

void Watch::windup(){
    plug.assign(plug.timer, *this);
    pic.allow(pic.timer);
}

bool Watch::prologue(){
    
}

void Watch::epilogue(){

}

/* Add your code here */ 
 
/* Add your code here */ 
/* Add your code here */ 

