#include <stdio.h>
#define MAX 1010
#define dis(i,j) (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])
int parent[MAX];
int rank[MAX];
int work[MAX];
double x[MAX], y[MAX], d;
int n;
void make_set(int n)
{
	int i;
	for(i = 0;i <= n; i++)
	{
		work[i] = 0;
		rank[i] = 0;
		parent[i] = i;
	}
}
int find_set(int x)
{
	if(x != parent[x]) parent[x] = find_set(parent[x]);
	return parent[x];
}
void union_set(int r1, int r2)
{
	int x = find_set(r1);
	int y = find_set(r2);
	if(x == y) return;
	if(rank[x] > rank[y]) parent[y] = x;
	else
	{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
}
void repaire(int p)
{
	double tmp;
	int i;
	work[p] = 1;
	for(i = 1;i <= n; i++)
	{
		if(work[i] && i != p)
		{
			tmp = dis(p, i);
			if(tmp <= d * d) union_set(p, i);
		}
	}
}
int main()
{
	char op[5];
	int i, p, q;
	scanf("%d %lf", &n, &d);
	make_set(n);
	for(i = 1;i <= n; i++) scanf("%lf %lf", &x[i], &y[i]);
	while(scanf("%s", op) != EOF)
	{
		if(op[0] == 'O') 
		{
			scanf("%d", &p);
			repaire(p);
		}
		else if(op[0] == 'S')
		{
			scanf("%d %d", &p, &q);
			if(find_set(p) != find_set(q)) printf("FAIL\n");
			else printf("SUCCESS\n");
		}
	}
	return 0;
}
