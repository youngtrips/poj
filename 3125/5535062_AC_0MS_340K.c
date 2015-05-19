#include <stdio.h>
#define MAX 102
int que[MAX * MAX][2];
int head, tail;
int n, p;
void init()
{
	int t;
	scanf("%d %d", &n, &p);
	head = 0;
	for(tail = 0;tail < n; tail++)
	{
		scanf("%d", &t);
		que[tail][0] = t;
		que[tail][1] = tail;
	}
}
void solve()
{
	int flag, ans, u, v, i;
	ans = 0;
	while(head < tail)
	{
		u = que[head][0];
		v = que[head][1];
		flag = 1;
		for(i = head + 1;i < tail; i++)
		{
			if(que[i][0] > u)
			{
				que[tail][0] = u;
				que[tail][1] = v;
				tail++;
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			ans++;
			if(v == p) break;
		}
		head++;
	}
	printf("%d\n", ans);
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
