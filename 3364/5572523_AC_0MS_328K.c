#include <stdio.h>
int n, m, c;
int main()
{
	while(1)
	{
		scanf("%d %d %d", &n, &m, &c);
		if(n == 0 && m == 0 && c == 0) break;
		printf("%d\n", ((n - 7) * (m - 7) + c)>>1);
	}
	return 0;
}
