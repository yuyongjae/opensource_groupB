#include <groupB.h>//�츮�� ������ �������

#pragma warning (disable:4996)//scanf�Լ��� visual studio���� �����޼����� �����ϹǷ� �� �޽��� �߰�.

#define computer_num 4 // ��ǻ�ͷ��� �ڸ����� �Է� 
#define user_num computer_num //���������ڸ����� 
#define number_counter (computer_num*2)+2
#define putchxy(x,y,c) {gotoxy(x,y); putch(c);}




int random_number(int random_number[]); //��ǻ�� �����Լ�
int play_game_user(int number[]); //�����Է� 

void number_result(int computer[], int player[], int strike_count[], int ball_count[]);
void LoadingStage();//�ε�ȭ��
/*-------------------------------------------------------------------------------------------------------------*/

int main()
{
	setcursortype(NOCURSOR);//Ŀ�����ֱ�

	LoadingStage();//�ε�ȭ��


	int computer[computer_num]; //��ǻ�ͷ�������
	random_number(computer); //�Լ��κ��� �������� ������
	int player[user_num]; // �����Է� �ʱ�ȭ 

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

	printf("%d��° ��ȸ !!!!\n", count_main);
	printf("���ڸ� �Է����ּ��� >> ");
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
		printf("���ӿ� �¸��ϼ˽��ϴ�.");
		printf("\n");
		system("pause");
		exit(0);

	}

	count++;

	if (count >= 10)
	{
		printf("���ӿ� �й��ϼ̽��ϴ�.");
		printf("\n");
		system("pause");
		exit(0);

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

	printf("B");

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



	delay(2500);

}

