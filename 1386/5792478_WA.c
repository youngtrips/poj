#include <stdio.h>
#include <string.h>
#define MAXN 27
char visited[MAXN];
int outdeg[MAXN];
int indeg[MAXN];
int n;
void init()
{
	char wd[1002];
	int i, j, m, u, v;
	memset(visited, 0, sizeof(visited));
	memset(outdeg, 0, sizeof(outdeg));
	memset(indeg, 0, sizeof(indeg));
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
		outdeg[u]++;
		indeg[v]++;
	}
}
int check()
{
	int i, x, y, z;
	x = 0;
	y = 0;
	z = 0;
	for(i = 1;i <= n; i++)
		if(indeg[i] == outdeg[i]) x++;
		else if(indeg[i] == outdeg[i] + 1) y++;
		else if(indeg[i] +1 == outdeg[i]) z++;
	return (x + 2 == n && y == 1 && z == 1);
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
