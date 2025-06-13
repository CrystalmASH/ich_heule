/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

/* Add your code here */ 

#include "machine/pit.h"
#include "device/cgastr.h"

void PIT::interval(int us){
    us *= 1000;
    int counter = (us - (us % 838)) / (838);
    int lower_byte = counter % (2^8);
    int higher_byte = counter >> 8;
    outb(0x40, 0b00110100);
    //outb(0x40, 0b00101100);
    outb(0x40, lower_byte);
    outb(0x40, higher_byte);
}

int PIT::interval(){


    kout << "interval" << endl;
    outb(0x43,0b0000000);
    kout << (int) inb(0x40) << endl;
    kout << (int )inb(0x40) << endl;
}
