#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define game_size 12 //�� �õ�Ƚ�� 10ȸ +2ȸ ������ (Ƚ�� ������ computer �������� �ٲ�ϴ�.)
#define computer_num 4 // ��ǻ�� ���� �ڸ���
#define player_num 4 //�÷��̾� ���� �ڸ���

/*-------------------------------------------------------------------------------------------------------------*/


int random_numbers(int random_number[]); //��ǻ�� �����Լ�
int play_game_user(int number[game_size][computer_num]); //�����Է� 

void number_result(int computer[], int player[game_size][player_num], int strike_count[], int ball_count[]);



/*-------------------------------------------------------------------------------------------------------------*/

int main()
{

	int computer[computer_num]; //��ǻ�ͷ������� �����Է�

	random_numbers(computer); //�Լ��κ��� �������� ���� �� ��������

	int player[game_size][player_num] = { {0},{0} }; // �÷��̾� �迭 0���� �ʱ�ȭ

	 // ��Ʈ����ũ �� �迭 ���� �� �ʱ�ȭ
	int strike_count[game_size] = { 0 }, ball_count[game_size] = { 0 };

	while (1)
	{

		play_game_user(player); // �÷��̾� �����Է� 

		number_result(computer, player, strike_count, ball_count); //�÷��̾� ��ǻ�� ���ں� 
		printf("\n\n\n\n\n");

	}


}

/*-------------------------------------------------------------------------------------------------------------*/


int random_numbers(int random_number[])
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
		if (i > computer_num) //�迭 ��ǥ���������� �ݺ��� ���� 
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

/*-------------------------------------------------------------------------------------------------------------*/

int play_game_user(int number[game_size][player_num])
{

	static count_user = 0; //����� ��ȸ���� ī����

	static chance;
	printf("%d��° ��ȸ !!!!  ", ++chance);


	printf("���ڸ� �Է����ּ��� >> ");
	scanf("%d %d %d %d", &number[count_user][0], &number[count_user][1], &number[count_user][2], &number[count_user][3]);
	count_user++;

	return *number;

}

/*-------------------------------------------------------------------------------------------------------------*/



void number_result(int computer[], int player[game_size][computer_num], int strike_count[], int ball_count[])
{

	static count;
	int i, j;


	for (i = 0; i < player_num; i++) //��Ʈ����ũ �� ī���� 
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
	j = 1; // ����ī�����ε� ���° �������� ������ ī���� �ϱ����ؼ� ���ϴ�.
	for (i = 0; i <= count; i++) // �������ġ ��� 
	{

		printf("%d��° ���� %d %d %d %d --->> strike = %d , ball = %d ", j, player[i][0], player[i][1], player[i][2], player[i][3], strike_count[i], ball_count[i]);
		j++;
		printf("\n");
	}
	printf("\n\n");
	printf("%d %d %d %d --->>  strike = %d , ball = %d", player[count][0], player[count][1], player[count][2], player[count][3], strike_count[count], ball_count[count]);
	printf("\n\n\n"); //���� ������ 


	if (strike_count[count] == 4) // �¸�����
	{
		printf("���ӿ� �¸��ϼ˽��ϴ�.");
		printf("%d�� ��ȸ���� �����ϼ̽��ϴ�.", count + 1);
		printf("\n\n\n\n");
		system("pause");
		exit(0);

	}
	count++;
	if (count >= 10) // �й�����
	{
		printf("���ӿ� �й��ϼ̽��ϴ�.\n");
		printf("��ǻ�� �������� %d %d %d %d", computer[0], computer[1], computer[2], computer[3]);
		printf("\n");
		system("pause");
		exit(0);

	}

}

/*-------------------------------------------------------------------------------------------------------------*/



