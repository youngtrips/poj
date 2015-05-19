#include <stdio.h>
#include <stdlib.h>
#define MAX 10002
char ans[2][4] = {"NO", "YES"};
char tel[MAX][11];
struct trie_t
{
	int d;
	struct trie_t* next[10];
};
struct trie_t root;
void init_node(struct trie_t* t)
{
	int i;
	for(i = 0;i < 10; i++) { t->next[i] = NULL; t->d = 0;}
}
int insert(char* key)
{
	struct trie_t* r = &root;
	int cnt = 0, i;
	for(i = 0;key[i] != '\0'; i++)
	{
		if(r->d == 1) return 0;
		if(r->next[key[i] - '0'] == NULL)
		{
			r->next[key[i] - '0'] = (struct trie_t*)malloc(sizeof(struct trie_t));
			init_node(r->next[key[i] - '0']);
			cnt++;
		}
		r = r->next[key[i] - '0'];
	}
	r->d = 1;
	return 1;
}
int main()
{
	int flag, t, n, i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		init_node(&root);
		flag = 1;
		for(i = 0;i < n; i++) 
		{
			scanf("%s", tel[i]);
			if(flag) flag = insert(tel[i]);
		}
		printf("%s\n", ans[flag]);
	}
	return 0;
}
