#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#pragma warning(disable :4996)
int a[3][3] = {0};
int count1 = 0, count2 = 0;
void inter()
{
	printf("=======================\n");
	printf("=======��Ϸ�˵�========\n");
	printf("======1.��ʼ��Ϸ=======\n");
	printf("========2.ս��=========\n");
	printf("========3.�˳�=========\n");
	printf("=======================\n");
}
int judge(int i, int j)
{
	if (a[i - 1][j - 1] == 0)
		return 1;
	else
		return 0;
}
int judgetest( )
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if ((a[i][0] == 1 && a[i][1] == 1 && a[i][2] == 1) || (a[0][i] == 1 && a[1][i] == 1 && a[2][i] == 1))
		{
			return 1;
		}
		if ((a[i][0] == 2 && a[i][1] == 2 && a[i][2] == 2)|| (a[0][i] == 2 && a[1][i] == 2 && a[2][i] == 2))
		{
			return 2;
		}
	}
	if ((a[0][0] == 1 && a[1][1] == 1 && a[2][2] == 1) || (a[0][2] == 1 && a[1][1] == 1 && a[2][0] == 1))
	{
		return 1;
	}
	if ((a[0][0] == 2 && a[1][1] == 2 && a[2][2] == 2) || (a[0][2] == 2 && a[1][1] == 2 && a[2][0] == 2))
	{
		return 2;
	}
	return 0;
}
void person()
{
	int i, j;
	printf("��ѡ����Ҫ�µ�λ��\n");
	scanf("%d %d", &i,&j);
	while(judge(i, j) == 0)
	{
		person();
	}
		a[i - 1][j - 1] = 1;
}
void ai()
{
	int  ab,b;
	srand((int)time(NULL));
	ab = rand()%3;
	b = rand()%3;
	while(judge(ab+1,b+1) == 0)
	{
		ab = rand() % 3;
		b = rand() % 3;
		printf("%d %d\n", ab, b);
	}
		a[ab][b] = 2;
}
void borad()
{
	int i, j;
	printf("=======================\n");
	printf("_______________\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%-7d", a[i][j]);
		}
		printf("\n");
		printf("_______________\n");
	}
}
void game()
{
	int su;
	borad();
	printf("��ѡ����������д1��");
	printf("��ѡ���������д2\n");
	scanf("%d", &su);

	if (su == 1)
	{
		while (judgetest() == 0)
		{
        person();
		borad();
		ai();
		borad();
		}
	}
	if (su == 2)
	{
		while (judgetest() == 0)
		{
			ai();
			borad();
			person();
			borad();
		}
	}	
	if (judgetest() == 1)
		{
			printf("��Ӯ��\n");
			count1++;
		}
		else {
			printf("������\n");
			count2++;
		}
}
int main()
{
	int  n;
	while (1) {
		inter();
		scanf("%d", &n);
		if (n == 1)
		{
			game();
			system("cls");
		}
		if (n == 2)
		{
			printf("��Ļ��֣�%d\n ���ԵĻ��֣�%d\n", count1, count2);
		}
		if (n == 3)
		{
			break;
		}
		memset(a,0,sizeof(int)*9);
	}
}