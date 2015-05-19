#include <stdio.h>
#include <string.h>
#define MAXM 1000002
#define MAXN 100002
#define MAXP 997001
int list[MAXN][32];
int has[MAXM];
int n, k;
int hash(int* v)
{
	int flag, i, p, j;
	for(p = 0, i = 0;i < k; i++)
		p = ((p<<2)+(v[i]>>4))^(v[i]<<10);
	p %= MAXP;
	if(p < 0) p += MAXP;
	for(flag = 0;!flag && has[p] != -1; p++)
		for(j = has[p], flag = 1, i = 0; flag && i < k; i++)
			flag = (v[i] == list[j][i]);
	if(flag) p--;
	return p;
}
int main()
{
	int ans, tmp, a, i, j, t, p, q;
	scanf("%d %d", &n, &k);
	memset(list, 0, sizeof(list));
	memset(has, -1, sizeof(has));
	has[hash(list[0])] = 0;
	ans = 0;
	k--;
	for(i = 1, p = 0;i <= n; i++, p++)
	{
		scanf("%d", &a);
		for(t = a % 2, a >>= 1, j = 0;j < k; j++, a >>= 1)
			list[i][j] = list[p][j] + (a % 2) - t;
		q = hash(list[i]);
		if(has[q] == -1) has[q] = i;
		tmp = i - has[q];
		if(tmp > ans) ans = tmp;
	}
	printf("%d\n", ans);
	return 0;
}
