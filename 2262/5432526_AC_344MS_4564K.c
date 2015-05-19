#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 1000002
int flag[MAX];
int prime[MAX];
int tot;
void gen_prime()
{
	int i, j;
	memset(flag, 0, sizeof(flag));
	tot = -1;
	for(i = 2;i <= MAX; i++)
	{
		if(flag[i] == 0)
		{
			prime[++tot] = i;
			for(j = 2;j * i <= MAX; j++) flag[j * i] = -1;
		}
	}
}
int main()
{
	int f, i, j, n;
	gen_prime();
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		f = 0;
		for(i = 1;prime[i] < n && i <= tot; i++)
			if(flag[n - prime[i]] == 0) { f = 1; break;}
		if(f) printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
		else printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
