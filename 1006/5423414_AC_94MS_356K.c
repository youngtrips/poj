#include <stdio.h>
#define MAX 21252
int main()
{
	int p, e, i, d, j, s = 1;
	while(1)
	{
		scanf("%d %d %d %d", &p, &e, &i, &d);
		if(p == -1 && e == -1 && i == -1 && d == -1) break;
		for(j = d + 1;j <= MAX; j++) if((j - p) % 23 == 0) break;
		for(;j <= MAX; j += 23) if((j - e) % 28 == 0) break;
		for(;j <= MAX; j += 644) if((j - i) % 33 == 0) break;
		printf("Case %d: the next triple peak occurs in %d days.\n", s++, j - d);
	}
	return 0;
}
