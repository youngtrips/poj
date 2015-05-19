#include <stdio.h>
#include <memory.h>
#include <string.h>
#define MAX 105
char m[MAX];
char q[110000][MAX];
int head, tail, n;
int mod(char* a, int b)
{
	int c = (*a++ - '0') % b;
	while(*a)
		c = (c * 10 + (*a++ - '0')) % b;
		return c;
}
void bfs()
{
	int len;
	strcpy(q[0], "1");
	head = 0;
	tail = 1;
	while(head < tail)
	{
		strcpy(m, q[head]);
		len = strlen(m);
		if(mod(m, n) == 0) return;
		m[len] = '1';
		strcpy(q[tail++], m);
		m[len] = '0';
		strcpy(q[tail++], m);
		head++;
	}
}
int main()
{
	while(scanf("%d", &n), n > 0)
	{
		memset(m, '\0', sizeof(m));
		bfs();
		printf("%s\n", m);
	}
	return 0;
}
