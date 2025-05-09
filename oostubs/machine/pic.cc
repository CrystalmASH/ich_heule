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
}
	
void PIC::allow(int interrupt_device){
	/*if(interrupt_device == timer){
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
		}
	}*/
	if(interrupt_device > 15) return;
	if(!PIC::is_masked(interrupt_device)) return;

	bool slave = false;
	if(interrupt_device > 7){
		slave = true;
		interrupt_device = interrupt_device % 8;
	}

	int bin_interrupt_device = 0b00000001 << interrupt_device;
	bin_interrupt_device = bin_interrupt_device ^ 0xFF;

	if(!slave){
		int port = inb(0x21);
		int new_bin = port & bin_interrupt_device;
		outb(0x21, new_bin);
	}
	else{
		int port = inb(0xa1);
		int new_bin = port & bin_interrupt_device;
		outb(0xa1, new_bin);
	}
	
}

void PIC::forbid(int interrupt_device){
	/*if(interrupt_device == timer){
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
	}*/
	if(interrupt_device > 15) return;
	if(PIC::is_masked(interrupt_device)) return;

	bool slave = false;
	if(interrupt_device > 7){
		slave = true;
		interrupt_device = interrupt_device % 8;
	}

	int bin_interrupt_device = 0b00000001 << interrupt_device;

	if(!slave){
		int port = inb(0x21);
		int new_bin = port | bin_interrupt_device;
		outb(0x21, new_bin);
	}
	else{
		int port = inb(0xa1);
		int new_bin = port | bin_interrupt_device;
		outb(0xa1, new_bin);
	}
}

bool PIC::is_masked(int interrupt_device){
	/*if(interrupt_device == timer){
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
	}*/
	if(interrupt_device > 15) return false;

	bool slave = false;
	if(interrupt_device > 7){
		slave = true;
		interrupt_device = interrupt_device % 8;
	}

	int bin_interrupt_device = 0b00000001 << interrupt_device;

	if(!slave){
		int port = inb(0x21);
		int new_bin = port & bin_interrupt_device;
		outb(0x21, port);
		if(new_bin == bin_interrupt_device) return true;
		else return false;
	}
	else{
		int port = inb(0xa1);
		int new_bin = port & bin_interrupt_device;
		outb(0xa1, port);
		if(new_bin == bin_interrupt_device) return true;
		else return false;
	}
}
	
	
	
	
	
	
	
	
	
	
	
	


