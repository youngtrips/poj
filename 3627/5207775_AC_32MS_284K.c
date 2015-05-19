#include <stdio.h>
#include <stdlib.h>
#define MAX 20002
int h[MAX];
int cmp(const void* p1, const void* p2)
{
	return *(int*)p2 - *(int*)p1;
}
int main()
{
	__int64 b, s;
	int n, i;
	scanf("%d %I64d", &n, &b);
	for(i = 0;i < n; i++) scanf("%d", h + i);
	qsort((void*)h, n, sizeof(h[0]), cmp);
	s = 0;
	for(i = 0;i < n; i++)
	{
		s += h[i];
		if(s >= b) break;
	}
	printf("%d\n", i + 1);
	return 0;
}
