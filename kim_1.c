#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <process.h>



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

void number_result(int computer[], int player[], int strike_count[], int ball_count[], int y, int chance);

void LoadingStage();//로딩화면
void window_graphic();

void win_stage(int y,int chance);
void lose_stage(int y);



/*-------------------------------------------------------------------------------------------------------------*/

/*unsigned _stdcall Thread1(void *arg) {

	while (1) {
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);

		gotoxy(61, 6); printf("%d-%d-%d %d:%d:%d\n",
			tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
			tm.tm_hour, tm.tm_min, tm.tm_sec);
		delay(1000);
	}
}
*/

int main()
{


	int y = 0;

	int computer[computer_num]; //컴퓨터랜덤숫자
	random_number(computer); //함수로부터 랜덤숫자 가져옴
	int player[user_num]; // 숫자입력 초기화

	setcursortype(NOCURSOR);//커서없애기
	LoadingStage();//로딩화면
	system("cls");
	int chance = 10;

	gotoxy(4, 2); printf(" 기  록 ");
	gotoxy(61, y + 1); printf("+-- SCORE BOARD ---+ ");
	gotoxy(61, y + 2); printf("|  S ○ ○ ○ ○   | ");
	gotoxy(61, y + 3); printf("|  B ○ ○ ○ ○   | ");
	gotoxy(61, y + 4); printf("+------------------+ ");

	gotoxy(61, y + 6); printf("+-  남 은 횟 수  -+ ");
	gotoxy(61, y + 7); printf("|        %d       | ", chance);
	gotoxy(61, y + 8); printf("+-----------------+ ");

	gotoxy(61, y + 10); printf("+-------게 임 규 칙----------+ ");
	gotoxy(61, y + 11); printf("|                            | ");
	gotoxy(61, y + 12); printf("| 컴퓨터 숫자 중복안나옴     | ");
	gotoxy(61, y + 13); printf("|                            | ");
	gotoxy(61, y + 14); printf("| 사용자 중복숫자입력 무시   | ");
	gotoxy(61, y + 15); printf("|                            | ");
	gotoxy(61, y + 16); printf("| 도전횟수는 총 10회         | ");
	gotoxy(61, y + 17); printf("|                            | ");
	gotoxy(61, y + 18); printf("| 숫자마다 공백을 넣어주세요 | ");
	gotoxy(61, y + 19); printf("|                            | ");
	gotoxy(61, y + 20); printf("+----------------------------+ ");

	int strike_count[number_counter] = { 0 }, ball_count[number_counter] = { 0 };
	window_graphic();

	while (1)
	{
		gotoxy(4, 21);	printf("test용 컴퓨터숫자 >> %d %d %d %d",
			computer[0], computer[1], computer[2], computer[3]);

		play_game_user(player);
		number_result(computer, player, strike_count, ball_count,y,chance);
		//gotoxy(61, 6); _beginthreadex(NULL, 0, Thread1, 0, 0, NULL);
		chance--;
		gotoxy(61, y + 6); printf("+-  남 은 횟 수  -+ ");
		gotoxy(61, y + 7); printf("|        %d        | ", chance);
		gotoxy(61, y + 8); printf("+-----------------+ ");
		gotoxy(4, 22);	printf("반환되는 유저숫자 >> %d %d %d %d",player[0], player[1], player[2], player[3]);
	}

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
	static count_main = 0;

	count_main++;
error_back: // 안쓰려고했는데 생각할시간이 없어요 ...;;
	gotoxy(2, count_main + 2);
	printf(" 숫자 입력 >> ");
	gotoxy(2, count_main + 2);
	printf("%d번째 기회 !! ", count_main);	
	
	char string_number[20];		

	scanf("%d %d %d %d", &number[0], &number[1], &number[2], &number[3]);	

	if (number[0] == number[1] || number[0] == number[2] || number[0] == number[3]
		|| number[1] == number[2] || number[1] == number[3]
		|| number[2] == number[3])
	{
		goto error_back;
	}

	return *number;
}
void number_result(int computer[], int player[], int strike_count[], int ball_count[],int y, int chance)
{

	static count;
	int j, k, m, i;

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

		gotoxy(25, m + 3); printf("----> strike = %d , ball = %d \n", strike_count[m], ball_count[m]);
		if (strike_count[m] == 0) {
			gotoxy(61, y + 2); printf("|  S ○ ○ ○ ○   | ");
		}
		if (strike_count[m] == 1) {
			gotoxy(61, y + 2); printf("|  S ● ○ ○ ○   | ");
		}
		if (strike_count[m] == 2) {
			gotoxy(61, y + 2); printf("|  S ● ● ○ ○   | ");
		}
		if (strike_count[m] == 3) {
			gotoxy(61, y + 2); printf("|  S ● ● ● ○   | ");
		}
		if (strike_count[m] == 4) {
			gotoxy(61, y + 2); printf("|  S ● ● ● ●   | ");
		}
		if (ball_count[m] == 0) {
			gotoxy(61, y + 3); printf("|  B ○ ○ ○ ○   | ");
		}
		if (ball_count[m] == 1) {
			gotoxy(61, y + 3); printf("|  B ● ○ ○ ○   | ");
		}
		if (ball_count[m] == 2) {
			gotoxy(61, y + 3); printf("|  B ● ● ○ ○   | ");
		}
		if (ball_count[m] == 3) {
			gotoxy(61, y + 3); printf("|  B ● ● ● ○   | ");
		}
		if (ball_count[m] == 4) {
			gotoxy(61, y + 3); printf("|  B ● ● ● ●   | ");
		}
	}

	if (strike_count[count] == 4)
	{
		system("cls");
		win_stage(y,chance);
	}
	count++;
	if (count >= 10)
	{
		system("cls");
		lose_stage(y);
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


	gotoxy(30, 12);
	printf("아무키 누르면 게임진행 가능합니다.");

	system("pause>null");


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


void win_stage(int y,int chance)
{
	gotoxy(61, y + 1); printf("+-- SCORE BOARD ---+ ");
	gotoxy(61, y + 2); printf("|  S ● ● ● ●   | ");
	gotoxy(61, y + 3); printf("|  B ○ ○ ○ ○   | ");
	gotoxy(61, y + 4); printf("+------------------+ ");

	gotoxy(61, y + 6); printf("+-  남 은 횟 수  -+ ");
	gotoxy(61, y + 7); printf("|        %d       | ",chance);
	gotoxy(61, y + 8); printf("+-----------------+ ");

	gotoxy(61, y + 10); printf("+-------게 임 규 칙----------+ ");
	gotoxy(61, y + 11); printf("|                            | ");
	gotoxy(61, y + 12); printf("| 컴퓨터 숫자 중복안나옴     | ");
	gotoxy(61, y + 13); printf("|                            | ");
	gotoxy(61, y + 14); printf("| 사용자 중복숫자입력 무시   | ");
	gotoxy(61, y + 15); printf("|                            | ");
	gotoxy(61, y + 16); printf("| 도전횟수는 총 10회         | ");
	gotoxy(61, y + 17); printf("|                            | ");
	gotoxy(61, y + 18); printf("| 숫자마다 공백을 넣어주세요 | ");
	gotoxy(61, y + 19); printf("|                            | ");
	gotoxy(61, y + 20); printf("+----------------------------+ ");
	window_graphic();
	delay(800);
	gotoxy(16, 7);
	printf("승");
	delay(600);
	gotoxy(35, 7);
	printf("리");
	delay(600);
	system("pause>null");
	exit(0);
	
}

void lose_stage(int y)
{
	gotoxy(61, y + 1); printf("+-- SCORE BOARD ---+ ");
	gotoxy(61, y + 2); printf("|  S ○ ○ ○ ○   | ");
	gotoxy(61, y + 3); printf("|  B ○ ○ ○ ○   | ");
	gotoxy(61, y + 4); printf("+------------------+ ");

	gotoxy(61, y + 6); printf("+-  남 은 횟 수  -+ ");
	gotoxy(61, y + 7); printf("|        0        | ");
	gotoxy(61, y + 8); printf("+-----------------+ ");

	gotoxy(61, y + 10); printf("+-------게 임 규 칙----------+ ");
	gotoxy(61, y + 11); printf("|                            | ");
	gotoxy(61, y + 12); printf("| 컴퓨터 숫자 중복안나옴     | ");
	gotoxy(61, y + 13); printf("|                            | ");
	gotoxy(61, y + 14); printf("| 사용자 중복숫자입력 무시   | ");
	gotoxy(61, y + 15); printf("|                            | ");
	gotoxy(61, y + 16); printf("| 도전횟수는 총 10회         | ");
	gotoxy(61, y + 17); printf("|                            | ");
	gotoxy(61, y + 18); printf("| 숫자마다 공백을 넣어주세요 | ");
	gotoxy(61, y + 19); printf("|                            | ");
	gotoxy(61, y + 20); printf("+----------------------------+ ");
	window_graphic();
	delay(800);
	gotoxy(16, 7);
	printf("패");
	delay(600);
	gotoxy(35, 7);
	printf("배");
	delay(600);
	system("pause>null");
	exit(0);
}
