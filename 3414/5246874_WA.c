#include <stdio.h>
#include <string.h>
#define MAX 50
char ans[8][20] = { "FILL(1)", "FILL(2)", "FILLL(1)\nFILL(2)", "DROP(1)","DROP(2)", "DROP(1)\nDROP(2)", "POUR(1,2)", "POUR(2,1)"};
typedef struct
{
	int i;
	int j;
	int k;
	int op;
	int pre;
}Pot;
Pot q[MAX * MAX];
int flag[MAX][MAX], op[MAX * MAX], head, tail, a, b, c;
void init()
{
	scanf("%d %d %d", &a, &b, &c);
	memset(flag, 0, sizeof(flag));
	flag[0][0] = 1;
	q[0].i = 0;
	q[0].j = 0;
	q[0].k = 0;
	q[0].op = -1;
	q[0].pre = -1;
	head = 0;
	tail = 1;
}
int bfs()
{
	int curpre, curop, curi, curj, curk, tmpi, tmpj, tmp;
	while(head < tail)
	{
		curi = q[head].i;
		curj = q[head].j;
		curk = q[head].k;
		if(curi == c || curj == c)
		{ 
			printf("%d\n", curk);
			return head;
		}
		if(curi == 0)
		{
			tmpi = a;
			tmpj = curj;
			if(flag[tmpi][tmpj] == 0)
			{
				flag[tmpi][tmpj] = 1;
				q[tail].i = tmpi;
				q[tail].j = tmpj;
				q[tail].k = curk + 1;
				q[tail].op = 0;
				q[tail].pre = head;
				tail++;
			}
		}
		if(curj == 0)
		{
			tmpi = curi;
			tmpj = b;
			if(flag[tmpi][tmpj] == 0)
			{
				flag[tmpi][tmpj] = 1;
				q[tail].i = tmpi;
				q[tail].j = tmpj;
				q[tail].k = curk + 1;
				q[tail].op = 1;
				q[tail].pre = head;
				tail++;
			}
		}
		if(curi == 0 && curi == 0)
		{
			tmpi = a;
			tmpj = b;
			if(flag[tmpi][tmpj] == 0)
			{
				flag[tmpi][tmpj] = 1;
				q[tail].i = tmpi;
				q[tail].j = tmpj;
				q[tail].k = curk + 1;
				q[tail].op = 2;
				q[tail].pre = head;
				tail++;
			}
		}
		if(curi > 0)
		{
			tmpi = 0;
			tmpj = curj;
			if(flag[tmpi][tmpj] == 0)
			{
				flag[tmpi][tmpj] = 1;
				q[tail].i = tmpi;
				q[tail].j = tmpj;
				q[tail].k = curk + 1;
				q[tail].op = 3;
				q[tail].pre = head;
				tail++;
			}
		}
		if(curj > 0)
		{
			tmpi = curi;
			tmpj = 0;
			if(flag[tmpi][tmpj] == 0)
			{
				flag[tmpi][tmpj] = 1;
				q[tail].i = tmpi;
				q[tail].j = tmpj;
				q[tail].k = curk + 1;
				q[tail].op = 4;
				q[tail].pre = head;
				tail++;
			}
		}
		if(curi > 0 && curj > 0)
		{
			tmpi = 0;
			tmpj = 0;
			if(flag[tmpi][tmpj] == 0)
			{
				flag[tmpi][tmpj] = 1;
				q[tail].i = tmpi;
				q[tail].j = tmpj;
				q[tail].k = curk + 1;
				q[tail].op = 5;
				q[tail].pre = head;
				tail++;
			}
		}
		tmp = (b - curj) < curi ? (b - curj) : curi;
		tmpi = curi - tmp;
		tmpj = curj + tmp;
		if(flag[tmpi][tmpj] == 0)
		{
			flag[tmpi][tmpj] = 1;
			q[tail].i = tmpi;
			q[tail].j = tmpj;
			q[tail].k = curk + 1;
			q[tail].op = 6;
			q[tail].pre = head;
			tail++;
		}
		tmp = (a - curi) < curj ? (a - curi) : curj;
		tmpi = curi + tmp;
		tmpj = curj - tmp;
		if(flag[tmpi][tmpj] == 0)
		{
			flag[tmpi][tmpj] = 1;
			q[tail].i = tmpi;
			q[tail].j = tmpj;
			q[tail].k = curk + 1;
			q[tail].op = 7;
			q[tail].pre = head;
			tail++;
		}
		head++;
	}
	return -1;
}
int main()
{
	int i, j;
	init();
	i = bfs();
	if(i == -1) printf("impossible\n");
	else
	{
		j = 0;
		while(q[i].pre != -1)
		{
			op[j++] = q[i].op;
			i = q[i].pre;
		}
		for(i = j - 1;i >= 0; i--) printf("%s\n", ans[op[i]]);
	}
	return 0;
}
