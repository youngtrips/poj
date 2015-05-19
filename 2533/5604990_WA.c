#include <stdio.h>
#define MAXN 1002
int a[MAXN], b[MAXN], c[MAXN], n;
int binary(int i, int k)
{
	int h, j;
	if(a[i] < b[1]) return 1;
	for(h = 1,j = k; h != j - 1;)
	{
		if(b[k = (h + j) / 2] <= a[i]) h = k;
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
		if(a[i] >= b[k]) b[++k] = a[i];
		else b[binary(i,k)] = a[i];
	}
	return k;
}
int main()
{
	int i, j, x, y;
	scanf("%d", &n);
	for(i = 0, j = n - 1;i < n; i++, j--) 
	{
		scanf("%d", a + i);
		c[j] = a[i];
	}
	x = lis();
	for(i = 0;i < n; i++) a[i] = c[i];
	y = lis();
	printf("%d\n", x > y ? x: y);
	return 0;
}
