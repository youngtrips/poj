#include <stdio.h>
#include <stdlib.h>
#define MAXN 100002
typedef struct
{
	int t;
	int d;
}cow_t;
cow_t cow[MAXN];
int n;
int cmp(const void* p1, const void* p2)
{
	cow_t* a = (cow_t*)p1;
	cow_t* b = (cow_t*)p2;
	return a->d * b->t > b->d * a->t;
}
void init()
{
	int i;
	scanf("%d", &n);
	for(i = 1;i <= n; i++) scanf("%d %d", &cow[i].t, &cow[i].d);
}
void solve()
{
	long long ans;
	int t;
	int i;
	qsort((void*)&cow[1], n, sizeof(cow[1]), cmp);
	ans = 0;
	t = 0;
	for(i = 1;i <= n; i++)
	{
		ans += (t + t) * cow[i].d;
		t = cow[i].t;
	}
	ans += cow[1].t * cow[1].d;
	printf("%lld\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
