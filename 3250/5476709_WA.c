#include <stdio.h>
#define MAX 80002
unsigned int stack[MAX], x;
unsigned int top, res, n;
int main()
{
	scanf("%d", &n);
	res = 0;
	top = 0;
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
