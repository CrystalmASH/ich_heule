/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The O_Stream class defines the << operator for several pre-defined data   */
/* types and thereby realizes output functionality similar to C++'s iostream */
/* library. By default, this class supports printing characters, strings and */
/* integer numbers of various bit sizes. Another << operator allows to use   */
/* so-called 'manipulators'.                                                 */
/*                                                                           */
/* Besides class O_Stream this file also defines the manipulators hex, dec,  */
/* oct and bin for choosing the basis in number representations, and endl    */
/* for implementing an (implicitly flushing) line termination.               */
/*****************************************************************************/

#include "object/o_stream.h"

/* Add your code here */ 
	O_Stream::O_Stream() {};
	O_Stream& O_Stream::operator<< (unsigned char c)
	{
		O_Stream::put(c);
		return *this;
	};
	O_Stream& O_Stream::operator<< (char c)
	{
		O_Stream::put(c);
		return *this;
	};
	O_Stream& O_Stream::operator<< (unsigned short number)
	{
		
	};
	O_Stream& O_Stream::operator<< (short number)
	{
		
	};
	O_Stream& O_Stream::operator<< (unsigned int number)
	{
		
	};
	O_Stream& O_Stream::operator<< (int c)
	{
		
	};
	O_Stream& O_Stream::operator<< (unsigned long number)
	{
		
	};
	O_Stream& O_Stream::operator<< (long number)
	{
		
	};
	O_Stream& O_Stream::operator<< (void* pointer)
	{
		
	};
	O_Stream& O_Stream::operator<< (char* text)
	{
		
		for (int i = 0; text[i]!='\0'; i++) 
		{
			O_Stream::put(text[i]);
		}
		return *this;
	};
	O_Stream& O_Stream::operator<< (O_Stream& (*fkt) (O_Stream&))
	{
		return fkt(*this);
	};
	
	// ENDL: inserts a newline in the output and flushes the buffer
/* Add your code here */ 

O_Stream& endl (O_Stream& os)
{
	os.put('\n');
	os.flush();
	return os;
	};

// BIN: selects the binary number system
/* Add your code here */ 

O_Stream& bin (O_Stream& os)
{
	os.number_system = 2;
	return os;
	};

// OCT: selects the octal number system
/* Add your code here */ 

O_Stream& oct (O_Stream& os)
{
	os.number_system = 8;
	return os;
	};

// DEC: selects the decimal number system
/* Add your code here */ 

O_Stream& dec (O_Stream& os)
{
	os.number_system = 10;
	return os;
	};

// HEX: selects the hexadecimal number system
/* Add your code here */ 

O_Stream& hex (O_Stream& os)
{
	os.number_system = 16;
	return os;
	};

