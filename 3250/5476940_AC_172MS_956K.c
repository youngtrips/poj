#include <stdio.h>
#define MAX 80010
long long stack[MAX];
long long res, x;
int top;
int n;
int main()
{
	scanf("%d", &n);
	top = 0;
	res = 0;
	while(n--)
	{
		scanf("%lld", &x);
		while(top > 0 && x >= stack[top]) top--;
		res += top;
		stack[++top] = x;
	}
	printf("%lld\n", res);
	return 0;
}
