#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100002
#define MAXM 32
#define MAXP 100003
int bits[MAXN][MAXM];
int hash[MAXP];
int n, k;
void to_bits(int x, int p)
{
	int i = k;
	while(x)
	{
		bits[p][i--] = x & 1;
		x >>= 1;
	}
}
void init()
{
	int i, x;
	scanf("%d %d", &n, &k);
	memset(bits, 0, sizeof(bits));
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &x);
		to_bits(x, i);
	}
}
int hashcode(const int *v)
{
	int i, s = 0;
	for(i = 1;i <= k; i++) s=((s<<2)+(v[i]>>4))^(v[i]<<10);
	s = s % MAXP;
	s = s < 0 ? s + MAXP : s;
	return s;
}
void solve()
{
	int ans, tmp, i, j, t;
	memset(hash, -1, sizeof(hash));
	ans = 0;
	for(i = 2;i <= n; i++)
		for(j = 1;j <= k; j++) bits[i][j] += bits[i-1][j];
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j < k; j++) bits[i][j] -= bits[i][k];
		bits[i][k] = 0;
		t = hashcode(bits[i]);
		if(hash[t] == -1) hash[t] = i;
		else
		{
			tmp = i - hash[t] + 1;
			if(ans < tmp) ans = tmp;
			hash[t] = i;
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
