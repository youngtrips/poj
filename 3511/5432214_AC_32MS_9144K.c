#include <stdio.h>
#include <string.h>
#define MAX 1000002
char flag[MAX];
int np1[MAX];
int np2[MAX];
void gen_prime()
{
	int i, j;
	memset(flag, '1', sizeof(flag));
	np1[0] = 0;
	np1[1] = 0;
	np2[0] = 0;
	np2[1] = 0;
	np2[2] = 1;
	for(i = 2;i <= MAX; i++)
	{
		if(flag[i] == '1')
		{
			np1[i] = np1[i-1] + 1;
			if((i - 1) % 4 == 0) np2[i] = np2[i-1] + 1;
			else np2[i] = np2[i-1];
			if(i == 2) np2[i] = 1;
			for(j = 2;j * i < MAX; j++) flag[i * j] = '0';
		}
		else
		{
			np1[i] = np1[i-1];
			np2[i] = np2[i-1];
		}
	}
}
int main()
{
	int l, u, x, y, t1, t2;
	gen_prime();
	while(1)
	{
		scanf("%d %d", &l, &u);
		if(l == -1 && u == -1) break;
		t1 = l; t2 = u;
		if(l <= 0 && u <= 0){ l = 1;u = 1;}
		else if(l <= 0 && u > 0) l = 1;
		x = np1[u] - np1[l-1];
		y = np2[u] - np2[l-1];
		printf("%d %d %d %d\n", t1, t2, x, y);
	}
	return 0;
}
