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
#include "thread/dispatch.h"
/* Add your code here */ 
 
/* GLOBAL VARIABLES */

/* Add your code here */

CPU cpu;
/*
Application::Application(){}
 
void Application::action(){
    CGA_Stream kout;
    cpu.enable_int();

    //Gate *gate = &plug.report(9);
//gate->trigger();

    Keyboard keybrd();
    keybrd.plugin();
    cpu.idle();



//Mian ist toll
//Nele sit auch okay :3
 
/* Add your code here */ 
 
/* Add your code here */ 
/* Add your code here */
//}
void Application::action() {
    CGA_Stream kout;

    for (int i = 0; i < 3; ++i) {
        kout << name << " step " << i << "\n";
    }

    if (next) {
        kout << name << " switching to " << ((Application*)next)->name << "\n";
        //static_cast<Application*>(next)->caller = this;       // 👈 Wer ruft als nächstes?
        dispatcher.dispatch(*next);
    }

    kout << name << " finished\n";

    //if (caller) {
        //resume(*caller);  // 👈 Zurück zum Aufrufer
    //}
}
