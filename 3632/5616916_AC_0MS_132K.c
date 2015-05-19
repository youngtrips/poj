#include <stdio.h>
int main()
{
	int rmost, lmost, n, x, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		rmost = 0; lmost = 99999;
		while(n--)
		{
			scanf("%d", &x);
			if(rmost < x) rmost = x;
			if(lmost > x) lmost = x;
		}
		printf("%d\n", (rmost - lmost)<<1);
	}
	return 0;
}
