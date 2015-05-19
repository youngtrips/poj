#include <stdio.h>
#define MAX 80002
int stack[MAX];
int n, t;
void init() { t = 0;}
int empty() { return t == 0;}
void push(int x) { stack[++t] = x;}
void pop() { t--;}
int top() { return stack[t];}
int main()
{
	int res;
	int x;
	res = 0;
	scanf("%d", &n);
	init();
	while(n--)
	{
		scanf("%d", &x);
		while(!empty() && x > top()) pop();
		res += t;
		push(x);
	}
	printf("%d\n", res);
}
