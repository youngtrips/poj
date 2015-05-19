#include <stdio.h>
#define MAXN 20002
int d[MAXN];
int k[MAXN];
int n, m;
int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}
int init()
{
	int i;
	scanf("%d %d", &n, &m);
	if(n == 0 && m == 0) return 0;
	for(i = 1;i <= n; i++) scanf("%d", d + i);
	for(i = 1;i <= m; i++) scanf("%d", k + i);
	return 1;
}
void solve()
{
	int ans, tmp, i, j;
	qsort((void*)&d[1], n, sizeof(d[1]), cmp);
	qsort((void*)&k[1], m, sizeof(k[1]), cmp);
	ans = 0;
	for(i = 1, j = 1;i <= n; i++)
	{
		while(k[j] < d[i] && j <= m) j++;
		if(j > m) { ans = -1; break;}
		ans += k[j++];
	}
	if(ans == -1) printf("Loowater is doomed!\n");
	else printf("%d\n", ans);
}
int main()
{
	while(init()) solve();
	return 0;
}
