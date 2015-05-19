#include <stdio.h>
#include <string.h>
#define MAXN 302
#define MAXM 18
int adj[MAXM][MAXN];
int stack[MAXN];
int found;
int top;
int m, n;
int init()
{
	int i, j;
	if(scanf("%d %d", &m, &n) == EOF) return 0;
	for(i = 1;i <= m; i++)
	{
		adj[i][0] = 0;
		for(j = 1;j <= n; j++) 
		{
			scanf("%d", &adj[i][j]);
			adj[i][0] += adj[i][j];
		}
	}
	return 1;
}
void check()
{
	int tmp, i, j;
	for(j = 1;j <= n; j++)
	{
		tmp = 0;
		for(i = 0;i <= top; i++) tmp += adj[stack[i]][j];
		if(tmp != 1) return;
	}
	found = 1;
}
void dfs(int i, int tot)
{
	if(found) return;
	if(tot == n) check();
	if(i >= m) return;
	stack[++top] = i + 1;
	dfs(i + 1, tot + adj[i + 1][0]);
	top--;
	dfs(i + 1, tot);
}
int main()
{
	while(init())
	{
		found = 0;
		top = -1;
		dfs(1, 0);
		top = -1;
		stack[++top] = 1;
		dfs(1, adj[1][0]);
		if(found) printf("Yes, I found it\n");
		else printf("It is impossible\n");
	}
	return 0;
}
