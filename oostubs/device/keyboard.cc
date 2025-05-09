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
    CGA_Stream kout;
    kout << "keybpard e1" << endl;
    if (inb(0x64) & 0b1 == 1)
    {
        kout << "keybpard 1" << endl;
        Key pressed_key = Keyboard::key_hit();
 
         if(pressed_key.valid()){
            if( pressed_key.scancode() == Key::scan::del and pressed_key.alt() and pressed_key.ctrl()){
                reboot();
            };
            unsigned char character = pressed_key.ascii();
            kout << "keybpard 2" << endl;
            if (character != 0){
				    kout << "keybpard 3" << endl;
                pic->forbid(pic->keyboard);
                kout.setpos(20,20);
                kout << character;
                pic->allow(pic->keyboard);
            }
            //pressed_key = Keyboard::key_hit();
        } 
     
    }else{
        inb(0x60);
    }
}

void Keyboard::plugin(){
    plugbox->assign(33, *this);
    pic->allow(1);
    CGA_Stream kout;
    kout << "Plugged in" << endl;
}
