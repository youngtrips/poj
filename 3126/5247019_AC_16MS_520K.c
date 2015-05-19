#include <stdio.h>
#include <string.h>
#define MAXN 10000
int prime[MAXN + 1];
typedef struct
{
	char p[5];
	int cost;
}Stat;
Stat q[MAXN];
char st[5], ed[5];
int flag[MAXN], head, tail;
void gen_prime()
{
	int i, j;
	for(i = 2; i < MAXN + 1; i++) prime[i] = 1;
    for(i = 2; i < MAXN + 1; i++)
    {
        j = 2;
        while(j * i < MAXN + 1)
        {
            prime[j * i] = 0;
            j++;
        }
    }
}
int stoi(char* s)
{
	int sum = 0, i = 0;
	while(s[i]){sum = sum * 10 + (s[i] - '0');i++;}
	return sum;
}
void init()
{
	scanf("%s %s", st, ed);
	strcpy(q[0].p, st);
	q[0].cost = 0;
	memset(flag, 0, sizeof(flag));
	flag[stoi(st)] = 1;
	head = 0;
	tail = 1;
}
int bfs()
{
	char cur[5], tmp[5];
	int i, k, j, x;
	while(head < tail)
	{
		strcpy(cur, q[head].p);
		k = q[head].cost;
		if(!strcmp(cur, ed)) return head;
		for(j = 1;j < 10; j++)
		{
			strcpy(tmp, cur);
			tmp[0] = j + '0';
			x = stoi(tmp);
			if(prime[x] && flag[x] == 0)
			{
				flag[x] = 1;
				strcpy(q[tail].p, tmp);
				q[tail].cost = k + 1;
				tail++;
			}
		}
		for(i = 1;i < 4; i++)
		{
			for(j = 0;j < 10; j++)
			{
				strcpy(tmp, cur);
				tmp[i] = j + '0';
				x = stoi(tmp);
				if(prime[x] && flag[x] == 0)
				{
					flag[x] = 1;
					strcpy(q[tail].p, tmp);
					q[tail].cost = k + 1;
					tail++;
				}
			}
		}
		head++;
	}
	return -1;
}
int main()
{
	int res, n;
	gen_prime();
	scanf("%d", &n);
	while(n--)
	{
		init();
		res = bfs();
		if(res == -1) printf("Impossible\n");
		else printf("%d\n", q[res].cost);
	}
	return 0;
}
