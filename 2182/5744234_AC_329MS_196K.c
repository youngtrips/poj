#include <stdio.h>
#include <string.h>
#define MAXN 8002
char flag[MAXN];
int a[MAXN];
int n;
int main()
{
	int i, j, k;
	scanf("%d", &n);
	memset(flag, 0, sizeof(flag));
	for(i = 2;i <= n; i++) scanf("%d", &a[i]);
	a[n] = a[n] + 1;
	flag[a[n]] = 1;
	for(i = n - 1;i >= 1; i--)
	{
		k = 0;
		for(j = 1;j <= n; j++)
		{
			if(flag[j] == 0) k++;
			if(k == a[i] + 1) break;
		}
		a[i] = j;
		flag[j] = 1;
	}
	for(i = 1;i <= n; i++) printf("%d\n", a[i]);
	return 0;
}
