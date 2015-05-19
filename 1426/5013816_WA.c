#include <stdio.h>
#define MAX 1100000
unsigned long long q[MAX];
int head, tail, n;
unsigned long long bfs()
{
	unsigned long long tmp;
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
		printf("%lld\n", bfs());
	return 0;
}
