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
	
	
	int map[20][20] =//[����][����] [cy][cx] 
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
	
	int input; //����Ű �Է� ���� int�� ���� char�� �ƴ�! 
	static int cx=36,cy=18,score,died;
	//�� ���� 
	map_ptf(map,20,20);
	//���� �÷��̾� ��ġ ��� 
	gotoxy(cx,cy);
	LIGHT_WHITE printf("%s", player);
	
	//����
	gotoxy(43,8);
	LIGHT_GREEN printf("500�� �̻� ���");
	gotoxy(43,12);
	BLUE printf("    ����Ű");
	gotoxy(45,14);
	BLUE printf("    ��");
	gotoxy(45,16);
	BLUE printf("��  ��  ��");
	
	//�̷� �������� ��ǥ�� �÷��̾�cx,cy��ǥ�� ������� ������ ����	
	while(1)
	{
		//������ ��ǥ��,���� ��Ÿ����
		gotoxy(43,5);
		WHITE printf("x = %2d",cx);
		gotoxy(43,6);
		WHITE printf("y = %2d",cy);
		gotoxy(43,7);
		LIGHT_GREEN printf("���� : %-3d", score);
		gotoxy(43,4);
		 
		LIGHT_WHITE printf("");//���� �ʱ�ȭ 
		input = getch();
		switch(input)
		{
			//����Ű�� �Է¹������, ��ũ��ó��
			case LEFT :  
						//�̵��� ���� ��(1)�� �������
						if(map[cy][cx/2-1] == 0 || map[cy][cx/2-1] >= 2)
						{
							gotoxy(cx,cy); //����ǿ��� Ŀ�� �̵� 
							if(map[cy][cx/2-1] == 2)
							{
								score+=100;//���� ������� ���� ���� 
								map[cy][cx/2-1] = 0;
							}
							else if(died == 0 && map[cy][cx/2-1] > 2)
							{
								map[cy][cx/2-1] = 0;
								died++;//�������� ������ �״´� 
							}	
							
							//���� Ŀ���� ����ǿ��� ��Ȯ�� �̵��Ǿ��ִ�. 
							printf("  ");//��ĭ�� ����� �����ִ� ����� ���ڸ� ���ش�. 
							//�������� �̵� 2ĭ
							cx-=2; 
							gotoxy(cx,cy);
							printf("%s", player);
							//����� �ٷ� �ؿ� Ŀ���� �����Ÿ��� ���� ���ϴ� �ָ� ����������.
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
			RED printf("������ ���ڸ��ϴ�");
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
		YELLOW printf("\n\nŻ�� ���� !\n");
	}	
	else if(died > 0)
	{
		RED printf("\n\n\a�ƹ��ų� �ֿ��Դ� �׾���.\n"); 	
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
						BLUE_GREEN printf("��");
						break;
				case 2 :
						RED printf("��");
						break; 
				case 3 :
						PLUM printf("��");
						break; 
				case 4 :
						YELLOW printf("��");
						break; 
				case 5 :
						GREEN printf("��");
						break; 		
				default : break; 
			}
		}
		putchar('\n');
	}
	
	
	
}
