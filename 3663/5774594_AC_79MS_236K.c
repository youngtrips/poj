#include <stdio.h>
#include <stdlib.h>
#define MAXN 20002
int h[MAXN];
int n, s;
int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}
void init()
{
	int i;
	scanf("%d %d", &n, &s);
	for(i = 1;i <= n; i++) scanf("%d", &h[i]);
	qsort((void*)&h[1], n, sizeof(h[1]), cmp);
}
int find(int x)
{
	int high = n;
	int low = 1;
	int mid;
	while(low < high)
	{
		mid = (low + high + 1) / 2;
		if(h[mid] <= x) low = mid;
		else high = mid - 1;
	}
	return low;
}
void solve()
{
	int ans, x, i, j;
	ans = 0;
	for(i = 1;i <= n; i++)
	{
		x = s - h[i];
		if(x < 0) continue;
		j = find(x);
		if(j > i) ans += (j - i);
	}
	printf("%d\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
