#ifndef __screen_include__
#define __screen_include__

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

#include "machine/io_port.h"

class CGA_Screen {
private:
	int CGA_START = (int) 0xb8000;
/* Add your code here */ 

public:
	CGA_Screen(const CGA_Screen &copy) = delete; // prevent copying
	CGA_Screen& operator=(const CGA_Screen&) = delete; // prevent assignment
	CGA_Screen();
	
	//	This method displays the character c at the position (x,y) with 
	//		the specified color attribute attrib. Here x specifies the 
	//		column and y the row of the desired position, where: 0<=x<=79 
	//		and 0<=y<=24. The position (0,0) designates the upper left corner 
	//		of the screen. attrib can be used to specify features such as 
	//		background color, foreground color and blinking.
	void show(int x, int y, char c, unsigned char attrib);
	
	//	This method sets the cursor to the specified position.
	void setpos(int x, int y);
	
	//	This can be used to get the current position of the cursor from 
	//		the graphics card. x and y are references and serve as output parameters.
	void getpos(int& x, int& y);
	
	//	This method can be used to output a string text, starting at the current 
	//		position of the cursor. Since the string does not need to contain 
	//		a zero terminator, as is usually the case with C, the length parameter 
	//		is required, which must specify of how many characters text consists. 
	//		After the output is finished, the cursor should be placed behind the 
	//		last printed character. The whole text should be displayed uniformly 
	//		with the colors chosen by attrib.
	//		If there is not enough space left until the end of the line, the output 
	//		should be continued on the following line. As soon as the last screen 
	//		line is filled, the entire screen area should be moved up by one line. 
	//		This makes the first line disappear. Now, the last line can be deleted 
	//		and the output can be continued there.
	void print(char* text, int length, unsigned char atrrib);


};

#endif
