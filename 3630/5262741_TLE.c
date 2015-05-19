#include <stdio.h>
#include <string.h>
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
int cmp(const void* p1, const void* p2)
{
	int l1 = strlen((char*)p1);
	int l2 = strlen((char*)p2);
	if(l1 == l2) return strcmp((char*)p1, (char*)p2);
	return l2 - l1;
}
void init_node(struct trie_t* t)
{
	int i;
	for(i = 0;i < 10; i++) t->next[i] = NULL;
}
int insert(char* key)
{
	struct trie_t* r = &root;
	int cnt = 1, i;
	for(i = 0;key[i] != '\0'; i++)
	{
		if(r->next[key[i] - '0'] == NULL)
		{
			r->next[key[i] - '0'] = (struct trie_t*)malloc(sizeof(struct trie_t));
			init_node(r->next[key[i] - '0']);
			cnt = 0;
		}
		r = r->next[key[i] - '0'];
	}
	return cnt;
}
int main()
{
	int t, n, i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		init_node(&root);
		for(i = 0;i < n; i++) scanf("%s", tel[i]);
		qsort((void*)tel, n, sizeof(tel[0]), cmp);
		flag = 1;
		for(i = 0;i < n; i++) if(insert(tel[i])) {flag = 0; break;}
		printf("%s\n", ans[flag]);
	}
	return 0;
}
