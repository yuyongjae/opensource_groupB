#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define game_size 12 //총 시도횟수 10회 +2회 여유분 (횟수 넘으면 computer 지정숫자 바뀝니다.)
#define computer_num 4 // 컴퓨터 숫자 자릿수
#define player_num 4 //플레이어 숫자 자릿수

/*-------------------------------------------------------------------------------------------------------------*/


int random_numbers(int random_number[]); //컴퓨터 랜덤함수
int play_game_user(int number[game_size][computer_num]); //숫자입력 

void number_result(int computer[], int player[game_size][player_num], int strike_count[], int ball_count[]);



/*-------------------------------------------------------------------------------------------------------------*/

int main()
{

	int computer[computer_num]; //컴퓨터랜덤숫자 변수입력

	random_numbers(computer); //함수로부터 랜덤숫자 지정 및 변수대입

	int player[game_size][player_num] = { {0},{0} }; // 플레이어 배열 0으로 초기화

	 // 스트라이크 볼 배열 선언 및 초기화
	int strike_count[game_size] = { 0 }, ball_count[game_size] = { 0 };

	while (1)
	{

		play_game_user(player); // 플레이어 숫자입력 

		number_result(computer, player, strike_count, ball_count); //플레이어 컴퓨터 숫자비교 
		printf("\n\n\n\n\n");

	}


}

/*-------------------------------------------------------------------------------------------------------------*/


int random_numbers(int random_number[])
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
		if (i > computer_num) //배열 목표지점도착시 반복문 종료 
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

/*-------------------------------------------------------------------------------------------------------------*/

int play_game_user(int number[game_size][player_num])
{

	static count_user = 0; //몇번쨰 기회인지 카운팅

	static chance;
	printf("%d번째 기회 !!!!  ", ++chance);


	printf("숫자를 입력해주세요 >> ");
	scanf("%d %d %d %d", &number[count_user][0], &number[count_user][1], &number[count_user][2], &number[count_user][3]);
	count_user++;

	return *number;

}

/*-------------------------------------------------------------------------------------------------------------*/



void number_result(int computer[], int player[game_size][computer_num], int strike_count[], int ball_count[])
{

	static count;
	int i, j;


	for (i = 0; i < player_num; i++) //스트라이크 볼 카운팅 
	{
		for (j = 0; j < player_num; j++)
		{
			if (player[count][i] == computer[j])
			{
				if (i == j)
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
	j = 1; // 누적카운팅인데 몇번째 도전인지 누적별 카운팅 하기위해서 씁니다.
	for (i = 0; i <= count; i++) // 결과누적치 출력 
	{

		printf("%d번째 도전 %d %d %d %d --->> strike = %d , ball = %d ", j, player[i][0], player[i][1], player[i][2], player[i][3], strike_count[i], ball_count[i]);
		j++;
		printf("\n");
	}
	printf("\n\n");
	printf("%d %d %d %d --->>  strike = %d , ball = %d", player[count][0], player[count][1], player[count][2], player[count][3], strike_count[count], ball_count[count]);
	printf("\n\n\n"); //현재 결과출력 


	if (strike_count[count] == 4) // 승리조건
	{
		printf("게임에 승리하셧습니다.");
		printf("%d번 기회만에 성공하셨습니다.", count + 1);
		printf("\n\n\n\n");
		system("pause");
		exit(0);

	}
	count++;
	if (count >= 10) // 패배조건
	{
		printf("게임에 패배하셨습니다.\n");
		printf("컴퓨터 지정숫자 %d %d %d %d", computer[0], computer[1], computer[2], computer[3]);
		printf("\n");
		system("pause");
		exit(0);

	}

}

/*-------------------------------------------------------------------------------------------------------------*/



