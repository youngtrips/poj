#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
#define MAX 201
#define CLS(x) memset(x, 0, sizeof(x))
int adj[MAX][MAX];
void toposort(int n)
{
	priority_queue<int> q;
	int indeg[MAX];
	int r[MAX];
	int cnt = 0;
	int i, j, k;
	CLS(indeg);
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++) indeg[i] += adj[j][i];
		if(indeg[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		k = q.top();
		q.pop();
		r[cnt++] = k;
		for(i = 1;i <= n; i++)
		{
			if(adj[k][i] == 1)
			{
				indeg[i]--;
				if(indeg[i] == 0) q.push(i);
			}
		}
	}
	if(cnt < n) printf("-1\n");
	else
	{
		for(i = cnt - 1;i >= 1; i--) printf("%d ", r[i]);
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
			adj[j][i] = 1;
		}
		toposort(n);
	}
	return 0;
}
