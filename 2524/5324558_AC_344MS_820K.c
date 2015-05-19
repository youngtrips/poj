#include <stdio.h>
#include <string.h>
#define MAX 50002
int parent[MAX], rank[MAX];
int n;
void make_set(int n)
{
	int i;
	for(i = 0;i <= n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
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
	if(rank[x] > rank[y]) parent[y] = x;
	else 
	{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
}
int main()
{
	int m, i, j, s = 1;
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;
		make_set(n);
		while(m--)
		{
			scanf("%d %d", &i, &j);
			union_set(i, j);
		}
		m = 0;
		for(i = 1;i <= n; i++) if(find_set(i) == i) m++;
		printf("Case %d: %d\n", s++, m);
	}
	return 0;
}
