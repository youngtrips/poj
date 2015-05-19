#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500000
int parent[MAX], rank[MAX], deg[MAX];
struct trie_t
{
	int no;
	struct trie_t* next[26];
};
struct trie_t root;
int tot;
void init()
{
	int i;
	for(i = 0;i < 26; i++) { root.no = -1; root.next[i] = NULL;}
	tot = 0;
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
			r->next[key[i] - 'a'] = (struct trie_t*)malloc(sizeof(struct trie_t));
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
void make_set()
{
	int i;
	for(i = 0;i < MAX; i++) 
	{
		parent[i] = i;
		rank[i] = 0;
		deg[i] = 0;
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
	char a[11], b[12];
	int cnt, i, j;
	make_set();
	init();
	while(scanf("%s %s", a, b) != EOF)
	{
		i = insert(a);
		j = insert(b);
		deg[i]++;
		deg[j]++;
		union_set(i, j);
	}
	cnt = 0;
	for(i = 0;i < tot; i++) if(deg[i] % 2) cnt++;
	if(cnt > 2) printf("Impossible\n");
	else
	{
		j = find_set(0);
		for(i = 1;i < tot; i++) if(find_set(i) != j) {printf("Impossible\n"); return 0;}
		printf("Possible\n");
	}
	return 0;
}
