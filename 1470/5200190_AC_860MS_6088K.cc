#include <cstdio>
#include <cstring>
#include <vector>
#define CLS(x) memset(x,0,sizeof(x))
#define MAX 902
using namespace std;
vector <int> tree[MAX];
vector <int> q[MAX];
int parent[MAX];
int rank[MAX];
int ancestor[MAX];
short color[MAX];
int root[MAX];
int num[MAX];
void init()
{
	CLS(parent);
	CLS(color);
	CLS(rank);
	CLS(root);
	CLS(tree);
	CLS(num);
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
	for(i = 0;i < q[u].size(); i++) if(color[q[u][i]]) num[ancestor[find_set(q[u][i])]]++;
}
int main()
{
	char ch;
	int i, j, k, c = 1, n, m;
	while(scanf("%d", &n) != EOF)
	{
		init();
		for(k = 0;k < n; k++)
		{
			scanf("%d", &i);
			while(getchar() != '(');
			scanf("%d", &m);
			while(getchar() != ')');
			while(m--)
			{
				scanf("%d", &j);
				tree[i].push_back(j);
				root[j]++;
			}
		}
		scanf("%d", &m);
		for(k = 0;k < m; k++)
		{
			while(getchar() != '(');
			scanf("%d", &i);
			scanf("%d", &j);
			q[i].push_back(j);
			q[j].push_back(i);
			while(getchar() != ')');
		}
		for(i = 1;i <= n; i++) if(root[i] == 0) break;
		lca(i);
		for(i = 1;i <= n; i++) if(num[i] > 0) printf("%d:%d\n", i, num[i]);
	}
	return 0;
}
