#include <stdio.h>
#include <string.h>
#define MAX 150000
int has[MAX];
int hash(int a[6])
{
	int x = a[0] + a[2] + a[4];
	int y = a[1] + a[3] + a[5];
	return (x + y) % 149997;
}
int main()
{
	int x[6], n, f, p;
	scanf("%d", &n);
	memset(has, 0, sizeof(has));
	f = 1;
	while(n--)
	{
		scanf("%d %d %d %d %d %d", x, x + 1, x + 2, x + 3, x + 4, x + 5);
		p = hash(x);
		if(has[p] == 1) { f = 0; break;}
		else has[p] = 1;
	}
	if(f) printf("No two snowflakes are alike.\n");
	else printf("Twin snowflakes found.\n");
	return 0;
}
