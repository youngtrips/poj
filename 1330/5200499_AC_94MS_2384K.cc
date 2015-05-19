#include <cstdio>
#include <cstring>
#include <vector>
#define CLS(x) memset(x,0,sizeof(x))
#define MAX 10002
using namespace std;
vector <int> tree[MAX];
vector <int> q[MAX];
int parent[MAX];
int rank[MAX];
int ancestor[MAX];
short color[MAX];
int root[MAX];
void init()
{
	CLS(parent);
	CLS(color);
	CLS(rank);
	CLS(root);
	CLS(tree);
	CLS(q);
}
void make_set(int u)
{
	parent[u] = u;
}
int find_set(int x)
{
	if(x != parent[x]) x = find_set(parent[x]);
	return x;
}
void union_set(int r1, int r2)
{
	int x = find_set(r1);
	int y = find_set(r2);
	if(x == y) return;
	if(rank[x] > rank[y]) parent[y] = x;
	else
	{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
}
void lca(int u)
{
	int i, j;
	make_set(u);
	ancestor[u] = u;
	for(i = 0;i < tree[u].size(); i++)
	{
        lca(tree[u][i]);
        union_set(u, tree[u][i]);
        ancestor[find_set(u)] = u;
	}
	color[u] = 1;
	for(i = 0;i < q[u].size(); i++) if(color[q[u][i]]) printf("%d\n", ancestor[find_set(q[u][i])]);
}
int main()
{
	char ch;
	int i, t, n, u, v;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		init();
		for(i = 1;i < n; i++)
		{
			scanf("%d %d", &u, &v);
			tree[u].push_back(v);
			root[v]++;
		}
		scanf("%d %d", &u, &v);
		q[u].push_back(v);
		q[v].push_back(u);
		for(i = 1;i <= n; i++) if(root[i] == 0) break;
		lca(i);
	}
	return 0;
}
