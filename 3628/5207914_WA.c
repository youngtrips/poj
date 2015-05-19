#include <stdio.h>
#include <stdlib.h>
#define MAX 22
int h[MAX], min, n, b;
int cmp(const void* p1, const void* p2)
{
	return *(int*)p2 - *(int*)p1;
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
	int s;
	s = x + h[i];
	if(s >= b)
	{
		if(min > s - b) min = s - b;
		return;
	}
	if(i + 1 < n)
	{
		dfs(s, i + 1);
		dfs(x, i + 1);
	}
}
int main()
{
	init();
	dfs(0, 0);
	printf("%d\n", min);
	return 0;
}
