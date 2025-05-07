/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* By using the PIC, hardware interrupts can be enabled or suppressed        */
/* individually. This way we can control whether interrupts of a specific    */
/* device are forwarded to the CPU at all. Even then, the interrupt handler  */
/* gets only activated if the CPU is ready to react to interrupts. This can  */
/* be controlled by using class CPU.                                         */
/*****************************************************************************/

/* Add your code here */ 
#include "machine/pic.h"
#include "device/cgastr.h"

PIC::PIC() {
	//ICW1
	outb(0x20, 0x11);
	outb(0xa0, 0x11);
	
	//ICW2
	outb(0x21, 0x20);
	outb(0xa1, 0x28);
	
	//ICW3
	outb(0x21, 0x04);
	outb(0xa1, 0x02);
	
	//ICW4
	outb(0x21, 0x03);
	outb(0xa1, 0x03);
	
	//OCW1 
	outb(0x21, 0xfb);
	outb(0xa1, 0xff);
}
	
void PIC::allow(int interrupt_device){
	

	if(interrupt_device == timer){
		if(inb(0x21) == 0xf9){
			outb(0x21, 0xf8);
		}
		else if(inb(0x21) == 0xfb){
			outb(0x21, 0xfa);
		}
	}
	else if(interrupt_device == keyboard){

		if(inb(0x21) == 0xfa){
			outb(0x21, 0xf8);
		}
		else if(inb(0x21) == 0xfb){
			outb(0x21, 0xf9);
			CGA_Stream kout;
    		kout << "After decleration";
		}
	}
}

void PIC::forbid(int interrupt_device){
	if(interrupt_device == timer){
		if(inb(0x21) == 0xf8){
			outb(0x21, 0xf9);
		}
		else if(inb(0x21) == 0xfa){
			outb(0x21, 0xfb);
		}
	}
	else if(interrupt_device == keyboard){
		if(inb(0x21) == 0xf9){
			outb(0x21, 0xfb);
		}
		else if(inb(0x21) == 0xf8){
			outb(0x21, 0xfa);
		}
	}
}

bool PIC::is_masked(int interrupt_device){
	if(interrupt_device == timer){
		if(inb(0x21) == 0xfb || inb(0x21) == 0xf9){
			return true;
		}
		else{
			return false;
		}
	}
	else if(interrupt_device == keyboard){
		if(inb(0x21) == 0xfb || inb(0x21) == 0xfa){
			return true;
		}
		else{
			return false;
		}
	}
	else if(interrupt_device == 2){
		return false;
	}
	else{
		return true;
	}
}
	
	
	
	
	
	
	
	
	
	
	
	


