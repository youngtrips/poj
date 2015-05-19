#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024
struct ans_t { int r; int c; int d; };
struct trie_t
{
	int no;
	struct trie_t* next[26];
};
struct trie_t spool[MAX * MAX * 5];
struct trie_t root;
struct trie_t* ptr;
struct ans_t ans[MAX];
char map[MAX][MAX];
int found[MAX];
int dx[8] = {-1, -1, 0, 1, 1,  1,  0, -1};
int dy[8] = { 0,  1, 1, 1, 0, -1, -1, -1};
int cnt, tot, l, c, w;
void init_trie()
{
	int i;
	for(i = 0;i < 26; i++) {root.next[i] = NULL; root.no = -1;}
	ptr = spool;
	cnt = 0;
}
void insert(char* key)
{
	struct trie_t* r = &root;
	struct trie_t* t;
	int i, j;
	for(i = 0;key[i] != '\0'; i++)
	{
		if(r->next[key[i] - 'A'] == NULL)
		{
			/*
			r->next[key[i] - 'A'] = (struct trie_t*)malloc(sizeof(struct trie_t));
			*/
			r->next[key[i] - 'A'] = ptr++;
			t = r->next[key[i] - 'A'];
			for(j = 0;j < 26; j++) { t->no = -1; t->next[j] = NULL;}
		}
		r = r->next[key[i] - 'A'];
	}
	r->no = ++cnt;
}
void init()
{
	char str[MAX];
	int i, j;
	scanf("%d %d %d", &l, &c, &w);
	getchar();
	for(i = 0;i < l; i++) scanf("%s", map[i]);
	for(i = 1;i <= w; i++)
	{
		scanf("%s", str);
		insert(str);
	}
	memset(found, 0, sizeof(found));
	tot = w;
}
void check(int x, int y, int d)
{
	struct trie_t* r = &root;
	char ch;
	int tx, ty, i, j;
	tx = x; ty = y;
	while(x >= 0 && x < l && y >= 0 && y < c)
	{
		ch = map[x][y];
		if(r->no > -1 && found[r->no] == 0)
		{
			found[r->no] = 1;
			ans[r->no].r = tx;
			ans[r->no].c = ty;
			ans[r->no].d = d;
			tot--;
			if(tot == 0) return;
		}
		if(r->next[ch - 'A'] == NULL) return;
		r = r->next[ch - 'A'];
		x += dx[d];
		y += dy[d];
	}
	if(r->no > -1 && found[r->no] == 0)
	{
		found[r->no] = 1;
		ans[r->no].r = tx;
		ans[r->no].c = ty;
		ans[r->no].d = d;
		tot--;
	}
}
void search()
{
	int res, i, j, k;
	for(i = 0;i < l; i++)
	{
		for(j = 0;j < c; j++)
		{
			for(k = 0;k < 8; k++)
			{
				check(i, j, k);
				if(tot == 0) return;
			}
		}
	}
}
int main()
{
	int i;
	init_trie();
	init();
	search();
	for(i = 1;i <= w; i++) printf("%d %d %c\n", ans[i].r, ans[i].c, ans[i].d + 'A');
	return 0;
}
