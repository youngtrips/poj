#include <stdio.h>
#include <string.h>
#define MAXN 1002
#define MAXP 3701
#define MAXM 22
typedef struct
{
	int price[MAXN];
	int qual[MAXN];
	int cnt;
}compo_t;
compo_t compo[MAXN];
int has[MAXP];
int cnt, n, b;
int hash(char* key)
{
	unsigned long h = 0;
	unsigned long g;
	while(*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000L;
		if(g) h ^= g >> 24;
		h &= ~g;
	}
	return h % MAXP;
}
void init()
{
	char name[MAXM];
	char type[MAXM];
	int qual, price;
	int i, j;
	scanf("%d %d", &n, &b);
	memset(compo, 0, sizeof(compo));
	memset(has, -1, sizeof(has));
	cnt = 0;
	for(i = 1;i <= n; i++)
	{
		scanf("%s %s %d %d", type, name, &price, &qual);
		j = hash(type);
		if(has[j] == -1) has[j] = ++cnt;
		j = has[j];
		compo[j].price[++compo[j].cnt] = price;
		compo[j].qual[compo[j].cnt] = qual;
	}
}
int check(int lmt)
{
	int sum, tmp, i, j;
	sum = 0;
	for(i = 1;i <= cnt; i++)
	{
		tmp = 0x7fffffff;
		for(j = 1;j <= compo[i].cnt; j++)
		{
			if(compo[i].qual[j] >= lmt && tmp > compo[i].price[j]) 
				tmp = compo[i].price[j];
		}
		if(tmp == 0x7fffffff) return 0;
		sum += tmp;
		if(sum > b) return 0;
	}
	return sum <= b;
}
void solve()
{
	int high = 1000000000;
	int low = 0;
	int mid;
	while(low < high)
	{
		mid = (low + high + 1) / 2;
		if(check(mid)) low = mid;
		else high = mid - 1;
	}
	printf("%d\n", low);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		solve();
	}
	return 0;
}

