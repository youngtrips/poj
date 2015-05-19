#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define eps 1e-20
#define MAX 102
struct trie_t
{
	int no;
	struct trie_t* next[26];
};
struct trie_t spool[MAX * MAX];
struct trie_t root;
double adj[MAX][MAX];
int tot, p, n;
void init_trie()
{
	int i;
	for(i = 0;i < 26; i++) { root.no = -1; root.next[i] = NULL;}
	tot = 1;
	p = 0;
}
int insert(char* key)
{
	int i, j;
	struct trie_t* r = &root;
	struct trie_t* t;
	for(i = 0; key[i] != '\0'; i++)
	{
		if(r->next[key[i] - 'a'] == NULL)
		{
			r->next[key[i] - 'a'] = &spool[p++];
			t = r->next[key[i] - 'a'];
			for(j = 0;j < 26; j++)
			{
				t->no = -1;
				t->next[j] = NULL;
			}
		}
		r = r->next[key[i] - 'a'];
	}
	if(r->no == -1) r->no = tot++;
	return r->no;
}
void tolow(char* str)
{
	int i;
	for(i = 0;str[i] != '\0'; i++) 
		if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
}
int init()
{
	char a[MAX], b[MAX];
	double c;
	int i, j;
	scanf("%d", &n);
	if(n == 0) return 0;
	for(i = 1;i <= n; i++) 
		for(j = 1;j <= n; j++) adj[i][j] = (i == j ? 1.0 : 0.0);
	init_trie();
	for(i = 1;i <= n; i++)
	{
		scanf("%s", a);
		tolow(a);
	}
	scanf("%d", &j);
	for(i = 1;i <= j; i++)
	{
		scanf("%s %lf %s", a, &c, b);
		tolow(a);
		tolow(b);
		adj[insert(a)][insert(b)] = c;
	}
	return 1;
}
void debug()
{
	int i, j;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++) printf("%lf ", adj[i][j]);
		printf("\n");
	}
	printf("\n");
}
void floyd()
{
	int i, j, k;
	for(k = 1;k <= n; k++)
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++)
				if(adj[i][j] + eps < adj[i][k] * adj[k][j]) adj[i][j] = adj[i][k] * adj[k][j];
}
int main()
{
	int flag, i, j, t;
	t = 1;
	while(init())
	{
		floyd();
		flag = 0;
		for(i = 1;i <= n; i++)
			if(1.0 + eps < adj[i][i]) {flag = 1; break;}
		printf("Case %d: ", t++);
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
