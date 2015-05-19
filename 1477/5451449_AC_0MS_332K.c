#include <stdio.h>
#define MAX 51
int h[MAX];
int avg;
int ans;
int n;
int main()
{
	int s = 1;
	int i;
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		avg = 0;
		ans = 0;
		for(i = 1;i <= n; i++)
		{
			scanf("%d", &h[i]);
			avg += h[i];
		}
		avg /= n;
		for(i = 1;i <= n; i++) if(h[i] > avg) ans += h[i] - avg;
		printf("Set #%d\n", s++);
		printf("The minimum number of moves is %d.\n", ans);
		printf("\n");
	}
	return 0;
}
