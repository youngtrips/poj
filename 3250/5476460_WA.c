#include <stdio.h>
#define MAX 80002
int stack[MAX];
int top = 0;
int main()
{
	int res, n, x;
	scanf("%d", &n);
	res = 0;
	while(n--)
	{
		scanf("%d", &x);
		while(top > 0 && x >= stack[top]) top--;
		res += top;
		stack[++top] = x;
	}
	printf("%d\n", res);
	return 0;
}
