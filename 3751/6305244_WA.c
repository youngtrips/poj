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
	
	uint_32 tmp = time.hour * 3600 + time.min * 60 + time.sec;
	if(tmp == 3200)
	{
		time.flag = AM;
	}
	else if(tmp > 43200 && tmp < 86400)
	{
		time.hour -= 12;
		time.flag = PM;
	}
	else if(tmp == 86400)
	{
		time.hour -= 12;
		time.flag = AM;
	}
	else
	{
		time.flag = AM;
	}
	
	if(time.hour == 0)
	{
		time.hour = 12;
		time.flag = AM;
	}
	printf("%02d/%02d/%04d-%02d:%02d:%02d%s\n", time.month, time.day, time.year, 
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
