#include <stdio.h>
#define MAXN 1002
int k[MAXN];
int cnt, n, x;
int main()
{
	int i;
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		x = 0; cnt = 0;
		for(i = 0;i < n; i++)
		{
			scanf("%d", k + i);
			x ^= k[i];
		}
		for(i = 0;i < n; i++)
			if((k[i] ^ x) < k[i]) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
