#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000002
typedef struct
{
	int pos;
	int val;
}node_t;
node_t qmax[MAXN];
node_t qmin[MAXN];
int h_max, t_max;
int h_min, t_min;
int a[MAXN];
int n, l;
int cmp(const void* p1, const void* p2)
{
	node_t* a = (node_t*)p1;
	node_t* b = (node_t*)p2;
	return b->val - a->val;
}
void init()
{
	int i;
	scanf("%d %d", &n, &l);
	for(i = 1;i <= n; i++) scanf("%d", &a[i]);
	h_max = 0; t_max = 0;
	h_min = 0; t_min = 0;
	for(i = 1;i <= l; i++)
	{
		qmax[t_max].pos = i;
		qmax[t_max++].val = a[i];
	}
	qsort((void*)&qmax[0], l, sizeof(qmax[0]), cmp);
	for(i = l - 1;i >= 0; i--)
	{
		qmin[t_min].val = qmax[i].val;
		qmin[t_min++].pos = qmax[i].pos;
	}
}
void solve()
{
	int i = l + 1;
	printf("%d", qmin[h_min].val);
	while(i <= n)
	{
		while(h_min < t_min && qmin[t_min - 1].val > a[i]) t_min--;
		qmin[t_min].val = a[i];
		qmin[t_min++].pos = i;
		while(qmin[h_min].pos < i - l + 1 && h_min < t_min) h_min++;
		printf(" %d", qmin[h_min].val);
		i++;
	}
	printf("\n");
	i = l + 1;
	printf("%d", qmax[h_max].val);
	while(i <= n)
	{
		while(h_max < t_max && qmax[t_max - 1].val < a[i]) t_max--;
		qmax[t_max].val = a[i];
		qmax[t_max++].pos = i;
		while(qmax[h_max].pos < i - l + 1 && h_max < t_max) h_max++;
		printf(" %d", qmax[h_max].val);
		i++;
	}
	printf("\n");
}
int main()
{
	init();
	solve();
	return 0;
}
