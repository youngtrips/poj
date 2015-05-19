#include <stdio.h>
int main()
{
	int max, tmp, s, d;
	while(scanf("%d %d", &s, &d) != EOF)
	{
		max = -12 * d;
		if(4 * s < d)
		{
			tmp = 10 * s - 2 * d;
			if(max < tmp) max = tmp;
		}
		if(3 * s < 2 * d)
		{
			tmp = 8 * s - 4 * d;
			if(max < tmp) max = tmp;
		}
		if(2 * s < 3 * d)
		{
			tmp = 6 * (s - d);
			if(max < tmp) max = tmp;
		}
		if(s < 4 * d)
		{
			tmp = 3 * s - 9 * d;
			if(max < tmp) max = tmp;
		}
		if(max < 0) printf("Deficit\n");
		else printf("%d\n", max);
	}return 0;
}
