#include <stdio.h>
#include <string.h>
#define MAXN 10002
int que[2][MAXN];
int head[2];
int tail[2];
int l, n;
void init()
{
	char str[6];
	int x;
	int i;
	head[0] = head[1] = 0;
	tail[0] = tail[1] = 0;
	scanf("%d %d", &l, &n);
	for(i = 1;i <= n; i++)
	{
		scanf("%d %s", &x, str);
		if(!strcmp(str, "left")) que[0][tail[0]++] = x;
		else que[1][tail[1]++] = x;
	}
	l *= 100;
}
void solve()
{
	int cnt, i, k;
	cnt = 0; i = 0;
	while(head[0] < tail[0] || head[1] < tail[1])
	{
		k = l;
		while(k - que[i][head[i]] >= 0 && head[i] < tail[i])
		{
			k -= que[i][head[i]];
			head[i]++;
		}
		cnt++;
		i ^= 1;
	}
	printf("%d\n", cnt);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		solve();
	}
	return 0;
}
