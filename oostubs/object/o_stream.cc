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
		O_Stream::numbertostr((long)number);
		O_Stream::operator<<(buffer);
		return *this;
	};
	O_Stream& O_Stream::operator<< (short number)
	{
		O_Stream::numbertostr((long)number);
		O_Stream::operator<<(buffer);
		return *this;
	};
	O_Stream& O_Stream::operator<< (unsigned int number)
	{
		O_Stream::numbertostr((long)number);
		O_Stream::operator<<(buffer);
		return *this;
	};
	O_Stream& O_Stream::operator<< (int number)
	{
		O_Stream::numbertostr((long)number);
		O_Stream::operator<<(buffer);
		return *this;
	};

	O_Stream& O_Stream::operator<< (unsigned long number)
	{
		O_Stream::numbertostr(number);
		O_Stream::operator<<(buffer);
		return *this;
	};
	O_Stream& O_Stream::operator<< (long number)
	{
		O_Stream::numbertostr((long)number);
		O_Stream::operator<<(buffer);
		return *this;
	};
	O_Stream& O_Stream::operator<< (void* pointer)
	{
		unsigned long addr = (unsigned long)pointer;
		int tmp = number_system;
		number_system = 16;
		O_Stream::numbertostr(addr);
		O_Stream::operator<<(buffer);
		number_system = tmp;
		return *this;
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
	
	
	void O_Stream::numbertostr(long number) 
	{
		switch (number_system) {
			case 2:
			{
				int i = 1;
				bool isNegative = false;
				bool complement = false;
				unsigned long temp;
				buffer[0] = '\0';
				if (number == 0) 
				{
					buffer[i] = 48;
					i++;
				}
				if (number<0) 
				{
					isNegative = true;
					temp = -number;
				}
				else
				{
					temp = number;
				}
				while(temp > 0)
				{
					unsigned long x = (temp%2);
					if (isNegative)
					{
						x = (x+1)%2;
						if (!complement)
						{
							if (x == 1)
							{
								x = 0;
							}
							else
							{
								x = 1;
								complement = true;
							}
						
						}
						buffer[i] = x+48;
						
					}
					else
					{
						buffer[i] = x+48;
					}
					temp /= 2;
					i++;
				}
				while (i<33) {
					if (isNegative) 
					{
						
						buffer[i] = 49;
						i++;
					}
					else
					{
						buffer[i] = 48;
						i++;
					}
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
				break;
			}
			case 8:
			{
				int i = 1;
				buffer[0] = '\0';
				unsigned long temp;
				bool isNegative = false;
				bool complement = false;
				if (number == 0) 
				{
					buffer[i] = 48;
					i++;
				}
				if (number<0) 
				{
					isNegative = true;
					temp = -number;
				}
				else
				{
					temp = number;
				}
				while(temp > 0)
				{
					unsigned long x = (temp%8);
					if (isNegative)
					{
						x = 7-x;
						if (!complement)
						{
							if (x == 7)
							{
								x = 0;
							}
							else
							{
								x += 1;
								complement = true;
							}
						
						}
						buffer[i] = x+48;
						
					}
					else
					{
						buffer[i] = x+48;
					}
					temp /= 8;
					i++;
				}
				while(i<12)
				{
					if (isNegative) 
					{
						if (i == 11) 
						{
							buffer[i] = 51;
						}
						else
						{
							buffer[i] = 55;
						}
						i++;
					}
					else
					{
						buffer[i] = 48;
						i++;
					}
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
				break;
			}
			case 10:
			{
				int i = 1;
				unsigned long temp;
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
					temp = -number;
				}
				else
				{
					temp = number;
				}
				while(temp > 0)
				{
					buffer[i] = (temp%10) +48;
					temp /= 10;
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
				break;
			}
			case 16:
			{
				int i = 1;
				buffer[0] = '\0';
				bool isNegative = false;
				bool complement = false;
				unsigned long temp;
				unsigned long x;
				if (number == 0)
				{
					buffer[i] = 48;
					i++;
				}
				if (number<0) 
				{
					isNegative = true;
					temp = -number;
				}
				else
				{
					temp = number;
				}
				while (temp > 0)
				{
					x = temp%16;
					if (isNegative)
					{
						x = 15-x;
						if (!complement)
						{
							if (x == 15)
							{ 
								x = 0;
							}
							else
							{ 
								x+=1;
								complement = true;
							}
						}
					}
					switch (x){
						case 10:
							buffer[i] = 'A';
							break;
						case 11:
							buffer[i] = 'B';
							break;
						case 12:
							buffer[i] = 'C';
							break;
						case 13:
							buffer[i] = 'D';
							break;
						case 14:
							buffer[i] = 'E';
							break;
						case 15:
							buffer[i] = 'F';
							break;
						default:
							buffer[i] = x+48;
							break;
					}
					temp /= 16;
					i++;
					int start = 0;
					int end = i - 1;
					
				}
				while(i<9)
				{
					if (isNegative) 
					{
						buffer[i] = 70;
						i++;
					}
					else
					{
						buffer[i] = 48;
						i++;
					}
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
				break;
			}
		}
	}
	
void O_Stream::numbertostr(unsigned long number) 
	{
		switch (number_system) {
			case 2:
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
					long x = (number%2);
					buffer[i] = x+48;
					number /= 2;
					i++;
				}
				O_Stream::put(i);
				while (i<33) {
						buffer[i] = 48;
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
				break;
			}
			case 8:
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
					long x = (number%8);
					buffer[i] = x+48;
					number /= 8;
					i++;
				}
				while(i<11)
				{
					buffer[i] = 48;
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
				break;
			}
			case 10:
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
				break;
			}
			case 16:
			{
				int i = 1;
				buffer[0] = '\0';
				int x;
				if (number == 0)
				{
					buffer[i] = 48;
					i++;
				}
				
				while (number > 0)
				{
					x = number%16;
					switch (x){
						case 10:
							buffer[i] = 'A';
							break;
						case 11:
							buffer[i] = 'B';
							break;
						case 12:
							buffer[i] = 'C';
							break;
						case 13:
							buffer[i] = 'D';
							break;
						case 14:
							buffer[i] = 'E';
							break;
						case 15:
							buffer[i] = 'F';
							break;
						default:
							buffer[i] = x+48;
							break;
					}
					number /= 16;
					i++;
					int start = 0;
					int end = i - 1;
					
				}
				while(i<9)
				{
					buffer[i] = 48;
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
				break;
			}
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

