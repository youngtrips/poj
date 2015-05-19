#include <stdio.h>
#include <string.h>
#define MAXM 100002
#define MAXN 27
typedef struct
{
	int v; int next;
}edge_t;
edge_t e[MAXM * 2];
char visited[MAXN];
int outdeg[MAXN];
int indeg[MAXN];
int first[MAXN];
int tot;
int n;
void add(int u, int v)
{
	e[++tot].v = v; e[tot].next = first[u]; first[u] = tot;
}
void init()
{
	char wd[1002];
	int i, j, m, u, v;
	memset(first, -1, sizeof(first));
	memset(visited, 0, sizeof(visited));
	memset(outdeg, 0, sizeof(outdeg));
	memset(indeg, 0, sizeof(indeg));
	tot = -1;
	n = 0;
	scanf("%d", &m);
	while(m--)
	{
		scanf("%s", wd);
		i = wd[0] - 'a' + 1;
		j = wd[strlen(wd) - 1] - 'a' + 1;
		if(visited[i] == 0) visited[i] = ++n;
		if(visited[j] == 0) visited[j] = ++n;
		u = visited[i];
		v = visited[j];
		add(u, v);
		add(v, u);
		outdeg[u]++;
		indeg[v]++;
	}
}
void dfs(int u)
{
	int v, t;
	visited[u] = 1;
	t = first[u];
	while(t != -1)
	{
		v = e[t].v;
		if(visited[v] == 0) dfs(v);
		t = e[t].next;
	}
}
int check()
{
	int i, x, y, z;
	x = 0;
	y = 0;
	z = 0;
	memset(visited, 0, sizeof(visited));
	dfs(1);
	for(i = 1;i <= n; i++) if(visited[i] == 0) return 0;
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
		if(check()) printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
	}
	return 0;
}
