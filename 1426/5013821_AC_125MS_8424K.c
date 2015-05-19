#include <stdio.h>
#define MAX 1100000
__int64 q[MAX];
int head, tail, n;
__int64 bfs()
{
	__int64 tmp;
	q[0] = 1;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		tmp = q[head];
		if(tmp % n == 0) return tmp;
		tmp *= 10;
		q[tail++] = tmp;
		q[tail++] = tmp + 1;
		head++;
	}
}
int main()
{
	while(scanf("%d", &n), n > 0)
		printf("%I64d\n", bfs());
	return 0;
}
