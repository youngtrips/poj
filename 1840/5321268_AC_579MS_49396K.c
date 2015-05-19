#include <stdio.h>
#include <string.h>
#define MAX 12500000
int a1, a2, a3, a4, a5;
int num[110];
short has[MAX * 2];
int main()
{
	int ans, i, j, k, t;
	scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
	memset(has, 0, sizeof(has));
	for(i = -50;i <= 50; i++) num[i + 50] = i * i * i;
	for(i = -50;i <= 50; i++)
	{
		if(i == 0) continue;
		for(j = -50;j <= 50; j++)
		{
			if(j == 0) continue;
			k = a1 * num[i + 50] + a2 * num[j + 50] + MAX;
			has[k]++;
		}
	}
	ans = 0;
	for(i = -50;i <= 50; i++)
	{
		if(i == 0) continue;
		for(j = -50;j <= 50; j++)
		{
			if(j == 0) continue;
			for(k = -50;k <= 50; k++)
			{
				if(k == 0) continue;
				t = MAX - a3 * num[i + 50] - a4 * num[j + 50] - a5 * num[k + 50];
				if(t >= 0 && (t>>1) <= MAX ) ans += has[t];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
