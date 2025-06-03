/* Add your code here */ 

#include "user/appl.h"
#include "machine/cpu.h"


/*
int main()

{
	Application appl;
	appl.action();

	
	return 0;
}

*/


int main()

{
	//Application appl;
	//appl.action();

	unsigned char stack1[4096];
	unsigned char stack2[4096];
	unsigned char stack3[4096];

	Application app3(stack3 + sizeof(stack3), "App3", nullptr);
	Application app2(stack2 + sizeof(stack2), "App2", &app3);
	Application app1(stack1 + sizeof(stack1), "App1", &app2);

	// Erste Coroutine starten (das ersetzt main-Schleife)
	app1.go();

	
	return 0;
}



