#include <stdio.h>
#include <string.h>
#define oo 2000000000
#define MAXM 1000002
#define MAXN 1002
typedef struct
{
	int v;
	int w;
	int next;
}edge_t;
edge_t e[MAXM];
int first[MAXN];
int que[MAXN * 2];
int dis[MAXN];
int has[MAXN];
int cnt[MAXN];
int head, tail;
int tot, n;
void add(int u, int v, int w)
{
	e[++tot].v = v; e[tot].w = w; e[tot].next = first[u]; first[u] = tot;
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void init()
{
	int ml, md, i, j, k;
	scanf("%d %d %d", &n, &ml, &md);
	memset(first, -1, sizeof(first));
	tot = -1;
	while(ml--)
	{
		scanf("%d %d %d", &i, &j, &k);
		if(i > j) swap(&i, &j);
		add(i, j, k);
	}
	while(md--)
	{
		scanf("%d %d %d", &i, &j, &k);
		if(i > j) swap(&i, &j);
		add(j, i, -k);
	}
	for(i = 1;i < n; i++) add(i + 1, i, 0);
}
int spfa()
{
	int i, j, t;
	memset(has, 0, sizeof(has));
	memset(cnt, 0, sizeof(cnt));
	for(i = 1;i <= n; i++) dis[i] = oo;
	dis[1] = 0; has[1] = 0;
	que[0] = 1; cnt[1] = 1;
	head = 0; tail = 1;
	while(head < tail)
	{
		i = que[head];
		has[i] = 0;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(dis[i] + e[t].w < dis[j])
			{
				dis[j] = dis[i] + e[t].w;
				if(has[j] == 0)
				{
					que[tail++] = j;
					cnt[j]++;
					if(cnt[j] > n) return 0;
					has[j] = 1;
				}
			}
			t = e[t].next;
		}
		head++;
	}
	return 1;
}
int main()
{
	int res;
	init();
	res = spfa();
	if(res == 0) printf("-1\n");
	else printf("%d\n", dis[n] == oo ? -2 : dis[n]);
	return 0;
}
