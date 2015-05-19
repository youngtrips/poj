#include <stdio.h>
#include <stdlib.h>
#define MAX 50002
int dis[MAX];
int l, n, m;
int cmp(const void* p1, const void* p2)
{
	int a = *(int*)p1;
	int b = *(int*)p2;
	if(a < b) return -1;
	else if(a == b) return 0;
	else return 1;
}
void init()
{
	int i;
	scanf("%d %d %d", &l, &n, &m);
	for(i = 1;i <= n; i++) scanf("%d", &dis[i]);
}
void solve()
{
	int a = 0;
	int b = l;
	int c;
	int r;
	int x;
	int i;
	qsort((void*)&dis[1], n, sizeof(dis[1]), cmp);
	while(a < b)
	{
		c = (a + b + 1) / 2;
		x = 0;
		r = 0;
		for(i = 1;i <= n; i++)
		{
			if(dis[i] - x < c) r++;
			else x = dis[i];
		}
		if(r > m) b = c - 1;
		else a = c;
	}
	printf("%d\n", a);
}
int main()
{
	init();
	solve();
	return 0;
}
