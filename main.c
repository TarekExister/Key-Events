#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>

//function declaration
void key_up_event(short int key);
void key_down_event(short int key);

int main(int argc, char **argv)
{

	while (true) 
	{
		key_up_event(VK_F1);
		key_down_event(VK_F2);
		Sleep(50);
	}

	return 0;
}

//function difinition
void key_up_event(short int key) 
{

	if (GetAsyncKeyState(key)) 
	{
		while (GetAsyncKeyState(key) != 0);
		
		//some codes
		printf("F1 is pressed\n");
	}
}

void key_down_event(short int key) 
{
	//key press timer per milliseconds:
	for (clock_t c = clock(); GetAsyncKeyState(key);) 
	{
		printf("\r%.3f ms", ((float)clock() - c) / CLOCKS_PER_SEC);
	}

	//simple code:
	//while(getasynckeystate(key))
	//{
	//}
}