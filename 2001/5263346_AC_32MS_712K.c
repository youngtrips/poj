#include <stdio.h>
#include <string.h>
#define MAX 1002
char list[MAX][22];
struct trie_t
{
	int d;
	struct trie_t* next[26];
};
struct trie_t root;
struct trie_t spool[MAX * 20];
int min, p;
void init_node(struct trie_t* t)
{
	int i;
	for(i = 0;i < 26; i++) { t->next[i] = NULL; t->d = 0;}
}
void insert(char* key)
{
	struct trie_t* r = &root;
	int i;
	for(i = 0;key[i] != '\0'; i++)
	{
		if(r->next[key[i] - 'a'] == NULL)
		{
			r->next[key[i] - 'a'] = &spool[p++];
			init_node(r->next[key[i] - 'a']);
		}
		r = r->next[key[i] - 'a'];
		r->d++;
	}
}
void find(char* key, char* pref)
{
	struct trie_t* r = &root;
	int cnt, i, j;
	for(i = 0;key[i] != '\0'; i++)
	{
	    pref[i] = key[i];
	    r = r->next[key[i] - 'a'];
	    if(r->d == 1) break;
	}
	if(i + 1 <= strlen(key)) i++;
	pref[i] = '\0';
}
int main()
{
	int len, n, i, j;
	char pref[22];
	n = 0;
	p = 0;
	init_node(&root);
	min = 999;
	while(scanf("%s", list[n]) != EOF)
	{
	    len = strlen(list[n]);
	    if(min > len) min = len;
	    insert(list[n]);
	    n++;
	}
	for(i = 0;i < n; i++)
	{
	    find(list[i], pref);
	    printf("%s %s\n", list[i], pref);
	}
	return 0;
}
