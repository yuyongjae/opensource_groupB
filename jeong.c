#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
int user_number[4];//사용자 배열
int strike_count[50];//시도 1회당 배열에 스트라이크 저장하기 위한 배열 선언 (정세현)
int ball_count[50];//시도 1회당 배열에 볼 저장하기 위한 배열 선언 (정세현)
int i=1;
int j,k;
int strike;
int ball;
int computer_number[4];//컴퓨터 배열
int count = 0;//시도 횟수 누적 변수

do{
srand(time(NULL));
computer_number[0]=rand()%10;
computer_number[1]=rand()%10;
computer_number[2]=rand()%10;
computer_number[3]=rand()%10;
if((computer_number[0] != computer_number[1]))
{
if((computer_number[1] != computer_number[2]))
{
if((computer_number[2] != computer_number[3]))
{
if((computer_number[0] != computer_number[2]))
{
if((computer_number[1] != computer_number[3]))
{
if((computer_number[0] != computer_number[3]))
{
if(count>=1)
{
printf("카운트 횟수 %d\n",count);
}
printf("Start Game\n");
printf("%d %d %d %d",computer_number[0],computer_number[1],computer_number[2],computer_number[3]);

						break;
					}
				}
			}
		}
	}
}
}while(1);
do{
printf("4개의 숫자 선택 :\n");
fflush(stdout);
scanf("%d %d %d",&user_number[0],&user_number[1],&user_number[2]);
if((computer_number[0]==user_number[0])&&(computer_number[1]==user_number[1])&&(computer_number[2]==user_number[2])&&(computer_number[3]==user_number[3])) // 모두 같으면 게임끝
{
printf("game over \n");
break;
}
else //그렇지 않으면 반복문 실행
{
strike =0;
ball=0; // 변수 초기화 한 이유는 사용자가 게임도중에 시도한 횟수에따라 계속 증가를 막기위한 이유다.
for(j=0;j<4;j++)
{
for(k=0;k<4;k++)
{
if(computer_number[j]==user_number[k]) // 처음에는 변수를 배열로 하지 않았는데 a,b,c,d,e,f 로 하면 조건이 너무 길어져서 일단 임의의 숫자랑 사용자가 선택한 숫자가 같은 조건을 만들었다.
{
if(j==k) //배열의 값도 같고 배열 숫서도 같으면 strike를 1추가 그렇지 않으면 ball추가
strike++;
else
ball++;
}
}
}

}
strike_count[i-1]=strike;//배열 S에 스트라이크를 저장하는 데 i는 1이니까 0부터 저장하기위해서 i-1(정세현)
ball_count[i-1]=ball;//배열 B에 볼을 저장하는 데 i는 1이니까 0부터 저장하기위해서 i-1(정세현)

		for(count=1;count<=i;count++){
printf("%d번쨰 도전결과 : %d strike, %d ball\n",count, strike_count[count-1],strike_count[count-1]);// for문을 써서 a만큼 시도 한다 시도는 i까지 시도하고 저장되어 있는 스트라이크와 볼의 배열에서 해당 값을 가져온다.(정세현)
}
i++;
}while(1);
}
//오류발생 수정바랍니다.