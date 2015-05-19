#include <stdio.h>
#include <string.h>
#define MAXM 100002
#define MAXN 50002
typedef struct
{
	int v; int next;
}edge_t;
typedef struct
{
	int que[MAXN + MAXN]; int head; int tail;
}queue_t;
edge_t deps[MAXM + MAXM];
queue_t dvd[2];
int first[MAXN + MAXN];
int pre[MAXN + MAXN];
int tmp[MAXN + MAXN];
int tot, n1, n2, n;
void add(int u, int v)
{
	deps[++tot].v = v; deps[tot].next = first[u]; first[u] = tot;
}
int init()
{
	int d, x, y;
	scanf("%d %d %d", &n1, &n2, &d);
	if(n1 == 0 && n2 == 0 && d == 0) return 0;
	memset(first, -1, sizeof(first));
	memset(pre, 0, sizeof(pre));
	while(d--)
	{
		scanf("%d %d", &x, &y);
		add(y, x);
		pre[x]++;
	}
	n = n1 + n2;
	return 1;
}
void init_que(queue_t* q) { q->head = 0; q->tail = 0;}
int bfs(int cur)
{
	int cnt, i, j, t;
	init_que(&dvd[0]);
	init_que(&dvd[1]);
	for(i = 1;i <= n; i++)
	{
		if(pre[i] == 0) dvd[i > n1 ? 1 : 0].que[dvd[i > n1 ? 1 : 0].tail++] = i; 
		tmp[i] = pre[i];
	}
	cnt = 1;
	while(dvd[0].head < dvd[0].tail || dvd[1].head < dvd[1].tail)
	{
		while(dvd[cur].head < dvd[cur].tail)
		{
			i = dvd[cur].que[dvd[cur].head++];
			t = first[i];
			while(t != -1)
			{
				j = deps[t].v;
				if(--tmp[j] == 0) dvd[j > n1 ? 1 : 0].que[dvd[j > n1 ? 1 : 0].tail++] = j;
				t = deps[t].next;
			}
		}
		cnt++;
		cur ^= 1;
	}
	return cnt;
}
int main()
{
	int a, b;
	while(init())
	{
		a = bfs(0);
		b = bfs(1);
		printf("%d\n", a < b ? a : b);
	}
	return 0;
}
