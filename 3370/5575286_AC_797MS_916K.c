#include <stdio.h>
#include <string.h>
#define MAXN 100002
int has[MAXN];
int a[MAXN];
int flag, sum, c, n;
int main()
{
	int st, ed, i, j;
	while(1)
	{
		scanf("%d %d", &c, &n);
		if(c == 0 && n == 0) break;
		for(i = 1;i <= n; i++) scanf("%d", &a[i]);
		flag = 0; sum = 0;
		memset(has, -1, sizeof(has));
		for(i = 1;i <= n; i++)
		{
			sum = (sum + a[i]) % c;
			if(has[sum] == -1) has[sum] = i;
			else
			{
				st = has[sum] + 1;
				ed = i;
				flag = 1;
				break;
			}
		}
		if(sum == 0)
		{
			st = 1; ed = n;
			flag = 1;
		}
		if(flag == 0) printf("no sweets\n");
		else
		{
			j = 1;
			for(i = st;i <= ed; i++)
			{
				if(j) printf("%d", i);
				else printf(" %d", i);
				j = 0;
			}
			printf("\n");
		}
	}
	return 0;
}
