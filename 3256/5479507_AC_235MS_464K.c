#include <stdio.h>
#include <string.h>
#define MAXM 10002
#define MAXN 1002
typedef struct
{
	int u;
	int v;
	int next;
}edge_t;
edge_t e[MAXM];
int first[MAXN];
int flag[MAXN];
int q[MAXN];
int has[MAXN];
int head;
int tail;
int tot;
int n;
int m;
int k;
void add(int u, int v)
{
	e[++tot].u = u; e[tot].v = v; e[tot].next = first[u];
	first[u] = tot;
}
void init()
{
	int i, j;
	scanf("%d %d %d", &k, &n, &m);
	memset(first, -1, sizeof(first));
	memset(flag, 0, sizeof(flag));
	for(i = 0;i < k; i++)
	{
		scanf("%d", &j);
		flag[j]++;
	}
	tot = 0;
	while(m--)
	{
		scanf("%d %d", &i, &j);
		add(j, i);
	}
}
int bfs(int st)
{
	int cnt, i, j, t;
	memset(has, 0, sizeof(has));
	has[st] = 1;
	q[0] = st;
	head = 0;
	tail = 1;
	cnt = 0;
	while(head < tail)
	{
		i = q[head];
		cnt += flag[i];
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(has[j] == 0)
			{
				q[tail++] = j;
				has[j] = 1;
			}
			t = e[t].next;
		}
		head++;
	}
	return cnt;
}
void solve()
{
	int cnt;
	int res;
	int i;
	cnt = 0;
	for(i = 1;i <= n; i++)
	{
		res = bfs(i);
		if(res == k) cnt++;
	}
	printf("%d\n", cnt);
}
int main()
{
	init();
	solve();
	return 0;
}
