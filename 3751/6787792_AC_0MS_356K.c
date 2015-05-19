#include <stdio.h>
#include <string.h>

#define AM_BOUNDER 12 * 3600
#define AM 0
#define PM 1

const static char *str[] = {"am", "pm"};

int am_or_pm(int hour, int min, int sec)
{
	int timestamps = hour * 3600 + min * 60 + sec;
	if(timestamps >= 1 && timestamps <= AM_BOUNDER) return AM;
	return PM;
}

void doit(const char *buf)
{
	int year;
	int mon;
	int date;
	int hour;
	int min;
	int sec;
	int flag;
	
	sscanf(buf,	"%d/%d/%d-%d:%d:%d", &year, &mon, &date, &hour, &min, &sec);
	flag = am_or_pm(hour, min, sec);
	if(hour >= 13 && hour <= 23) hour -= 12;
	if(flag == AM && hour == 0) hour = 12;
	printf("%02d/%02d/%d-%02d:%02d:%02d%s\n", mon, date, year, hour, min, sec, str[flag]);
}

int main()
{
	char buf[64];
	int n;
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		gets(buf);
		doit(buf);
	}
	return 0;
}
