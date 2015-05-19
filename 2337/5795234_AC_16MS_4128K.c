#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXE 1002
#define MAXW 1002
#define MAXN 27
typedef struct
{
	int v;
	int p;
	int next;
}edge_t;
edge_t e[MAXE];
char list[MAXW][22];
char visited[MAXE];
int parent[MAXN];
int rank[MAXN];
int first[MAXN];
int outdeg[MAXN];
int indeg[MAXN];
int stack[MAXE];
int ar[MAXN];
int top;
int tot;
int cnt;
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
int find_set(int x) { if(x != parent[x]) parent[x] = find_set(parent[x]); return parent[x];}
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
void add(int u, int v, int p)
{
	e[++tot].v = v; e[tot].p = p; e[tot].next = first[u]; first[u] = tot;
}
int cmp(const void* p1, const void* p2)
{
	return strcmp((char*)p1, (char*)p2);
}
void init()
{
	int i, j, k, u, v;
	scanf("%d", &n); getchar();
	memset(visited, 0, sizeof(visited));
	memset(outdeg, 0, sizeof(outdeg));
	memset(indeg, 0, sizeof(indeg));
	memset(first, -1, sizeof(first));
	memset(ar, 0, sizeof(ar));
	tot = -1; cnt = 0;
	for(i = 1;i <= n; i++) gets(list[i]);
	qsort((void*)&list[1], n, sizeof(list[1]), cmp);
	make_set();
	for(i = 1;i <= n; i++)
	{
		j = list[i][0] - 'a' + 1;
		k = list[i][strlen(list[i]) - 1] - 'a' + 1;
		if(visited[j] == 0) visited[j] = ++cnt;
		if(visited[k] == 0) visited[k] = ++cnt;
		u = visited[j];
		v = visited[k];
		add(u, v, i);
		union_set(u, v);
		outdeg[u]++;
		indeg[v]++;
		ar[u]--; ar[v]++;
	}
}
int check()
{
	int i, x, y, z;
	x = 0;
	for(i = 1;i <= cnt; i++) if(find_set(i) == i) x++;
	if(x > 1) return 0;
	x = 0; y = 0; z = 0;
	for(i = 1;i <= cnt; i++)
		if(indeg[i] == outdeg[i]) x++;
		else if(indeg[i] == outdeg[i] + 1) y++;
		else if(indeg[i] + 1 == outdeg[i]) z++;
	return ((x + 2 == cnt && y == 1 && z == 1) || (x == cnt && y == 0 && z == 0));
}
void find_euler_path(int u)
{
	int link[MAXE];
	int t, v, p, i;
	t = first[u];
	i = 0;
	while(t != -1)
	{
		link[++i] = t;
		t = e[t].next;
	}
	while(i > 0)
	{
		t = link[i];
		v = e[t].v;
		p = e[t].p;
		if(visited[p] == 0)
		{
			visited[p] = 1;
			find_euler_path(v);
			stack[++top] = p;
		}
		i--;
	}
}
void solve()
{
	int i;
	memset(visited, 0, sizeof(visited));
	top = 0;
	for(i = 1;i <= cnt && ar[i] >= 0; i++);
	if(i > cnt) i = 1;
	find_euler_path(i);
	while(top > 1) printf("%s.", list[stack[top--]]);
	printf("%s\n", list[stack[1]]);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		if(check() == 0)
		{
			printf("***\n");
			continue;
		}
		solve();
	}
	return 0;
}
