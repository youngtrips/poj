#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5000
typedef struct
{
	int val;
	int pre;
}path_t;
path_t path[MAX];
int x[10], n, m;
int visited[MAX];
int q[MAX], head, tail;
int cmp(const void* p1, const void* p2){ return *(int*)p1 - *(int*)p2;}
int bfs()
{
	int tmp, mod, cur, i;
	while(head < tail)
	{
		cur = q[head];
		for(i = 0;i < m; i++)
		{
			tmp = cur * 10 + x[i];
			mod = tmp %  n;
			if(visited[mod] == 0)
			{
				visited[mod] = 1;
				path[mod].pre = cur;
				path[mod].val = x[i];
				if(mod == 0) return 1;
				q[tail++] = mod;
			}
		}
		head++;
	}
	return 0;
}
int main()
{
	int f, t, i, j;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d", &m);
		for(i = 0;i < m; i++) scanf("%d", x + i);
		if(n == 0) { printf("0\n"); continue;}
		qsort((void*)x, m, sizeof(x[0]), cmp);
		memset(visited, 0, sizeof(visited));
		memset(path, -1, sizeof(path));
		head = 0; tail = 0;
		f = 0;
		for(i = 0;i < m; i++)
		{
			if(x[i] != 0)
			{
				t = x[i] % n;
				if(t == 0){ f = x[i]; break;}
				q[tail++] = t;
				visited[t] = 1;
				path[t].val = x[i];
				path[t].pre = -1;
			}
		}
		if(f) {printf("%d\n"); continue;}
		if(bfs() == 0) printf("0\n");
		else
		{
			i = 0; j = 0;
			while(path[i].pre != -1)
			{
				q[j++] = path[i].val;
				i = path[i].pre;
			}
			q[j++] = path[i].val;
			for(i = j - 1;i >= 0; i--) printf("%d", q[i]);
			printf("\n");
		}
	}
	return 0;
}
