#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 1000008
char flag[MAX];
int prime[MAX];
int tot;
int n;
void init()
{
	int i, j;
	memset(flag, '1', sizeof(flag));
	for(i = 2;i < MAX; i++)
	{
		if(flag[i] == '1')
			for(j = 2;j * i < MAX; j++) flag[i * j] = '0';
	}
	tot = 0;
	for(i = 2;i < MAX; i++) if(flag[i] == '1') prime[++tot] = i;
}
void solve()
{
	int max;
	int cnt;
	int i, j, k;
	if(n == 1) cnt = 0;
	else
	{
		cnt = 1;
		i = 1;
		while(n > 1)
		{
			k = 0;
			while(n % prime[i] == 0)
			{
				k++;
				n /= prime[i];
			}
			if(k > 0) cnt *= (pow(prime[i], k) - pow(prime[i], k - 1));
			i++;
		}
	}
	printf("%d\n", cnt);
}
int main()
{
	init();
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		solve();
	}
	return 0;
}
