#include <stdio.h>
#define MAX 80002
typedef long long int64;
int64 stack[MAX];
int64 h;
int res;
int top;
int n;
int main()
{
	scanf("%d", &n);
	top = 0;
	res = 0;
	while(n--)
	{
		scanf("%lld", &h);
		while(top > 0 && h >= stack[top]) top--;
		res += top;
		stack[++top] = h;
	}
	printf("%d\n", res);
	return 0;
}
