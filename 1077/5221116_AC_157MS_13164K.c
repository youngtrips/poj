#include <stdio.h>
#include <string.h>
#define MAXN 400002
typedef int State[11];
State st, q[MAXN];
int visited[MAXN], head, tail;
int ans[MAXN], pre[MAXN];
int d[4] = {1, -3, -1, 3};
char str[] = "ruld";
int inv(int a[], int n)
{
	int s, i, j;
	for(s = 0, i = 1;i <= n; i++)
		for(j = 1;j < i; j++) if(a[i] < a[j]) s++;
	return s;
}
int hash(int a[])
{
	int f[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
	int res, cnt, i, j;
	res = 0;
	for(i = 1;i <= 9; i++)
	{
		cnt = 0;
		for(j = 1;j < i; j++) if(a[i] < a[j]) cnt++;
		res += cnt * f[i-1];
	}
	return res;
}
int dist(int i)
{
	int x, y;
	x = i / 3;
	if(i % 3 != 0) x++;
	y = i - (x - 1) * 3;
	return 6 - x - y;
}
void init()
{
	char s[2];
	int i;
	for(i = 1;i <= 9; i++)
	{
		scanf("%s", s);
		if(s[0] != 'x') st[i] = s[0] - '0';
		else {st[i] = 9; st[0] = i;}
	}
	memset(visited, 0, sizeof(visited));
	memset(pre, -1, sizeof(pre));
	head = 0;
	tail = 0;
}
int unsolve(State st)
{
	int res;
	res = inv(st, 9);
	res += dist(st[0]);
	return res & 1; 
}
void push(State e)
{
	int i;
	for(i = 0;i <= 10; i++) q[tail][i] = e[i];
	tail++;
}
void pop(State e)
{
	int i;
	for(i = 0;i <= 10; i++) e[i]= q[head][i];
	head++;
}
int empty() { return head >= tail;}
int check(int cur, int d)
{
	if(cur == 1 && (d == 0 || d == 3)) return 1;
	if(cur == 2 && (d == 0 || d == 2 || d == 3)) return 1;
	if(cur == 3 && (d == 2 || d == 3)) return 1;
	if(cur == 4 && (d == 0 || d == 1 || d == 3)) return 1;
	if(cur == 5 && (d == 0 || d == 1 || d == 2 || d == 3)) return 1;
	if(cur == 6 && (d == 1 || d == 2 || d == 3)) return 1;
	if(cur == 7 && (d == 0 || d == 1)) return 1;
	if(cur == 8 && (d == 0 || d == 1 || d == 2)) return 1;
	if(cur == 9 && (d == 1 || d == 2)) return 1;
	return 0;
}
void move(State s, int di, State t)
{
	int i, j, k;
	for(i = 0;i <= 10; i++) t[i] = s[i];
	i = t[0];
	j = t[0] + d[di];
	k = t[i];
	t[i] = t[j];
	t[j] = k;
	t[0] = j;
}
void bfs(State st)
{
	int i, j, k, p;
	State cur, tmp;
	k = hash(st);
	st[10] = k;
	push(st);
	visited[k] = 1;
	pre[k] = -1;
	while(!empty())
	{
		pop(cur);
		p = cur[0];
		j = cur[10];
		for(i = 0;i < 4; i++)
		{
			if(check(p, i))
			{
				move(cur, i, tmp);
				k = hash(tmp);
				if(visited[k] == 0)
				{
					tmp[10] = k;
					pre[k] = j;
					ans[k] = i;
					visited[k] = 1;
					push(tmp);
				}
				if(k == 0) return;
			}
		}
	}
}
int main()
{
	char m[MAXN];
	int i, j;
	init();
	if(unsolve(st)) printf("unsolvable\n");
	else
	{
		bfs(st);
		i = 0;
		j = 0;
		while(pre[i] != -1)
		{
			m[j++] = str[ans[i]];
			i = pre[i];
		}
		for(i = j - 1;i > 0; i--) printf("%c", m[i]);
		printf("%c\n", m[i]);
	}
	return 0;
}
