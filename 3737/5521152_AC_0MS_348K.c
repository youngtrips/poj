#include <stdio.h>
#include <math.h>
#define pi acos(-1.0)
double v, s, h, r;
int main()
{
	while(scanf("%lf", &s) != EOF)
	{
		r = sqrt(s / (4.0 * pi));
		h = sqrt(s * s - 2.0 * s * pi * r * r) / (pi * r);
		v = pi * r * r * h / 3.0;
		printf("%0.2f\n", v);
		printf("%0.2f\n", h);
		printf("%0.2f\n", r);
	}
	return 0;
}
