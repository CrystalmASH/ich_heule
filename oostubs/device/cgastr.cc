/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C G A _ S T R E A M                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The CGA_Stream class allows to print different data types as text strings */
/* to a PC's CGA screen.                                                     */
/* For attributes/colors and cursor positioning use the methods of class     */
/* CGA_Screen.                                                               */
/*****************************************************************************/

#include "device/cgastr.h"

	CGA_Stream::CGA_Stream() {};

	void CGA_Stream::flush()
	{
		int x = 0;
		int y = 0;
		CGA_Stream::print(buf, index, 0b00001111);
		index = 0;
	}
/* Add your code here */ 
