#include <stdio.h>
#include <string.h>
#define MAXM 32768
#define MAXN 15002
int lev[MAXN];
int cnt[MAXM];
int a[MAXM * 2];
int n;
void add(int n)
{
	int i = MAXM + n;
	for(++a[i];i > 1; i /= 2) if(~ i & 1) a[i / 2]++;
}
int query(int n)
{
	int cnt, i;
	for(i = MAXM + n, cnt = 0;i > 1; i /= 2) if(i & 1) cnt += a[i / 2];
	return cnt;
}
int main()
{
	int res;
	int i, x, y;
	scanf("%d", &n);
	memset(cnt, 0, sizeof(cnt));
	memset(lev, 0, sizeof(lev));
	memset(a, 0, sizeof(a));
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		lev[query(x) + cnt[x]]++;
		add(x);
		cnt[x]++;
	}
	for(i = 0;i < n; i++) printf("%d\n", lev[i]);
	return 0;
}
