#include <stdio.h>
#include <string.h>
#define MAX 420
int adj[MAX][MAX], num, stu;
int q[MAX], visited[MAX], pre[MAX], head, tail;
int bfs()
{
	int i, k;
	memset(visited, 0, sizeof(visited));
	memset(pre, -1, sizeof(pre));
	visited[0] = 1;
	pre[0] = -1;
	q[0] = 0;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		k = q[head];
		for(i = 0;i <= num; i++)
		{
			if(adj[k][i] > 0 && visited[i] == 0)
			{
				pre[i] = k;
				if(i == num) return 1;
				visited[i] = 1;
				q[tail++] = i;
			}
		}
		head++;
	}
	return 0;
}
int main()
{
	int res, cnt, t, p, n, m, i, j;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &p, &n);
		memset(adj, 0, sizeof(adj));
		num = p + n + 1;
		stu = n;
		for(i = 1;i <= p; i++)
		{
			scanf("%d", &m);
			while(m--)
			{
				scanf("%d", &j);
				adj[i][j + p] = 1;
				adj[j + p][num] = 1;
			}
			adj[0][i] = 1;
		}
		cnt = 0;
		while(bfs())
		{
			i = num;
			while(pre[i] != -1)
			{
				adj[pre[i]][i]--;
				adj[i][pre[i]]++;
				i = pre[i];
			}
			cnt++;
		}
		if(cnt == stu) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
