#include <stdio.h>
#include <string.h>
#define MAX 340
char str[MAX][50], a[50], b[50];
int next[MAX], pre[MAX], cur;
int find(char* key)
{
	int i;
	for(i = 1;i < cur; i++) if(!strcmp(str[i], key)) return i;
	strcpy(str[cur], key);
	return cur++;
}
int main()
{
	int s, t, i, n, u, v;
	scanf("%d", &t);
	for(s = 1;s <= t; s++)
	{
		memset(next, -1, sizeof(next));
		memset(pre, -1, sizeof(pre));
		scanf("%d", &n);
		cur = 1;
		for(i = 1;i < n; i++)
		{
			scanf("%s %s", &a, &b);
			u = find(a);
			v = find(b);
			pre[v] = u;
			next[u] = v;
		}
		printf("Scenario #%d:\n", s);
		for(i = 1;i <= n; i++) if(pre[i] == -1) break;
		while(i != -1)
		{
			printf("%s\n", str[i]);
			i = next[i];
		}
		printf("\n");
	}
	return 0;
}
