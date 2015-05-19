#include <stdio.h>
#include <string.h>
#define MAXN 27
char visited[MAXN];
int outdeg[MAXN];
int indeg[MAXN];
int parent[MAXN];
int rank[MAXN];
int n;
void make_set()
{
	int i;
	for(i = 1;i <= 26; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}
/*
int find_set(int x)
{
	if(x != parent[x]) parent[x] = find_set(parent[x]);
	return parent[x];
}
*/
int find_set(int x)
{
	int _b, _x = x;
	while(parent[_x] != _x) _x = parent[_x];
	while(parent[x] != x)
	{
		_b = parent[x];
		parent[x] = _x;
		x = _b;
	}
	return _x;
}
void union_set(int r1, int r2)
{
	int x = find_set(r1);
	int y = find_set(r2);
	if(x == y) return;
	if(rank[x] > rank[y]) parent[y] = x;
	else
	{
		if(rank[x] == rank[y]) rank[y]++;
		parent[x] = y;
	}
}
void init()
{
	char wd[1002];
	int i, j, m, u, v;
	memset(visited, 0, sizeof(visited));
	memset(outdeg, 0, sizeof(outdeg));
	memset(indeg, 0, sizeof(indeg));
	make_set();
	n = 0;
	scanf("%d", &m);
	getchar();
	while(m--)
	{
		gets(wd);
		i = wd[0] - 'a' + 1;
		j = wd[strlen(wd) - 1] - 'a' + 1;
		if(visited[i] == 0) visited[i] = ++n;
		if(visited[j] == 0) visited[j] = ++n;
		u = visited[i];
		v = visited[j];
		union_set(u, v);
		outdeg[u]++;
		indeg[v]++;
	}
}
int check()
{
	int cnt, i, x, y, z;
	cnt = 0;
	x = 0;
	y = 0;
	z = 0;
	for(i = 1;i <= n; i++) if(find_set(i) == i) cnt++;
	if(cnt > 1) return 0;
	for(i = 1;i <= n; i++)
		if(indeg[i] == outdeg[i] && outdeg[i]) x++;
		else if(indeg[i] == outdeg[i] + 1) y++;
		else if(indeg[i] +1 == outdeg[i]) z++;
	return ((x + 2 == n && y == 1 && z == 1) || (x == n && y == 0 && z == 0));
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		if(check()) puts("Ordering is possible.");
		else puts("The door cannot be opened.");
	}
	return 0;
}
