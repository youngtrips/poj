#include <stdio.h>
int  det(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - x2 * y1;
}
int main()
{
	int x[700];
	int y[700];
	int max;
	int cnt;
	int res;
	int n;
	int i;
	int j;
	int k;
	scanf("%d", &n);
	for(i = 0;i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	max = 0;
	for(i = 0;i < n-1; i++)
	{
		for(j = i + 1;j < n; j++)
		{
			cnt = 0;
			for(k = j+1;k < n; k++)
			{
				if(0 == det(x[j] - x[i], y[j] - y[i], x[k] - x[j], y[k] - y[j]))
					cnt++;
			}
			if(max < cnt)
				max = cnt;
		}
	}
	printf("%d\n", max + 2);
	return 0;
}
