//tiem��غ���
//1.clock_t clock(void) ����clock����ִ����һ��Ϊ��ͷ����������ʱ����ʹ�õ�ʱ�䡣��Ϊfinish - start.
//2.time_t time(NULL)   ����1970-01-01 00��00��00 ����ǰʱ���������
//3.char * asctime(struct tm * ptr) ���ص�ǰʱ������ �� �� ʱ �� �� �� ptrͨ������localtime������gmtime������á�
//4.struct tm localtime(time_t* timer)  ʹ��timer��ֵ���tm
//5.char * ctime( time_t *timer) �൱��3+4
//6.struct tm gmtime( time_t* timer)  �ñ�׼ʱ���ʶ
//7.time_t mktime��struct tm * timeptr����timeptrתΪ����ʱ��
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#pragma warning (disable :4996)
	int b,c,d,e,f,g,h,i,j,k;
int tese(time_t sum)
{
	b = sum / (60 * 60 * 24);//������
	c = b / (365);//��������
	k = c / 4;//������
	c = b / (365) + 1970;//��ǰ��
	d = b % 365 - k;//��ǰ����
	e = d / 31;//e+1Ϊ�·�
	switch (e)
	{
	case 0: f = d;
		break;
	case 1: f = d - 31;
		break;
	case 2: f = d - 31 - 28;
		break;
	case 3: f = d - 90;
		break;
	case 4: f = d - 120;
		break;
	case 5: f = d - 151;
		break;
	case 6: f = d - 181;
		break;
	case 7: f = d - 212;
		break;
	case 8: f = d - 243;
		break;
	case 9: f = d - 273;
		break;
	case 10: f = d - 304;
		break;
	case 11: f = d - 334;
		break;
	}
	if (e >= 2 && c / 4 == 0)
	{
		f--;
	}//fΪ����
	g = sum % (60 * 60 * 24);//ʣ������
	h = g / (60 * 60);//Сʱ
	i = (g % (60 * 60)) / 60;//����
	j = g - i * 60 - h * 60 * 60;//��
	return 0;
}
int main()
{
	struct tm * ptr;
	time_t curtime;
	if (0) {
		time_t a;
		while (1)
		{
			a = time(NULL);//������
			tese(a);
			if (j < 10) {
				printf(" %d-%d-%d %d :%d: 0%d", c, e + 1, f + 1, h + 8, i, j);
			}
			else {
				printf(" %d-%d-%d %d :%d: %d", c, e + 1, f + 1, h + 8, i, j);
			}
			Sleep(100);
			system("cls");
		}
	}
	curtime = time(NULL);
	ptr =gmtime(&curtime);
	printf("%s", asctime(ptr));
	printf("%s", ctime(&curtime));
	system("pause");
	return 0;
}