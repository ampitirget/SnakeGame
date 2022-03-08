#ifndef _SNAKE_HEDAR_SNAKEGAME_
#define _SNAKE_HEDAR_SNAKEGAME_

namespace snake{
	struct piseof{
		int x,y;
	};
	
	class snake{// class main
		private:
			void displacedint(int&n1,int&n2){ int temporary=n1; n1=n2; n2=temporary; }
			char direction='d';//   w
							   // a s d
		public:
			piseof head= { 10 , 10 };
			piseof body[100];
			int sizeSnake=0;
			
			void newPiseof(int xPiseof,int yPiseof){
				body[sizeSnake++] = {xPiseof , yPiseof};
				gotoxy(xPiseof,yPiseof); cout<<'o';
			}
			
			void getDirection(){
				if(kbhit())
					switch(getch()){
						case'w':if(direction!='s')direction='w';break;
						case's':if(direction!='w')direction='s';break;
						case'd':if(direction!='a')direction='d';break;
						case'a':if(direction!='d')direction='a';break;
					}
				}
			
			void moveSnake(){
				int saveX=head.x,saveY=head.y;
				////// Move Head
				switch(direction){
					case'w':head.y--; if(head.y<0) head.y=24; break;
					case's':head.y++; if(head.y>24) head.y=0; break;
					case'd':head.x++; if(head.x>79) head.x=0; break;
					case'a':head.x--; if(head.x<0) head.x=79; break;
				}
				gotoxy(saveX , saveY); cout<<'o';
				gotoxy(head.x,head.y); cout<<'O';
				////// Move Body
				for(int i=0;i<sizeSnake;i++){
					displacedint(body[i].x,saveX);
					displacedint(body[i].y,saveY);
				}
				gotoxy(saveX,saveY); cout<<' ';
			}
	};
}

#endif//_SNAKE_HEDAR_SNAKEGAME_