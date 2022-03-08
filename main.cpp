/* for compile:
windres.exe -i main.rc --input-format=rc -o mainRC.res -O coff
g++ main.cpp -o SnakeGame.exe mainRC.res
*/
#include "func_gotoxy.h"
#include <iostream>
#include <conio.h>
using namespace std;

#include "snake.h"
snake::snake Snake;
#include "apple.h"

void GameOver(){
	gotoxy(24,12);cout<<" _____________ \n";
	gotoxy(24,13);cout<<"| !Game Over! |\n";
	gotoxy(24,14);cout<<" ------------- \n";
	
	gotoxy(31,13);
	while(1);
}

int main(/*no argc and argv*/){
	system("color ac");
	system("title Snake Game");
	Snake.newPiseof(9,10);
	Snake.newPiseof(8,10);
	apple::newApple();
	while(1){// Loop Main
		Snake.getDirection();
		Snake.moveSnake();
		gotoxy(0,0);
		apple::eatApple();
		//// Game Over?
			if(apple::srcSnake(Snake.head.x,Snake.head.y) == 2){
				GameOver();
			}
		//// Exit to Game?
		if(kbhit())
			if(getch()==59)
				exit(0);
		Sleep(99);
	}
}