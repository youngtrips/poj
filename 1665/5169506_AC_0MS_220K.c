#include <stdio.h>
#define pi 3.1415927
int main()
{
	double distance,mph,d,t;
	int r,i = 0;
	while(1)
	{
	    scanf("%lf %d %lf", &d, &r, &t);
	    if(r == 0) break;
		i++;
		distance = (pi * d) / 63360.0;
		distance = distance * r;
		mph = (distance * 3600) / t;
		printf("Trip #%d: %0.2f %0.2f\n",i,distance,mph);
	}
	return 0;
}
