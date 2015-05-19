#include <stdio.h>
#include <string.h>
#define MAXM 65536
#define MAXN 15002
int lev[MAXN];
int cnt[MAXN];
int a[MAXM * 2];
int n;
void add(int n)
{
	int i = MAXM + n;
	for(++a[i];i > 1; i /= 2) if(~ i & 1) a[i / 2]++;
}
int query(int n)
{
	int cnt = 0, i;
	for(i = MAXM + n;i > 1; i /= 2) if(i & 1) cnt += a[i / 2];
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
