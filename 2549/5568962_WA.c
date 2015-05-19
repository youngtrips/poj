#include <stdio.h>
#include <stdlib.h>
#define MAXN 1002
typedef struct
{
	int a; int b;
	int s;
}left_t;
typedef struct
{
	int c; int d;
	int s;
}right_t;
right_t right[MAXN * MAXN];
left_t left[MAXN * MAXN];
int s[MAXN];
int tot_l, tot_r, n;
int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}
int init()
{
	int i, j;
	scanf("%d", &n);
	if(n == 0) return 0;
	for(i = 1;i <= n; i++) scanf("%d", &s[i]);
	qsort((void*)&s[1], n, sizeof(s[1]), cmp);
	tot_l = 0; tot_r = 0;
	for(i = 1;i <= n; i++)
	{
		for(j = i + 1;j <= n; j++)
		{
			left[++tot_l].s = s[i] + s[j];
			left[tot_l].a = s[i];
			left[tot_l].b = s[j];
		}
	}
	for(i = n;i >= 1; i--)
	{
		for(j = i - 1;j >= 1; j--)
		{
			right[++tot_r].s = s[i] - s[j];
			right[tot_r].c = s[j];
			right[tot_r].d = s[i];
		}
	}
	return 1;
}
void solve()
{
	int f, i;
	f = 0;
	for(i = 1;i <= tot_l; i++)
	{
		if(left[i].s == right[i].s && left[i].a != right[i].c && left[i].a != right[i].d &&
				left[i].b != right[i].c && left[i].b != right[i].d)
		{
			f = 1;
			break;
		}
	}
	if(f) printf("%d\n", right[i].d);
	else printf("no solution\n");
}
int main()
{
	while(init()) solve();
	return 0;
}
