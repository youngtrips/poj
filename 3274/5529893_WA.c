#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100002
#define MAXM 32
#define MAXP 100003
typedef struct
{
	int bits[MAXM];
	int no;
}list_t;
list_t list[MAXN];
int n, k;
void to_bits(int x, int p)
{
	int i = k;
	while(x)
	{
		list[p].bits[i--] = x & 1;
		x >>= 1;
	}
}
void init()
{
	int i, x;
	scanf("%d %d", &n, &k);
	memset(list, 0, sizeof(list));
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &x);
		list[i].no = i;
		to_bits(x, i);
	}
}
int cmp(const void* p1, const void* p2)
{
	list_t* a = (list_t*)p1;
	list_t* b = (list_t*)p2;
	int i, j;
	for(i = 1;i <= k; i++)
	{
		if(a->bits[i] != b->bits[i])
		{
			return a->bits[i] - b->bits[i];
		}
	}
	return a->no - b->no;
}
int equal(list_t a, list_t b)
{
	int i;
	for(i = 1;i <= k; i++) if(a.bits[i] != b.bits[i]) return 0;
	return 1;
}
void solve()
{
	int ans, i, j, t;
	if(n == 1) ans = 1;
	else
	{
		ans = 0;
		for(i = 2;i <= n; i++)
			for(j = 1;j <= k; j++) list[i].bits[j] += list[i-1].bits[j];
		for(i = 1;i <= n; i++)
		{
			for(j = 1;j < k; j++) list[i].bits[j] -= list[i].bits[k];
			list[i].bits[k] = 0;
		}
		qsort((void*)&list[1], n, sizeof(list[1]), cmp);
		i = 1;
		while(i < n)
		{
			j = i + 1;
			while(equal(list[i], list[j]) && j <= n) j++;
			t = list[j].no - list[i].no;
			if(ans < t) ans = t;
			i = j;
		}
	}
	printf("%d\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
