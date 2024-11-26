#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
//   72 
//75 80 77
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#define COL				GetStdHandle(STD_OUTPUT_HANDLE)
#define BLACK			SetConsoleTextAttribute(COL, 0x0000); 
#define DARK_BLUE		SetConsoleTextAttribute(COL, 0x0001);
#define GREEN			SetConsoleTextAttribute(COL, 0x0002);
#define BLUE_GREEN		SetConsoleTextAttribute(COL, 0x0003);
#define BLOOD			SetConsoleTextAttribute(COL, 0x0004);
#define PURPLE			SetConsoleTextAttribute(COL, 0x0005);
#define DARK_YELLOW		SetConsoleTextAttribute(COL, 0x0006);
#define WHITE			SetConsoleTextAttribute(COL, 0x0007);
#define GRAY			SetConsoleTextAttribute(COL, 0x0008);
#define BLUE			SetConsoleTextAttribute(COL, 0x0009);
#define LIGHT_GREEN		SetConsoleTextAttribute(COL, 0x000a);
#define LIGHT_BLUE		SetConsoleTextAttribute(COL, 0x000b);
#define RED				SetConsoleTextAttribute(COL, 0x000c);
#define PLUM			SetConsoleTextAttribute(COL, 0x000d);
#define YELLOW			SetConsoleTextAttribute(COL, 0x000e);
#define LIGHT_WHITE		SetConsoleTextAttribute(COL, 0x000f);

void gotoxy(int x,int y);
void map_ptf(int map[20][20], int x, int y);

int main()
{
	system("mode con: cols=60 lines=21");

	char player[2] = "2";
	
	
	int map[20][20] =//[세로][가로] [cy][cx] 
	{
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,4,1,0,0,0,1,0,0,0,0,3,1,
		1,0,1,1,1,1,1,0,1,1,0,1,0,1,0,1,1,1,1,1,
		1,0,0,0,0,0,1,0,2,1,0,1,0,0,0,0,0,0,0,1,
		1,0,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,
		1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,
		1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
		1,0,1,0,0,0,0,0,1,3,0,1,0,0,0,0,2,1,0,1,
		1,0,1,1,1,0,1,0,1,0,0,1,0,1,1,1,1,1,0,1,
		1,0,1,0,0,0,1,0,1,1,0,0,0,0,0,0,0,1,0,1,
		1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,
		1,0,1,0,1,0,0,2,1,0,0,1,0,0,0,1,0,1,0,1,
		1,0,1,0,1,1,1,1,1,0,0,1,0,1,0,1,0,1,0,1,
		1,0,0,0,0,0,0,0,1,0,1,1,0,1,2,1,0,0,0,1,
		1,1,0,1,1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,
		1,1,0,1,5,0,1,0,1,1,0,1,0,0,0,0,0,0,2,1,
		1,2,0,1,0,0,0,0,1,0,0,1,0,1,1,1,0,1,1,1,
		1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,0,0,0,1,
		1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,1,
		1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
		
	};
	
	int input; //방향키 입력 받을 int형 변수 char형 아님! 
	static int cx=36,cy=18,score,died;
	//맵 생성 
	map_ptf(map,20,20);
	//최초 플레이어 위치 출력 
	gotoxy(cx,cy);
	LIGHT_WHITE printf("%s", player);
	
	//목차
	gotoxy(43,8);
	LIGHT_GREEN printf("500점 이상 통과");
	gotoxy(43,12);
	BLUE printf("    조작키");
	gotoxy(45,14);
	BLUE printf("    ↑");
	gotoxy(45,16);
	BLUE printf("←  ↓  →");
	
	//미로 도착지점 좌표와 플레이어cx,cy좌표가 같을경우 루프문 해제	
	while(1)
	{
		//우측에 좌표값,점수 나타내기
		gotoxy(43,5);
		WHITE printf("x = %2d",cx);
		gotoxy(43,6);
		WHITE printf("y = %2d",cy);
		gotoxy(43,7);
		LIGHT_GREEN printf("점수 : %-3d", score);
		gotoxy(43,4);
		 
		LIGHT_WHITE printf("");//색깔 초기화 
		input = getch();
		switch(input)
		{
			//방향키를 입력받을경우, 매크로처리
			case LEFT :  
						//이동할 곳에 벽(1)이 없을경우
						if(map[cy][cx/2-1] == 0 || map[cy][cx/2-1] >= 2)
						{
							gotoxy(cx,cy); //졸라맨에게 커서 이동 
							if(map[cy][cx/2-1] == 2)
							{
								score+=100;//별이 있을경우 점수 증가 
								map[cy][cx/2-1] = 0;
							}
							else if(died == 0 && map[cy][cx/2-1] > 2)
							{
								map[cy][cx/2-1] = 0;
								died++;//독버섯이 있으면 죽는다 
							}	
							
							//현재 커서는 졸라맨에게 정확히 이동되어있다. 
							printf("  ");//빈칸을 출력해 현재있는 졸라맨 문자를 없앤다. 
							//왼쪽으로 이동 2칸
							cx-=2; 
							gotoxy(cx,cy);
							printf("%s", player);
							//졸라맨 바로 밑에 커서가 깜빡거리면 보기 흉하니 멀리 보내버린다.
							gotoxy(40,20);
						}
						break;
			case RIGHT :  
						if(map[cy][cx/2+1] == 0 || map[cy][cx/2+1] >= 2)
						{
							gotoxy(cx,cy);
							if(map[cy][cx/2+1] == 2)
							{
								score+=100;
								map[cy][cx/2+1] = 0;
							}
							else if(died == 0 && map[cy][cx/2+1] > 2)
							{
								map[cy][cx/2-1] = 0;
								died++;
							}
							printf("  ");
							cx+=2;
							gotoxy(cx,cy);
							printf("%s", player);
							gotoxy(40,20);
						}
						break;
			case UP :  
						if(map[cy-1][cx/2] == 0 || map[cy-1][cx/2] >= 2)
						{
							gotoxy(cx,cy);
							if(map[cy-1][cx/2] == 2)
							{
								score+=100;
								map[cy-1][cx/2] = 0;
							}
							else if(died == 0 && map[cy-1][cx/2] > 2)
							{
								map[cy][cx/2-1] = 0;
								died++;
							}
							printf("  ");
							cy-=1;
							gotoxy(cx,cy);
							printf("%s", player);
							gotoxy(40,20);;
						}
						break;
			case DOWN :  
						if(map[cy+1][cx/2] == 0 || map[cy+1][cx/2] >= 2)
						{
							gotoxy(cx,cy);
							if(map[cy+1][cx/2] == 2)
							{
								score+=100;
								map[cy+1][cx/2] = 0;
							}
							else if(died == 0 && map[cy+1][cx/2] > 2)
							{
								map[cy][cx/2-1] = 0;
								died++;
							}
							printf("  ");
							cy+=1;
							gotoxy(cx,cy);
							printf("%s", player);
							gotoxy(40,20);
						}
						break;
		}
		
		if(cy==20 && cx==2 && score >= 500)
			break;
		else if(cy==20 && cx==2 && score < 500)
		{
			gotoxy(2,20);
			RED printf("점수가 모자릅니다");
			//gotoxy(2,19);
			//printf("  ");
			cy--;
			gotoxy(cx,cy);
			LIGHT_WHITE printf("%s", player);
		}
		else if(died > 0)
		{
			Sleep(500);
			break;
		}
			
		
	}
	
	system("cls");
	if(cy==20 && cx==2)
	{
		YELLOW printf("\n\n탈출 성공 !\n");
	}	
	else if(died > 0)
	{
		RED printf("\n\n\a아무거나 주워먹다 죽었다.\n"); 	
	}
	
	system("pause"); 
	return 0;
}
void gotoxy(int x,int y)
{
	COORD Cur;
	Cur.X=x;
	Cur.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void map_ptf(int map[20][20], int x, int y)
{
	int i,j;
	
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			switch(map[i][j])
			{
				case 0 :
						printf("  ");
						break;
				case 1 :
						BLUE_GREEN printf("■");
						break;
				case 2 :
						RED printf("☆");
						break; 
				case 3 :
						PLUM printf("♧");
						break; 
				case 4 :
						YELLOW printf("♡");
						break; 
				case 5 :
						GREEN printf("♤");
						break; 		
				default : break; 
			}
		}
		putchar('\n');
	}
	
	
	
}
