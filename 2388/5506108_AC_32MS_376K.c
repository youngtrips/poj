#include <stdio.h>
#include <stdlib.h>
#define MAX 10002
int a[MAX];
int n;
int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}
void init()
{
	int i;
	scanf("%d", &n);
	for(i = 0;i < n; i++) scanf("%d", a + i);
}
void solve()
{
	int ans;
	qsort((void*)&a[0], n, sizeof(a[0]), cmp);
	ans = a[(n - 1) / 2];
	printf("%d\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
