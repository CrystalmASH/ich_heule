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
		number = O_Stream::convert_number_system(number);
		O_Stream::numbertostr((long)number);
		O_Stream::operator<<(buffer);
		return *this;
	};
	O_Stream& O_Stream::operator<< (short number)
	{
		number = O_Stream::convert_number_system(number);
		O_Stream::numbertostr((long)number);
		O_Stream::operator<<(buffer);
		return *this;
	};
	O_Stream& O_Stream::operator<< (unsigned int number)
	{
		number = O_Stream::convert_number_system(number);
		O_Stream::numbertostr((long)number);
		O_Stream::operator<<(buffer);
		return *this;
	};
	O_Stream& O_Stream::operator<< (int number)
	{
		number = O_Stream::convert_number_system(number);
		O_Stream::numbertostr((long)number);
		O_Stream::operator<<(buffer);
		return *this;
	};

	O_Stream& O_Stream::operator<< (unsigned long number)
	{
		number = O_Stream::convert_number_system(number);
		O_Stream::numbertostr(number);
		O_Stream::operator<<(buffer);
		return *this;
	};
	O_Stream& O_Stream::operator<< (long number)
	{
		number = O_Stream::convert_number_system(number);
		O_Stream::numbertostr(number);
		O_Stream::operator<<(buffer);
		return *this;
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
	
	long O_Stream::convert_number_system(long number) 
	{
		switch (number_system) {
			case 2:
				{
					int exp = 0;
					long temp = 0;
					long result = 0;
					while (number!=0) 
					{
						temp = number%2;
						number = (number-temp)/2;
						long pow = O_Stream::power(10, exp);
						result = temp * O_Stream::power(10, exp);
						exp++;						
					}
					return result;
				};
			case 8:
				{
					int exp = 0;
					long temp = 0;
					long result = 0;
					while (number!=0) 
					{
						temp = number%8;
						number = (number-temp)/8;
						long pow = O_Stream::power(10, exp);
						result = temp * O_Stream::power(10, exp);
						exp++;						
					}
					return result;
				};
			case 10:
				return number;	
			case 16:
				return 0;
		}
	}
	
	long O_Stream::power(int base, int exp) {
		int result = 1;
		for (int i = 0; i < exp; i++) 
		{
			result *= base;
		}
		return result;
	}
	
	void O_Stream::numbertostr(long number) 
	{
		int i = 1;
		bool isNegative = false;
		buffer[0] = '\0';
		if (number == 0) 
		{
			buffer[i] = 48;
			i++;
		}
		if (number < 0) 
		{ 
			isNegative = true;
			number = -number;
		}
		while(number > 0)
		{
			buffer[i] = (number%10) +48;
			number /= 10;
			i++;
		}
		if (isNegative) 
		{
			buffer[i] = '-';
			i++;
		}
		int start = 0;
		int end = i - 1;
		while (start < end) 
		{
			char tmp = buffer[start];
			buffer[start] = buffer[end];
			buffer[end] = tmp;
			start++;
			end--;
		}
	}
	
void O_Stream::numbertostr(unsigned long number) 
	{
		int i = 1;
		buffer[0] = '\0';
		if (number == 0) 
		{
			buffer[i] = 48;
			i++;
		}
		while(number > 0)
		{
			buffer[i] = (number%10) +48;
			number /= 10;
			i++;
		}
		int start = 0;
		int end = i - 1;
		while (start < end) 
		{
			char tmp = buffer[start];
			buffer[start] = buffer[end];
			buffer[end] = tmp;
			start++;
			end--;
		}
	}
	
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

