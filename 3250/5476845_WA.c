#include <stdio.h>
#define MAX 80010
int stack[MAX];
int hi[MAX];
int top;
int res;
int n;
int i;
int main()
{
	scanf("%d", &n);
	top = 0;
	res = 0;
	for(i = 0;i < n; i++)
	{
		scanf("%d", &hi[i]);
		while(top > 0 && hi[i] >= stack[top]) top--;
		res += top;
		stack[++top] = hi[i];
	}
	printf("%d\n", res);
	return 0;
}
