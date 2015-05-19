#include <stdio.h>
int main()
{
	int n, m, p, c;
	while(1)
	{
		scanf("%d %d %d %d", &n, &m, &p, &c);
		if(n == 0 && m == 0 && p == 0 && c == 0) break;
		printf("%d\n", n - m + p);
	}
	return 0;
}
