/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/
#include "device/keyboard.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
/* Add your code here */ 
Keyboard::Keyboard(	PIC* pi, Plugbox* plug){
    pic = pi;
    plugbox = plug;
}
/* Add your code here */ 
void Keyboard::trigger(){
    if (inb(0x64) & 0b1 == 1)
    {
        Key pressed_key = Keyboard::key_hit();
 
         if(pressed_key.valid()){
            if( pressed_key.scancode() == Key::scan::del and pressed_key.alt() and pressed_key.ctrl()){
                reboot();
            };
            unsigned char character = pressed_key.ascii();
            if (character != 0){

                pic->forbid(pic->keyboard);
                kout.setpos(1,1);
                kout << character;
                pic->allow(pic->keyboard);
            }
            //pressed_key = Keyboard::key_hit();
        } 
     
    }
}

void Keyboard::plugin(){
    plugbox->assign(33, *this);
    pic->allow(1);
}
