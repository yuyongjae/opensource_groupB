#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>


#pragma warning (disable:4996)//scanf�Լ��� visual studio���� �����޼����� �����ϹǷ� �� �޽��� �߰�.
#define computer_num 4 // ��ǻ�ͷ��� �ڸ����� �Է� 
#define user_num computer_num //���������ڸ����� 
#define number_counter (computer_num*2)+2
#define putchxy(x,y,c) {gotoxy(x,y); putch(c);}
#define delay(n) Sleep(n)   

int random_number(int random_number[]); //��ǻ�� �����Լ�
int play_game_user(int number[]); //�����Է� 

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void gotoxy(int x, int y);
void setcursortype(CURSOR_TYPE c);

void number_result(int computer[], int player[], int strike_count[], int ball_count[]);

void LoadingStage();//�ε�ȭ��

void window_graphic();
/*-------------------------------------------------------------------------------------------------------------*/
int main()
{
	int y = 0;


	int computer[computer_num]; //��ǻ�ͷ�������
	random_number(computer); //�Լ��κ��� �������� ������
	int player[user_num]; // �����Է� �ʱ�ȭ
	
	setcursortype(NOCURSOR);//Ŀ�����ֱ�
	LoadingStage();//�ε�ȭ��
	system("cls");
	gotoxy(61, y + 2); printf("+-  SCORE BOARD  -+ ");
	gotoxy(61, y + 3); printf("|    S �� �� ��   | ");
	gotoxy(61, y + 4); printf("|    B �� �� �� ��| ");
	gotoxy(61, y + 5); printf("+-----------------+ ");
	int strike_count[number_counter] = { 0 }, ball_count[number_counter] = { 0 };
	while (1)
	{
		
		gotoxy(2, 2); printf("%d %d %d %d", computer[0], computer[1], computer[2], computer[3]);
		window_graphic();
		play_game_user(player);
		number_result(computer, player, strike_count, ball_count);
	}
	system("pause");
}
/*-------------------------------------------------------------------------------------------------------------*/
int random_number(int random_number[])
{
	srand(time(NULL));
	int i;
re_number: //goto��
	for (i = 0; i <= computer_num; i++) //��ǻ�� �����ڸ���ŭ ���ڷ�������
	{
		random_number[i] = rand() % 10;
	}
	int a = 0;
	for (i; i <= computer_num; i++) //������ (��ǻ����������-1��) ��ŭ �迭 0���� ���� 
	{
		random_number[i] = random_number[a];
		a++;
	}
	for (i = 0; i < computer_num; i++)
	{
		if (i == computer_num) //�迭 ��ǥ���������� �ݺ��� ���� 
		{
			break;
		}
		if (random_number[i] == random_number[i + 1] || random_number[i] == random_number[i + 2] || random_number[i] == random_number[i + 3])
		{ // 1 2 3 4 ���� �� �ϳ��� ������ ó������ 
			goto re_number;
		}
	}
	return *random_number;
}
int play_game_user(int number[])
{
	static count_main = 1;

	gotoxy(2, count_main + 2);
	printf(" ���� �Է� >> ");
	gotoxy(2, count_main + 2);
	printf("%d��° ��ȸ !!", count_main);
	fflush(stdout);
	scanf("%d %d %d %d", &number[0], &number[1], &number[2], &number[3]);
	count_main++;
	return *number;
}
void number_result(int computer[], int player[], int strike_count[], int ball_count[])
{
	int y = 0;
	static count;
	int j, k, m;


	gotoxy(61, y + 22); printf("���� 4���� �Է��Ͻÿ�.");
	for (j = 0; j < user_num; j++)
	{
		for (k = 0; k < user_num; k++)
		{
			if (computer[j] == player[k])
			{
				if (j == k)
				{
					strike_count[count]++;
				}
				else
				{
					ball_count[count]++;
				}
			}
		}
	}
	for (m = 0; m <= count; m++)
	{



		gotoxy(61, 9); printf(" SCORE History :");
		gotoxy(61, m + 11); printf("%dȸ strike = %d , ball = %d \n", m + 1, strike_count[m], ball_count[m]);
		if (strike_count[m] == 0) {
			gotoxy(61, y + 3); printf("|    S �� �� ��   | ");
		}
		if (strike_count[m] == 1) {
			gotoxy(61, y + 3); printf("|    S �� �� ��   | ");
		}
		if (strike_count[m] == 2) {
			gotoxy(61, y + 3); printf("|    S �� �� ��   | ");
		}
		if (strike_count[m] == 3) {
			gotoxy(61, y + 3); printf("|    S �� �� ��   | ");
		}
		if (ball_count[m] == 0) {
			gotoxy(61, y + 4); printf("|    B �� �� �� ��| ");
		}
		if (ball_count[m] == 1) {
			gotoxy(61, y + 4); printf("|    B �� �� �� ��| ");
		}
		if (ball_count[m] == 2) {
			gotoxy(61, y + 4); printf("|    B �� �� �� ��| ");
		}
		if (ball_count[m] == 3) {
			gotoxy(61, y + 4); printf("|    B �� �� �� ��| ");
		}
		if (ball_count[m] == 4) {
			gotoxy(61, y + 4); printf("|    B �� �� �� ��| ");
		}


	}

	if (strike_count[count] == 4)
	{
		end2();
	}
	count++;
	if (count >= 10)
	{
		end1();
	
	
	}

}
void LoadingStage()//�ε�ȭ�� ����
{
	int i;
	for (i = 0; i < 45; i++)
	{
		putchxy(10 + i, 5, '-');
		delay(10);
	}
	for (i = 0; i < 45; i++)
	{
		putchxy(70 - i, 10, '-');
		delay(10);
	}
	delay(800);
	gotoxy(35, 7);
	printf("��");
	delay(600);
	gotoxy(38, 7);
	printf("��");
	delay(600);
	gotoxy(41, 7);
	printf("��");
	delay(600);
	gotoxy(44, 7);
	printf("��");
	delay(600);
	putchxy(48, 8, 'M');
	delay(40);
	putchxy(49, 8, 'a');
	delay(40);
	putchxy(50, 8, 'd');
	delay(40);
	putchxy(51, 8, 'e');
	delay(40);
	putchxy(53, 8, 'b');
	delay(40);
	putchxy(54, 8, 'y');
	delay(40);
	gotoxy(56, 8);
	printf("B��");
	delay(1000);


	gotoxy(30, 12); system("pause");

}

void window_graphic() {


	int i;
	int y = 0;

	for (i = 0; i < 60; i++)
	{
		putchxy(i, 0, '-');
	}
	for (i = 0; i < 20; i++)
	{
		putchxy(0, i, '|')
	}
	for (i = 0; i < 20; i++)
	{
		putchxy(60, i, '|')
	}
	for (i = 0; i < 60; i++)
	{
		putchxy(i, 20, '-')
	}





}
  
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
void end1() {
	system("cls");
	gotoxy(35, 7);
	printf("��");
	gotoxy(38, 7);
	printf("��");
}
void end2() {
	system("cls");
	gotoxy(35, 7);
	printf("��");
	gotoxy(38, 7);
	printf("��");
}