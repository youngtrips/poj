#include <stdio.h>
#define MAXN 100002
long long max, tmp;
long long stack[MAXN][2];
int top;
int main()
{
	int skip, h, i, j, n;
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		top = -1; max = 0;
		for(i = 0;i < n; i++)
		{
			scanf("%d", &h);
			j = i;
			skip = 0;
			while(top != -1)
			{
				if(stack[top][0] == h) { skip = 1; break;}
				if(stack[top][0] < h) break;
				tmp = stack[top][0] * (i - stack[top][1]);
				if(tmp > max) max = tmp;
				j = stack[top][1];
				top--;
			}
			if(skip == 0)
			{
				stack[++top][0] = h;
				stack[top][1] = j;
			}
		}
		while(top != -1)
		{
			tmp = stack[top][0] * (n - stack[top][1]);
			if(tmp > max) max = tmp;
			top--;
		}
		printf("%lld\n", max);
	}
	return 0;
}
