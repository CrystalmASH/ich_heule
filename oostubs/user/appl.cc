/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "device/keyboard.h"
#include "machine/plugbox.h"
#include "machine/cpu.h"
/* Add your code here */ 
 
/* GLOBAL VARIABLES */

/* Add your code here */

CPU cpu;

Application::Application(){}
 
void Application::action(){
    CGA_Stream kout;
    PIC pic;
    cpu.enable_int();

    //Gate *gate = &plug.report(9);
//gate->trigger();

    Keyboard keybrd(&pic, &plug);
    keybrd.plugin();
    cpu.idle();



//Mian ist toll
//Nele sit auch okay :3
 
/* Add your code here */ 
 
/* Add your code here */ 
/* Add your code here */
}
