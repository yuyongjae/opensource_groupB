#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
int user_number[4];//����� �迭
int strike_count[50];//�õ� 1ȸ�� �迭�� ��Ʈ����ũ �����ϱ� ���� �迭 ���� (������)
int ball_count[50];//�õ� 1ȸ�� �迭�� �� �����ϱ� ���� �迭 ���� (������)
int i=1;
int j,k;
int strike;
int ball;
int computer_number[4];//��ǻ�� �迭
int count = 0;//�õ� Ƚ�� ���� ����

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
printf("ī��Ʈ Ƚ�� %d\n",count);
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
printf("4���� ���� ���� :\n");
fflush(stdout);
scanf("%d %d %d",&user_number[0],&user_number[1],&user_number[2]);
if((computer_number[0]==user_number[0])&&(computer_number[1]==user_number[1])&&(computer_number[2]==user_number[2])&&(computer_number[3]==user_number[3])) // ��� ������ ���ӳ�
{
printf("game over \n");
break;
}
else //�׷��� ������ �ݺ��� ����
{
strike =0;
ball=0; // ���� �ʱ�ȭ �� ������ ����ڰ� ���ӵ��߿� �õ��� Ƚ�������� ��� ������ �������� ������.
for(j=0;j<4;j++)
{
for(k=0;k<4;k++)
{
if(computer_number[j]==user_number[k]) // ó������ ������ �迭�� ���� �ʾҴµ� a,b,c,d,e,f �� �ϸ� ������ �ʹ� ������� �ϴ� ������ ���ڶ� ����ڰ� ������ ���ڰ� ���� ������ �������.
{
if(j==k) //�迭�� ���� ���� �迭 ������ ������ strike�� 1�߰� �׷��� ������ ball�߰�
strike++;
else
ball++;
}
}
}

}
strike_count[i-1]=strike;//�迭 S�� ��Ʈ����ũ�� �����ϴ� �� i�� 1�̴ϱ� 0���� �����ϱ����ؼ� i-1(������)
ball_count[i-1]=ball;//�迭 B�� ���� �����ϴ� �� i�� 1�̴ϱ� 0���� �����ϱ����ؼ� i-1(������)

		for(count=1;count<=i;count++){
printf("%d���� ������� : %d strike, %d ball\n",count, strike_count[count-1],strike_count[count-1]);// for���� �Ἥ a��ŭ �õ� �Ѵ� �õ��� i���� �õ��ϰ� ����Ǿ� �ִ� ��Ʈ����ũ�� ���� �迭���� �ش� ���� �����´�.(������)
}
i++;
}while(1);
}
//�����߻� �����ٶ��ϴ�.