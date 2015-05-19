#include <stdio.h>
#include <string.h>
#define MAX 202
int adj[MAX][MAX], n;
int encode(char* key)
{
	int res = 0, i;
	for(i = 0;key[i] != '\0'; i++) res |= 1 << (key[i] - 'a');
	return res;
}
void decode(int x, char* str)
{
	int t, i, j;
	i = 0; j = 0;
	if(x == 0) {str[0] = '-';str[1] = '\0';}
	else
	{
		while(x > 0)
		{
			t = x & 1;
			if(t == 1) str[j++] = i + 'a';
			x >>= 1;
			i++;
		}
		str[j] = '\0';
	}
}
void floyd()
{
	int i, j, k;
	for(k = 1;k <= n; k++)
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++) 
				adj[i][j] |= (adj[i][k] & adj[k][j]);
}
int main()
{
	char str[32];
	int i, j, k;
	while(1)
	{
		scanf("%d", &n); if(n == 0) break;
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++) adj[i][j] = (i == j ? ~0 : 0);
		while(1)
		{
			scanf("%d %d", &i, &j); if(i == 0 && j == 0) break;
			scanf("%s", str);
			k = encode(str);
			adj[i][j] = k;
		}
		floyd();
		while(1)
		{
			scanf("%d %d", &i, &j); if(i == 0 && j == 0) break;
			decode(adj[i][j], str);
			printf("%s\n", str);
		}
		printf("\n");
	}
	return 0;
}
