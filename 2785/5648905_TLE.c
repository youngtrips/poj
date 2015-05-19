#include <stdio.h>
#include <stdlib.h>
#define MAXN 4005
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int sl[MAXN * MAXN];
int sr[MAXN * MAXN];
int tot, t1, t2, n;
int cmp(const void* p1, const void* p2)
{
	if(*(int*)p1 > *(int*)p2) return 1;
	else return -1;
}
void init()
{
	int i;
	scanf("%d", &n);
	for(i = 0;i < n; i++) scanf("%d %d %d %d", a + i, b + i, c + i, d + i);
}
void solve()
{
	int ans, cnt1, cnt2, i, j, k = 0;
	for(i = 0;i < n; i++)
	{
		for(j = 0;j < n; j++)
		{
			sl[k] = a[i] + b[j];
			sr[k] = -(c[i] + d[j]);
			k++;
		}
	}
	tot = k;
	qsort((void*)sl, tot, sizeof(sl[0]), cmp);
	qsort((void*)sr, tot, sizeof(sr[0]), cmp);
	ans = 0;
	for(i = 0, j = 0;i < tot && j < tot;)
	{
		if(sl[i] > sr[j]) j++;
		else if(sl[i] < sr[j]) i++;
		else
		{
			k = i; cnt1 = 1;
			while(sl[k] == sl[k + 1] && k + 1 < tot)
			{
				cnt1++; k++;
			}
			i = k + 1;
			k = j; cnt2 = 1;
			while(sr[k] == sr[k + 1] && k + 1 < tot)
			{
				cnt2++; k++;
			}
			j = k + 1;
			ans += cnt1 * cnt2;
		}
	}
	printf("%d\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
