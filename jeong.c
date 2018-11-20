#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#pragma warning (disable:4996)//scanf함수는 visual studio에서 에러메세지를 동반하므로 본 메시지 추가.

#define computer_num 4 // 컴퓨터랜덤 자리숫자 입력 
#define user_num computer_num //유저랜덤자리숫자 
#define number_counter (computer_num*2)+2



int random_number(int random_number[]); //컴퓨터 랜덤함수
int play_game_user(int number[]); //숫자입력 

void number_result(int computer[], int player[], int strike_count[], int ball_count[]);

/*-------------------------------------------------------------------------------------------------------------*/

int main()
{

	int computer[computer_num]; //컴퓨터랜덤숫자
	random_number(computer); //함수로부터 랜덤숫자 가져옴
	int player[user_num]; // 숫자입력 초기화 

	printf("%d %d %d %d\n", computer[0], computer[1], computer[2], computer[3]);

	int strike_count[number_counter] = { 0 }, ball_count[number_counter] = { 0 };

	while (1)
	{
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

	printf("%d번째 기회 !!!!\n", count_main);
	printf("숫자를 입력해주세요 >> ");
	fflush(stdout);
	scanf("%d %d %d %d", &number[0], &number[1], &number[2], &number[3]);
	count_main++;
	return *number;

}


void number_result(int computer[], int player[], int strike_count[], int ball_count[])
{


	static count;
	int j, k, m;


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
		printf("strike = %d , ball = %d ", strike_count[m], ball_count[m]);
		printf("\n");
	}
	printf("\n\n");
	printf("strike = %d , ball = %d", strike_count[count], ball_count[count]);
	printf("\n\n\n");


	if (strike_count[count] == 4)
	{
		printf("게임에 승리하셧습니다.");
		printf("\n");
		system("pause");
		exit(0);

	}

	count++;

	if (count >= 10)
	{
		printf("게임에 패배하셨습니다.");
		printf("\n");
		system("pause");
		exit(0);

	}
}




