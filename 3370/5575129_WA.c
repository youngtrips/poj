#include <stdio.h>
#include <string.h>
#define MAXN 100002
long long sum;
int has[MAXN];
int flag, c, n;
int main()
{
	int st, ed, i, x, j, t;
	while(1)
	{
		scanf("%d %d", &c, &n);
		if(c == 0 && n == 0) break;
		memset(has, 0, sizeof(has));
		flag = 0; sum = 0;
		for(i = 1;i <= n; i++)
		{
			scanf("%d", &x);
			if(flag == 0)
			{
				sum += x;
				t = sum % c;
				if(has[t] == 0) has[t] = i;
				else
				{
					st = has[t] + 1;
					ed = i;
					flag = 1;
				}
			}
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
