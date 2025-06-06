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
Keyboard::Keyboard(){

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

                pic.forbid(pic.keyboard);
                kout.setpos(1,1);
                kout << character;
                pic.allow(pic.keyboard);
            }
            //pressed_key = Keyboard::key_hit();
        } 
     
    }
}

bool Keyboard::prologue(){
    if(inb(0x64) & 0b1 == 1){
        code = inb(port_int::data_port);
        //kout << "Prologue " << endl;
        //Gate::queued(true);
        return true;
    }else{
        //kout << "Prologue 2" << endl;
        return false;
    }
}

void Keyboard::epilogue(){
    //kout << "epilogue" << endl;
    Key pressed_key = Keyboard_Controller::key_hit();

    if( pressed_key.scancode() == Key::scan::del and pressed_key.alt() and pressed_key.ctrl()){
            kout << "reboot" << endl;
            reboot();
    };
    if(pressed_key.valid()){
        //kout << "epilogue 2" << endl;
        unsigned char character = pressed_key.ascii();
        if (character != 0){

            pic.forbid(pic.keyboard);
            //kout.setpos(1,1);
            kout << character;
            pic.allow(pic.keyboard);
        }
        //pressed_key = Keyboard::key_hit();
    } 
    //Gate:queued(false);
    return;
}

void Keyboard::plugin(){
    plug.assign(plug.keyboard, *this);
    pic.allow(pic.keyboard);
}
