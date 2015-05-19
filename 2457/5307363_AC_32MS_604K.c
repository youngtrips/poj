#include <stdio.h>
#include <string.h>
#define MAXM 50002
#define MAXN 1002
struct edge_t
{
	int v;
	struct edge_t* next;
};
struct edge_t e[MAXM];
struct edge_t list[MAXN];
struct edge_t* p;
int q[MAXM], head, tail, n;
int dis[MAXN], pre[MAXN];
void insert(int u, int v)
{
	struct edge_t* cur = p++;
	cur->next = list[u].next;
	cur->v = v;
	list[u].next = cur;
}
void init()
{
	int m, i, j;
	scanf("%d %d", &m, &n);
	for(i = 1;i <= n; i++) list[i].next = NULL;
	p = e;
	while(m--)
	{
		scanf("%d %d", &i, &j);
		insert(i, j);
	}
	memset(dis, -1, sizeof(dis));
	memset(pre, -1, sizeof(pre));
	dis[1] = 1;
	q[0] = 1;
	head = 0; tail = 1;
}
int bfs()
{
	struct edge_t* cur;
	int k, i, j;
	while(head < tail)
	{
		i = q[head];
		k = dis[i];
		cur = list[i].next;
		while(cur != NULL)
		{
			j = cur->v;
			if(dis[j] == -1)
			{
				dis[j] = k + 1;
				pre[j] = i;
				if(j == n) return dis[j];
				q[tail++] = j;
			}
			cur = cur->next;
		}
		head++;
	}
	return -1;
}
int main()
{
	int res, i, j;
	init();
	res = bfs();
	printf("%d\n", res);
	if(res != -1)
	{
		i = n;
		j = 0;
		q[++j] = n;
		while(pre[i] != -1)
		{
			q[++j] = pre[i];
			i = pre[i];
		}
		for(i = j;i >= 1; i--) printf("%d\n", q[i]);
	}
	return 0;
}
