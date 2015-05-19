#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define CLS(x) memset(x, 0, sizeof(x))
#define N 10
typedef struct
{
	int i;
	int e;
}Frog;
Frog frog[N];
int adj[N][N];
char ans[2][4] = {"NO", "YES"};
int cmp(const void* p1, const void* p2)
{
	Frog* f1 = (Frog*)p1;
	Frog* f2 = (Frog*)p2;
	return f1->e - f2->e;
}
void print(int n)
{
	int i, j;
	for(i = 0;i < n; i++)
	{
		for(j = 0;j < n; j++) printf("%d ", adj[i][j]);
		printf("\n");
	}
}
void build(int n)
{
	int flag, cnt, i, j, e, k, p;
	CLS(adj);
	flag = 1;
	for(i = 0;i < n; i++)
	{
		qsort((void*)frog, n - i, sizeof(frog[0]), cmp);
		p = frog[n - i - 1].i;
		e = frog[n - i - 1].e;
		for(j = n - i -2, k = 0;k < e; k++, j--)
		{
			adj[frog[j].i][p] = 1;
			adj[p][frog[j].i] = 1;
			frog[j].e--;
			if(frog[j].e < 0) {flag = 0;break;}
		}
	}
	printf("%s\n", ans[flag]);
	if(flag) print(n);
}
int main()
{
	int tmp, t, n, i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		tmp = 0;
		for(i = 0;i < n; i++)
		{
			frog[i].i = i;
			scanf("%d", &frog[i].e);
			tmp += frog[i].e;
		}
		if(tmp & 1) printf("NO\n");
		else build(n);
		printf("\n");
	}
	return 0;
}
