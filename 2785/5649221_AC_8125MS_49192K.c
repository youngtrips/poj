#include <stdio.h>
#include <stdlib.h>
#define MAXN 4000
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int sl[MAXN * MAXN];
int sr[MAXN * MAXN];
int tot, n;
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
int bs(int key)
{
	int high = tot;
	int low  = 0;
	int mid, cnt, i;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(sr[mid] > key) high = mid - 1;
		else if(sr[mid] < key)  low = mid + 1;
		else
		{
			i = mid; cnt = 1;
			while(sr[i] == sr[i-1] && i-1 >= 0) {cnt++; i--;}
			i = mid;
			while(sr[i] == sr[i+1] && i+1 < tot) { cnt++; i++;}
			return cnt;
		}
	}
	return 0;
}
void solve()
{
	int ans, i, j, k = 0;
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
	qsort((void*)sr, tot, sizeof(sr[0]), cmp);
	ans = 0;
	for(i = 0;i < tot; i++) ans += bs(sl[i]);
	printf("%d\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
