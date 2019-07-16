//tiem相关函数
//1.clock_t clock(void) 返回clock函数执行起（一般为开头），处理器时钟所使用的时间。或为finish - start.
//2.time_t time(NULL)   返回1970-01-01 00：00：00 到当前时间的总秒数
//3.char * asctime(struct tm * ptr) 返回当前时间星期 月 日 时 分 秒 年 ptr通过函数localtime（）或gmtime（）获得。
//4.struct tm localtime(time_t* timer)  使用timer的值填充tm
//5.char * ctime( time_t *timer) 相当于3+4
//6.struct tm gmtime( time_t* timer)  用标准时间标识
//7.time_t mktime（struct tm * timeptr）将timeptr转为当地时间
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#pragma warning (disable :4996)
	int b,c,d,e,f,g,h,i,j,k;
int tese(time_t sum)
{
	b = sum / (60 * 60 * 24);//总天数
	c = b / (365);//经历年数
	k = c / 4;//闰年数
	c = b / (365) + 1970;//当前年
	d = b % 365 - k;//当前天数
	e = d / 31;//e+1为月份
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
	}//f为日期
	g = sum % (60 * 60 * 24);//剩余秒数
	h = g / (60 * 60);//小时
	i = (g % (60 * 60)) / 60;//分钟
	j = g - i * 60 - h * 60 * 60;//秒
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
			a = time(NULL);//总秒数
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