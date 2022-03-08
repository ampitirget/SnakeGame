#ifndef _APPLE_HEDAR_SNAKEGAME_
#define _APPLE_HEDAR_SNAKEGAME_

#include <stdlib.h>

namespace apple{
	int x,y;
	
	int srcSnake(int xSrc,int ySrc){
		for(int i=0;i<Snake.sizeSnake;i++) if(Snake.body[i].x==xSrc and Snake.body[i].y==ySrc){ return 2; break; }// src body
		if(Snake.head.x==xSrc && Snake.head.y==ySrc)// src head
			return 1;
		return 0;
	}
	
	void newApple(){
		do{
		x=rand()%80 , y=rand()%25;
		}while(srcSnake(x,y));
		gotoxy(x,y); cout<<'@';
	}
	
	void eatApple(){
		if(x/* for apple */==Snake.head.x && y/* for apple */==Snake.head.y){
			Snake.newPiseof( Snake.body[Snake.sizeSnake-1].x-1 , Snake.body[Snake.sizeSnake-1].y );
			newApple();
			}
	}
}

#endif//_APPLE_HEDAR_SNAKEGAME_