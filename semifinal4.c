#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>


#pragma warning (disable:4996)//scanf함수는 visual studio에서 에러메세지를 동반하므로 본 메시지 추가.
#define computer_num 4 // 컴퓨터랜덤 자리숫자 입력 
#define user_num computer_num //유저랜덤자리숫자 
#define number_counter (computer_num*2)+2
#define putchxy(x,y,c) {gotoxy(x,y); putch(c);}
#define delay(n) Sleep(n)   

int random_number(int random_number[]); //컴퓨터 랜덤함수
int play_game_user(int number[]); //숫자입력 

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void gotoxy(int x, int y);
void setcursortype(CURSOR_TYPE c);

void number_result(int computer[], int player[], int strike_count[], int ball_count[]);

void LoadingStage();//로딩화면

void window_graphic();
/*-------------------------------------------------------------------------------------------------------------*/
int main()
{
	int y = 0;


	int computer[computer_num]; //컴퓨터랜덤숫자
	random_number(computer); //함수로부터 랜덤숫자 가져옴
	int player[user_num]; // 숫자입력 초기화
	
	setcursortype(NOCURSOR);//커서없애기
	LoadingStage();//로딩화면
	system("cls");
	gotoxy(61, y + 2); printf("+-  SCORE BOARD  -+ ");
	gotoxy(61, y + 3); printf("|    S ○ ○ ○   | ");
	gotoxy(61, y + 4); printf("|    B ○ ○ ○ ○| ");
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
re_number: //goto문
	for (i = 0; i <= computer_num; i++) //컴퓨터 지정자리만큼 숫자랜덤지정
	{
		random_number[i] = rand() % 10;
	}
	int a = 0;
	for (i; i <= computer_num; i++) //나머지 (컴퓨터지정숫자-1개) 만큼 배열 0부터 복사 
	{
		random_number[i] = random_number[a];
		a++;
	}
	for (i = 0; i < computer_num; i++)
	{
		if (i == computer_num) //배열 목표지점도착시 반복문 종료 
		{
			break;
		}
		if (random_number[i] == random_number[i + 1] || random_number[i] == random_number[i + 2] || random_number[i] == random_number[i + 3])
		{ // 1 2 3 4 전부 비교 하나라도 같으면 처음으로 
			goto re_number;
		}
	}
	return *random_number;
}
int play_game_user(int number[])
{
	static count_main = 1;

	gotoxy(2, count_main + 2);
	printf(" 숫자 입력 >> ");
	gotoxy(2, count_main + 2);
	printf("%d번째 기회 !!", count_main);
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


	gotoxy(61, y + 22); printf("숫자 4개를 입력하시오.");
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
		gotoxy(61, m + 11); printf("%d회 strike = %d , ball = %d \n", m + 1, strike_count[m], ball_count[m]);
		if (strike_count[m] == 0) {
			gotoxy(61, y + 3); printf("|    S ○ ○ ○   | ");
		}
		if (strike_count[m] == 1) {
			gotoxy(61, y + 3); printf("|    S ● ○ ○   | ");
		}
		if (strike_count[m] == 2) {
			gotoxy(61, y + 3); printf("|    S ● ● ○   | ");
		}
		if (strike_count[m] == 3) {
			gotoxy(61, y + 3); printf("|    S ● ● ●   | ");
		}
		if (ball_count[m] == 0) {
			gotoxy(61, y + 4); printf("|    B ○ ○ ○ ○| ");
		}
		if (ball_count[m] == 1) {
			gotoxy(61, y + 4); printf("|    B ● ○ ○ ○| ");
		}
		if (ball_count[m] == 2) {
			gotoxy(61, y + 4); printf("|    B ● ● ○ ○| ");
		}
		if (ball_count[m] == 3) {
			gotoxy(61, y + 4); printf("|    B ● ● ● ○| ");
		}
		if (ball_count[m] == 4) {
			gotoxy(61, y + 4); printf("|    B ● ● ● ●| ");
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
void LoadingStage()//로딩화면 선언
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
	printf("숫");
	delay(600);
	gotoxy(38, 7);
	printf("자");
	delay(600);
	gotoxy(41, 7);
	printf("야");
	delay(600);
	gotoxy(44, 7);
	printf("구");
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
	printf("B조");
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
	printf("패");
	gotoxy(38, 7);
	printf("배");
}
void end2() {
	system("cls");
	gotoxy(35, 7);
	printf("승");
	gotoxy(38, 7);
	printf("리");
}