#include <stdio.h>
#define MAX 30002
int parent[MAX];
int rank[MAX];
int n;
void make_set(int n)
{
	int i;
	for(i = 0;i <= n; i++)
	{
		rank[i] = 0;
		parent[i] = i;
	}
}
int find_set(int x)
{
	if(x != parent[x]) parent[x] = find_set(parent[x]);
	return parent[x];
}
void union_set(int r1, int r2)
{
	int x = find_set(r1);
	int y = find_set(r2);
	if(x == y) return;
	if(rank[x] > rank[y]) parent[y] = parent[x];
	else
	{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
}
int main()
{
	int cnt, m, i, j, k;
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;
		make_set(n);
		while(m--)
		{
			scanf("%d", &k);
			scanf("%d", &i);
			k--;
			while(k--)
			{
				scanf("%d", &j);
				union_set(i, j);
			}
		}
		k = find_set(0);
		cnt = 1;
		for(i = 1;i < n; i++) if(parent[i] == k) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
