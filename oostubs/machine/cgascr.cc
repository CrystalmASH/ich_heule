/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* This class allows accessing the PC's screen.  Accesses work directly on   */
/* the hardware level, i.e. via the video memory and the graphic adapter's   */
/* I/O ports.                                                                */
/*****************************************************************************/

#include "machine/cgascr.h"

/* Add your code here */ 
	CGA_Screen::CGA_Screen() {;
	}
	void CGA_Screen::show(int x, int y, char c, unsigned char attrib)
	{
		if ((0<=x) and (x<=79) and (0<=y) and (y<=24))
		{
			char *pos1;
			pos1 = (char*)CGA_START + y*160 + x*2;
			*pos1 = c;
			*(pos1+1) = attrib;
			}
		}
	
	void CGA_Screen::setpos(int x, int y)
	{
		int position = x + y*80;
		
		outb(0x3d4, 15);
		outb(0x3d5, position & 0xff);
		outb(0x3d4, 14);
		outb(0x3d5, (position >> 8) & 0xff);
		}
		
	void CGA_Screen::getpos(int& x, int& y)
	{
		outb(0x3d4, 14);
		int pos = inb(0x3d5);
		outb(0x3d4, 15);
		pos = pos << 8;
		pos = pos + inb(0x3d5);
		x = pos % 80;
		pos = pos - x;
		y = pos/80;
		}
	
	void CGA_Screen::print(char* text, int length, unsigned char attrib)
	{
		int x;
		int y;
		for (int i = 0; i < length; i++) 
		{
			CGA_Screen::getpos(x, y);
			CGA_Screen::show(x, y, text[i], attrib);
			if (x+1 > 79) {
				CGA_Screen::setpos(0, y+1);
			}
			else {
				CGA_Screen::setpos(x+1, y);
			}
			
		}

	}
