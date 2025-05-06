/* Add your code here */ 
#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "device/keyboard.h"
#include "machine/plugbox.h"
#include "guard/guardian.cc"

int main()

{
CGA_Stream kout;
Plugbox plug;
Keyboard_Controller keyCtr;
int a = -149;
unsigned long b = 100;
//kout << bin << a << endl;
//kout << "hihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihihiihihihihiihi" << endl;
//kout << " in hex: " << bin << a << endl;
//kout << "pointer:      " << reinterpret_cast<void*>(1994473406541717165ul) << " -> 0x1badcafefee1dead" << endl;

//kout << "Test          <stream result> -> <expected>" << endl;
//kout << "zero:         " << 0 << " -> 0" << endl;
//kout << "decimal:      " << dec << 42 << " -> 42" << endl;
//kout << "binary:       " << bin << 42 << dec << " -> 0b101010" << endl;
//kout << "octal:        " << oct << 42 << dec << " -> 052" << endl;
//kout << "hex:          " << hex << 42 << dec << " -> 0x2a" << endl;
//kout << "uint64_t max: " << ~((unsigned long)0) << " -> 18446744073709551615" << endl;
//kout << "int64_t max:  " << ~(1l<<63) << " -> 9223372036854775807" << endl;
//kout << "int64_t min:  " << (1l<<63) << " -> -9223372036854775808" << endl;
//kout << "some int64_t: " << (-1234567890123456789) << " -> -1234567890123456789" << endl;
//kout << "some int64_t: " << (1234567890123456789) << " -> 1234567890123456789" << endl;
//kout << "pointer:      " << reinterpret_cast<void*>(1994473406541717165ul) << " -> 0x1badcafefee1dead" << endl;
//kout << "smiley:       " << static_cast<char>(1) << endl;

/* Add your code here */
Gate *gate = &plug.report(9);
gate->trigger();
Keyboard keybrd;
while (true)
{
	keybrd.trigger();
} 



//Mian ist toll
//Nele sit auch okay :3
 
/* Add your code here */ 
 
/* Add your code here */ 
 
	return 0;
}



