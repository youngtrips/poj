#include <stdio.h>
#include <string.h>
#define MAXN 1002
#define MAXM 2502
struct trie_t
{
	int flag;
	struct trie_t* next[2];
};
struct trie_t spool[MAXN * MAXM];
struct trie_t root;
struct trie_t* pt;
char map[MAXN][MAXN];
int cnt, n, m, p, q;
void init_trie()
{
	int i;
	for(i = 0;i < 2; i++) {root.flag = 0; root.next[i] = NULL;}
	pt = spool;
}
void insert(char* key)
{
	int i, j;
	struct trie_t* r = &root;
	struct trie_t* t;
	for(i = 0;key[i] != '\0'; i++)
	{
		if(r->next[key[i] - '0'] == NULL)
		{
			r->next[key[i] - '0'] = pt++;
			t = r->next[key[i] - '0'];
			for(j = 0;j < 2; j++) { t->flag = 0; t->next[j] = NULL;}
		}
		r = r->next[key[i] - '0'];
	}
	r->flag = 1;
}
int find(char* key)
{
	int i, j;
	struct trie_t* r = &root;
	struct trie_t* t;
	for(i = 0;key[i] != '\0'; i++)
	{
		if(r->next[key[i] - '0'] == NULL) return 0;
		r = r->next[key[i] - '0'];
	}
	return r->flag;
}
int init()
{
	int i, j, t, k;
	char sub[MAXM];
	scanf("%d %d %d %d %d", &n, &m, &t, &p, &q);
	if(n == 0 && m == 0 && t == 0 && p == 0 && q == 0) return 0;
	getchar();
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++)
		{
			map[i][j] = getchar();
			if(map[i][j] == '*') map[i][j] = '1';
		}
		getchar();
	}
	init_trie();
	while(t--)
	{
		k = 0;
		getchar();
		for(i = 1;i <= p; i++)
		{
			for(j = 1;j <= q; j++)
			{
				sub[k] = getchar();
				if(sub[k] == '*') sub[k] = '1';
				k++;
			}
			getchar();
		}
		sub[k] = '\0';
		insert(sub);
	}
	return 1;
}
void scan()
{
	int tx, ty, i, j, x, y, k;
	char sub[MAXM];
	cnt = 0;
	for(i = 1;i <= n - p + 1; i++)
	{
		for(j = 1;j <= m - q + 1; j++)
		{
			k = 0;
			tx = i;
			for(x = 0;x < p; x++)
			{
				tx += x;
				ty = j;
				for(y = 0;y < q; y++)
				{
					ty += y;
					sub[k++] = map[tx][ty];
				}
			}
			sub[k] = '\0';
			cnt += find(sub);
		}
	}
}
int main()
{
	int s = 1;
	while(init())
	{
		scan();
		printf("Case %d: %d\n", s++, cnt);
	}
	return 0;
}
