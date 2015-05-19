#include <stdio.h>
#include <string.h>
#define myabs(x) ((x)<0?-(x):(x))
#define MAX 502
int adj[MAX][MAX], match[MAX], v[MAX], n;
typedef struct
{
	char t[10];
	int dt;
}list_t;
typedef struct
{
	int h;
	int m;
}time;
list_t list[MAX];
void add_time(time* t, int min)
{
	t->m += min;
	t->h += t->m / 60;
	t->m %= 60;
}
void s2time(char* str, time* t)
{
	int h, m;
	sscanf(str, "%d:%d", &h, &m);
	t->h = h; t->m = m;
}
int cmp_time(time a, time b)
{
	if(a.h == b.h) return a.m < b.m;
	return a.h < b.h;
}
void init()
{
	int i, j, a, b, c, d;
	time t1, t2;
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
	{
		scanf("%s %d %d %d %d", list[i].t, &a, &b, &c, &d);
		list[i].dt = myabs(a - c) + myabs(b - d);
	}
	memset(adj, 0, sizeof(adj));
	for(i = 1;i <= n; i++)
	{
		for(j = i + 1;j <= n; j++)
		{
			s2time(list[i].t, &t1);
			add_time(&t1, list[i].dt);
			s2time(list[j].t, &t2);
			adj[i][j] = cmp_time(t1, t2);
		}
	}
}
int find(int i)
{
	int j;
	for(j = 1;j <= n; j++)
	{
		if(adj[i][j] && v[j] == 0)
		{
			v[j] = 1;
			if(match[j] == -1 || find(match[j]))
			{
				match[j] = i;
				return 1;
			}
		}
	}
	return 0;
}
int hungary()
{
	int cnt = 0, i;
	memset(match, -1, sizeof(match));
	for(i = 1;i <= n; i++)
	{
		memset(v, 0, sizeof(v));
		cnt += find(i);
	}
	return cnt;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		printf("%d\n", n - hungary());
	}
	return 0;
}
