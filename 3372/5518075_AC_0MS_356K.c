#include <stdio.h>
#include <math.h>
int n;
void solve()
{
	int x, y;
	x = log2(n);
	y = (int)pow(2.0, x * 1.0);
	printf("%s\n", n == y ? "YES" : "NO");
}
int main()
{
	while(scanf("%d", &n) != EOF) solve();
	return 0;
}
