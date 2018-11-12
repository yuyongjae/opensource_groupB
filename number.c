#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int computer_number[4];//컴퓨터 배열
int user_number[4];//사용자 배열
int count;//시도 횟수 누적 변수

int strike_count[50];//시도 1회당 배열에 스트라이크 저장하기 위한 배열 선언 (정세현)
int ball_count[50];//시도 1회당 배열에 볼 저장하기 위한 배열 선언 (정세현)
int i=1;
int j,k;
int strike;
int ball;
do{
srand(time(NULL));
computer_number[0]=rand()%10;
computer_number[1]=rand()%10;
computer_number[2]=rand()%10;
computer_number[3]=rand()%10;
if((computer_number[0] != computer_number[1]))
if((computer_number[1] != computer_number[2]))
if((computer_number[2] != computer_number[3]))
if((computer_number[0] != computer_number[2]))
if((computer_number[1] != computer_number[3]))
if((computer_number[0] != computer_number[3]))
{
printf("Start Game\n");
break;
}
}while(1); //서로다른 숫자를 뽑기위해 계속 실행하기위해 do while 무한반복문을 하였다.

