#include <stdio.h>
#include <stdlib.h>
#define MAX 10002
char ans[2][4] = {"NO", "YES"};
char tel[MAX][11];
struct trie_t
{
	struct trie_t* next[10];
};
struct trie_t root;
int flag;
void init_node(struct trie_t* t)
{
	int i;
	for(i = 0;i < 10; i++) t->next[i] = NULL;
}
void insert(char* key)
{
	struct trie_t* r = &root;
	int cnt, i;
	for(i = 0;key[i] != '\0'; i++)
	{
		if(r->next[key[i] - '0'] == NULL)
		{
			r->next[key[i] - '0'] = (struct trie_t*)malloc(sizeof(struct trie_t));
			init_node(r->next[key[i] - '0']);
		}
		r = r->next[key[i] - '0'];
	}
}
int find(char* key)
{
	struct trie_t* r = &root;
	int i;
	for(i = 0;key[i] != '\0'; i++) r = r->next[key[i] - '0'];
	for(i = 0;i < 10; i++) if(r->next[i] != NULL) return 0;
	return 1;
}
int main()
{
	int t, n, i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		init_node(&root);
		for(i = 0;i < n; i++)
		{
			scanf("%s", tel[i]);
			insert(tel[i]);
		}
		flag = 1;
		for(i = 0;i < n; i++) if(find(tel[i]) == 0){flag = 0; break;}
		printf("%s\n", ans[flag]);
	}
	return 0;
}
