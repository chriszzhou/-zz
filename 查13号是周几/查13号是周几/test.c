
#include<stdio.h>
#include<Windows.h>
int c,f,i,e;
int k[7] = {0};
int main()
{
	int count = 0;
	c = 1900;
	e = 1;
	while (count <= 20 * 12)
	{

		switch (e)
		{

		case 1: f += 31;
			break;
		case 2: f += 59;
			break;
		case 3: f += 90;
			break;
		case 4: f += 120;
			break;
		case 5: f += 151;
			break;
		case 6: f += 181;
			break;
		case 7: f += 212;
			break;
		case 8: f += 243;
			break;
		case 9: f += 273;
			break;
		case 10: f += 304;
			break;
		case 11: f += 334;
			break;
		case 12: f += 365;
			break;
		}
		if (c / 4 == 0)
		{
			f++;
		}
		if (e == 12)
		{
			c++;
			e = 0;
		}
		e++;
		k[f % 7] ++;
		count++;
	}
	printf("%c%c\n", 0,1);
	for (i = 0; i < 7; i++)
	{
		printf("ÐÇÆÚ%d have %d day\n",0, i+1, k[i]);
	}
	system("pause");
	return 0;
}