#include <stdio.h>
int main()
{
	int tmp, i, j, n, k, s, t, r;
	scanf("%d %d", &n, &k);
	while(k--)
	{
		scanf("%d %d %d", &s, &t, &r);
		tmp = n;
		i = 1;
		j = 0;
		while(1)
		{
			tmp -= s;
			if(tmp <= 0) break;
			i++;
			j++;
			if(j == t)
			{
				i += r;
				j = 0;
			}
		}
		printf("%d\n", i);
	}
	return 0;
}
