#include <stdio.h>
#define MAXN 1002
int a[MAXN][MAXN];
int n;
int init()
{
	int i, j;
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) scanf("%d", &a[i][j]);
	return n != 0;
}
void solve()
{
	int flag, i, j;
	for(i = n;i >= 1; i--)
		for(j = 1;j <= n; j++) a[i][j] -= a[1][j];
	flag = 1;
	for(j = n;j >= 1; j--)
	{
		for(i = 1;i <= n; i++)
		{
			a[i][j] -= a[i][1];
			if(a[i][j] != 0) { flag = 0; break;}
		}
		if(flag == 0) break;
	}
	printf("%s\n", flag == 1 ? "homogeneous" : "not homogeneous");
}
int main()
{
	while(init()) solve();
	return 0;
}
