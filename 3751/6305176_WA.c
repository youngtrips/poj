#include <stdio.h>

#define AM 0
#define PM 1
typedef unsigned int uint_32;
typedef unsigned char uint_8;

const char flag[2][3] = {"am", "pm"};

typedef struct
{
	uint_32 year;
	uint_32 month;
	uint_32 day;
	
	uint_32 hour;
	uint_32 min;
	uint_32 sec;

	uint_8 flag;
}st_time;

st_time time;

void init()
{
	scanf("%d/%d/%d-%d:%d:%d", &time.year, &time.month, &time.day,
								&time.hour, &time.min, &time.sec);
}

void dosome()
{
	time.flag = AM;
	if(time.hour >= 12 && time.min >= 0 && time.sec > 0)
	{
		time.flag = PM;
		time.hour -= 12;
	}

	if(time.hour == 12 && time.min == 0 && time.sec == 0)
	{
		time.flag = PM;
	}
	if(time.hour == 24 && time.min == 0 && time.sec == 0)
	{
		time.hour = 12;
		time.flag = AM;
	}
	printf("%02d/%02d/%d-%02d:%02d:%02d%s\n", time.month, time.day, time.year, 
												time.hour, time.min, time.sec, flag[time.flag]);
}

int main()
{
	uint_32 cases;
	scanf("%d", &cases);
	while(cases--)
	{
		init();
		dosome();
	}
	return 0;
}
