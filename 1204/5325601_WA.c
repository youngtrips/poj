#include <stdio.h>
#include <string.h>
#define MAX 1002
struct ans_t
{
	int r;
	int c;
	int d;
};
struct trie_t
{
	int no;
	struct trie_t* next[26];
};
struct trie_t spool[MAX * MAX];
struct trie_t root;
struct trie_t* ptr;
struct ans_t ans[MAX];
char map[MAX][MAX];
int dx[8] = {-1, -1, 0, 1, 1,  1,  0, -1};
int dy[8] = { 0,  1, 1, 1, 0, -1, -1, -1};
int cnt, l, c, w;
void init_trie()
{
	int i;
	for(i = 0;i < 26; i++) {root.next[i] = NULL; root.no = -1;}
	ptr = spool;
	cnt = 0;
}
int insert(char* key)
{
	struct trie_t* r = &root;
	struct trie_t* t;
	int i, j;
	for(i = 0;key[i] != '\0'; i++)
	{
		if(r->next[key[i] - 'A'] == NULL)
		{
			r->next[key[i] - 'A'] = ptr++;
			t = r->next[key[i] - 'A'];
			for(j = 0;j < 26; j++) { t->no = -1; t->next[j] = NULL;}
		}
		r = r->next[key[i] - 'A'];
	}
	r->no = ++cnt;
	return r->no;
}
void init()
{
	char str[MAX];
	int i, j;
	scanf("%d %d %d", &l, &c, &w);
	getchar();
	for(i = 1;i <= l; i++)
	{
		for(j = 1;j <= c; j++) map[i][j] = getchar();
		getchar();
	}
	for(i = 1;i <= w; i++)
	{
		scanf("%s", str);
		j = insert(str);
	}
}
void check(int x, int y, int d)
{
	struct trie_t* r = &root;
	char ch;
	int tx, ty, i, j;
	while(x >= 1 && x <= l && y >= 1 && y <= c)
	{
		ch = map[x][y];
		if(r->next[ch - 'A'] == NULL) break;
		r = r->next[ch - 'A'];
		x += dx[d];
		y += dy[d];
	}
	if(r->no > -1)
	{
		ans[r->no].r = x - 1;
		ans[r->no].c = y - 1;
		ans[r->no].d = d;
	}
}
void search()
{
	int res, i, j, k;
	for(i = 1;i <= l; i++)
	{
		for(j = 1;j <= c; j++)
		{
			for(k = 0;k < 8; k++)
			{
				check(i, j, k);
			}
		}
	}
}
void output()
{
	int i;
	for(i = 1;i <= w; i++) printf("%d %d %c\n", ans[i].r, ans[i].c, ans[i].d + 'A');
}
int main()
{
	int i;
	init_trie();
	init();
	search();
	output();
	return 0;
}
