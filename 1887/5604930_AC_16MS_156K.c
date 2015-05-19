#include <stdio.h>
#define MAXN 10002
int a[MAXN], b[MAXN], n;
int binary(int i, int k)
{
	int h, j;
	if(a[i] >= b[1]) return 1;
	for(h = 1,j = k; h != j - 1;)
	{
		if(b[k = (h + j) / 2] >= a[i]) h = k;
		else j = k;
	}
	return j;
}
int lis()
{
	int i, j, k;
	b[1] = a[0];
	for(i = 1, k = 1;i < n; i++)
	{
		if(a[i] <= b[k]) b[++k] = a[i];
		else b[binary(i,k)] = a[i];
	}
	return k;
}
int main()
{
	int s = 1;
	while(1)
	{
		n = 0;
		scanf("%d", &a[n]);
		if(a[n] == -1) break;
		while(a[n] != -1)
		{
			n++;
			scanf("%d", &a[n]);
		}
		printf("Test #%d:\n", s++);
		printf("  maximum possible interceptions: %d\n\n", lis());
	}
	return 0;
}
