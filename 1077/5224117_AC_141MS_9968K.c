#include <stdio.h>
#include <string.h>
#define MAXN 400002
typedef struct
{
	char board[4][4];
	int px, py, key;
}State;
State queue[MAXN], start;
char action[] = "drul";
int f[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int visited[MAXN], pre[MAXN], ans[MAXN], head, tail;
void init()
{
	char tmp[2];
	int i, j;
	for(i = 1;i <= 3; i++)
		for(j = 1;j <= 3; j++)
		{
			scanf("%s", tmp);
			if(tmp[0] != 'x') start.board[i][j] = tmp[0];
			else
			{
				start.board[i][j] = '9';
				start.px = i;
				start.py = j;
			}
		}
	memset(visited, 0, sizeof(visited));
	memset(pre, -1, sizeof(pre));
	head = 0; tail = 0;
}
int hash(State stat)
{
	int tmp[10], res, i, j, k = 1;
	for(i = 1;i <= 3; i++)
		for(j = 1;j <= 3; j++) tmp[k++] = stat.board[i][j] - '0';
	res = 0;
	for(i = 1;i <= 9; i++)
	{
		k = 0;
		for(j = 1;j < i; j++) if(tmp[i] < tmp[j]) k++;
		res += k * f[i-1];
	}
	return res;
}
int issolveable(State stat)
{
	int tmp[10], res, i, j, k = 1;
	for(i = 1;i <= 3; i++)
		for(j = 1;j <= 3; j++) tmp[k++] = stat.board[i][j] - '0';
	res = 0;
	for(i = 1;i <= 9; i++)
		for(j = 1;j < i; j++) if(tmp[i] < tmp[j]) res++;
	res += 6 - stat.px - stat.py;
	return (res & 1) == 0;
}
int check(int x, int y){return x >= 1 && x <= 3 && y >= 1 && y <= 3;}
void push(State stat)
{
	int i, j;
	for(i = 1;i <= 3; i++)
		for(j = 1;j <= 3; j++) queue[tail].board[i][j] = stat.board[i][j];
	queue[tail].px = stat.px;
	queue[tail].py = stat.py;
	queue[tail].key = stat.key;
	tail++;
}
void pop(State* stat)
{
	int i, j;
	for(i = 1;i <= 3; i++)
		for(j = 1;j <= 3; j++) stat->board[i][j] = queue[head].board[i][j];
	stat->px = queue[head].px;
	stat->py = queue[head].py;
	stat->key = queue[head].key;
	head++;
}
int empty(){return head >= tail;}
void move(State s, State* t, int d)
{
	int i, j;
	for(i = 1;i <= 3; i++)
		for(j = 1;j <= 3; j++) t->board[i][j] = s.board[i][j];
	t->px = s.px + dx[d]; t->py = s.py + dy[d];
	t->board[t->px][t->py] = s.board[s.px][s.py];
	t->board[s.px][s.py] = s.board[t->px][t->py];
}
void bfs(State* st)
{
	int i, k;
	State e, t;
	k = hash(*st);
	st->key = k;
	push(*st);
	visited[k] = 1;
	pre[k] = -1;
	while(!empty())
	{
		pop(&e);
		k = e.key;
		for(i = 0;i < 4; i++)
		{
			if(check(e.px + dx[i], e.py + dy[i]))
			{
				move(e, &t, i);
				t.key = hash(t);
				if(visited[t.key] == 0)
				{
					visited[t.key] = 1;
					pre[t.key] = k;
					ans[t.key] = i;
					push(t);
				}
				if(t.key == 0) return;
			}
		}
	}
}
void output()
{
	int i = 0, j = 0;
	while(pre[i] != -1)
	{
		visited[j++] = ans[i];
		i = pre[i];
	}
	for(i = j - 1; i > 0; i--) printf("%c", action[visited[i]]);
	printf("%c\n", action[visited[i]]);
}
int main()
{
	init();
	if(!issolveable(start)) printf("unsolvable\n");
	else
	{
		bfs(&start);
		output();
	}
	return 0;
}
