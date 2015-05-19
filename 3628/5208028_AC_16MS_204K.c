#include <stdio.h>
#include <stdlib.h>
#define MAX 22
int h[MAX], min, n, b;
int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}
void init()
{
	int i;
	scanf("%d %d", &n, &b);
	for(i = 0;i < n; i++) scanf("%d", h + i);
	qsort((void*)h, n, sizeof(h[0]), cmp);
	min = 999999999;
}
void dfs(int x, int i)
{
	if(x >= b)
	{
		if(min > x - b) min = x - b;
		return;
	}
	if(x + h[i] >= b)
	{
		if(min > x + h[i] - b) min = x + h[i] - b;
		return;
	}
	if(i < n)
	{
		dfs(x, i + 1);
		dfs(x + h[i], i + 1);
	}
}
int main()
{
	init();
	dfs(0, 0);
	printf("%d\n", min);
	return 0;
}
