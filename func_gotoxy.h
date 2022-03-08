#ifndef _FUNC_GOTOXY_
#define _FUNC_GOTOXY_
#include <windows.h>
void gotoxy(int x, int y){
	COORD coord = {0,0};
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
#endif//_FUNC_GOTOXY_