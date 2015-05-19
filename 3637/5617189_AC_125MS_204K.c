#include <stdio.h>
#include <stdlib.h>
#define MAXN 20002
int price[MAXN];
int n;
int cmp(const void* p1, const void* p2)
{
	return *(int*)p2 - *(int*)p1;
}
void init()
{
	int i;
	scanf("%d", &n);
	for(i = 1;i <= n; i++) scanf("%d", price + i);
}
void solve()
{
	int ans, i, j;
	qsort((void*)&price[1], n, sizeof(price[1]), cmp);
	ans = 0;
	if(n >= 3)
	{
		for(i = 1;i <= n; i++) 
			if(i % 3 == 0) ans += price[i];
	}
	printf("%d\n", ans);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		solve();
	}
	return 0;
}
