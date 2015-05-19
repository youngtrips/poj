#include <stdio.h>
#include <stdlib.h>
#define MAXN 4000
typedef struct{ int val; int cnt; }sum_t;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
sum_t sl[MAXN * MAXN];
sum_t sr[MAXN * MAXN];
int s1[MAXN * MAXN];
int s2[MAXN * MAXN];
int tot, t1, t2, n;
int cmp(const void* p1, const void* p2)
{
	if(*(int*)p1 > *(int*)p2) return 1;
	else return -1;
}
int init()
{
	int i;
	if(scanf("%d", &n) == EOF) return 0;
	for(i = 0;i < n; i++) scanf("%d %d %d %d", a + i, b + i, c + i, d + i);
	return 1;
}
void solve()
{
	long long ans;
	int cnt, i, j, k = 0;
	for(i = 0;i < n; i++)
	{
		for(j = 0;j < n; j++)
		{
			s1[k] = a[i] + b[j];
			s2[k] = -(c[i] + d[j]);
			k++;
		}
	}
	tot = k;
	qsort((void*)s1, tot, sizeof(s1[0]), cmp);
	qsort((void*)s2, tot, sizeof(s2[0]), cmp);
	t1 = 0; i = 0;
	while(i < tot)
	{
		cnt = 1;
		while(s1[i] == s1[i+1] && i + 1 < tot)
		{
			cnt++;
			i++;
		}
		sl[t1].val = s1[i]; sl[t1].cnt = cnt; t1++;
		i++;
	}
	t2 = 0; i = 0;
	while(i < tot)
	{
		cnt = 1;
		while(s2[i] == s2[i+1] && i + 1 < tot)
		{
			cnt++;
			i++;
		}
		sr[t2].val = s2[i]; sr[t2].cnt = cnt; t2++;
		i++;
	}
	ans = 0;
	for(i = 0, j = 0;i < t1 && j < t2;)
	{
		if(sl[i].val > sr[j].val) j++;
		else if(sl[i].val < sr[j].val) i++;
		else {ans += sl[i].cnt * sr[j].cnt; i++; j++;}
	}
	printf("%lld\n", ans);
}
int main()
{
	while(init()) solve();
	return 0;
}
