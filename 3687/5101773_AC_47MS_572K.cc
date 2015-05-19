#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <cstdio>
using namespace std;
#define MAX 202
#define CLS(x) memset(x, 0, sizeof(x))
int adj[MAX][MAX];
void toposort(int n)
{
	priority_queue<int> q;
	int indeg[MAX];
	int r[MAX];
	int cnt = n;
	int i, j, k;
	CLS(indeg);
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++) indeg[i] += adj[i][j];
		if(indeg[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		k = q.top();
		q.pop();
		r[k] = cnt--;
		for(i = 1;i <= n; i++)
		{
			if(adj[i][k] == 1)
			{
				indeg[i]--;
				if(indeg[i] == 0) q.push(i);
			}
		}
	}
	if(cnt != 0) printf("-1\n");
	else
	{
		for(i = 1;i < n; i++) printf("%d ", r[i]);
		printf("%d\n", r[i]);
	}
}

int main()
{
	int t, n, m, i, j;
	scanf("%d", &t);
	while(t--)
	{
		CLS(adj);
		scanf("%d %d", &n, &m);
		while(m--)
		{
			scanf("%d %d", &i, &j);
			adj[i][j] = 1;
		}
		toposort(n);
	}
	return 0;
}
