#include <stdio.h>
#include <math.h>
#define q  ((1.0+sqrt(5.0))/2.0)
int main()
{
	int a, b, t;
	while(scanf("%d %d", &a, &b) != EOF)
	{
		if(a > b) 
		{
			t = a;
			a = b;
			b = t;
		}
		t = (int)(q * (b - a));
		if(a == t) printf("0\n");
		else printf("1\n");
	}
	return 0;
}
