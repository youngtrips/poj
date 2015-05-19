#include <stdio.h>
#define eps 1e-20
#define oo 999999999999.999f
#define MAX 5002
double adj[MAX][MAX], key[MAX];
int has[MAX], n;
struct trie_t
{
	int no;
	struct trie_t* next[26];
};
struct trie_t spool[MAX * 22];
struct trie_t root;
int tot, p;
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
double prim()
{
	double res = 0.0, min;
	int i, j, k;
	for(i = 1;i <= n; i++)
	{
		key[i] = adj[1][i];
		has[i] = 0;
	}
	has[1] = 1;
	for(i = 1;i < n; i++)
	{
		min = oo;
		k = 1;
		for(j = 1;j <= n; j++)
			if(has[j] == 0 && min > key[j] + eps)
			{
				min = key[j];
				k = j;
			}
		has[k] = 1;
		res += min;
		for(j = 1;j <= n; j++) if(key[j] > adj[k][j] + eps) key[j] = adj[k][j];
	}
	return res;
}
void tolow(char* str)
{
	int i;
	for(i = 0;str[i] != '\0'; i++)
		if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
}
int main()
{
	char a[22], b[22];
	double l, c;
	int i, j, m;
	scanf("%lf", &l);
	scanf("%d", &n);
	init_trie();
	for(i = 1;i <= n; i++)
	{
		scanf("%s", a);
		tolow(a);
		insert(a);
	}
	for(i = 1;i <= n; i++) 
		for(j = 1;j <= n; j++) adj[i][j] = oo;
	scanf("%d", &m);
	while(m--)
	{
		scanf("%s %s %lf", a, b, &c);
		tolow(a);
		tolow(b);
		i = insert(a);
		j = insert(b);
		adj[i][j] = c;
		adj[j][i] = c;
	}
	c = prim();
	if(l + eps < c) printf("Not enough cable\n");
	else printf("Need %0.1f miles of cable\n", c);
	return 0;
}
