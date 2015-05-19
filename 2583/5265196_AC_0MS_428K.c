#include <stdio.h>
int main()
{
	int f0, f1, f2, f3, f4, f5;
	while(scanf("%d %d %d", &f0, &f1, &f2) != EOF)
	{
		f3 = 3 * (f2 - f1) + f0;
		f4 = 6 * f2 - 8 * f1 + 3 * f0;
		f5 = 10 * f2 - 15 * f1 + 6 * f0;
		printf("%d %d %d\n", f3, f4, f5);
	}
	return 0;
}
