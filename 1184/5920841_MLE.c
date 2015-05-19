#include <stdio.h>
#include <string.h>
#define MAXN 8000002
typedef struct
{
	int code[8];
	int key;
}node_t;
node_t que[MAXN];
node_t st, ed;
int dist[MAXN];
int head;
int tail;

int hash(node_t node)
{
	int res = 0, i;
	for(i = 0;i <= 6; i++) res = res * 10 + node.code[i];
	return res;
}
void init()
{
	char a[8], b[8];
	int i;
	scanf("%s %s", a, b);
	for(i = 1;i <= 6; i++)
	{
		st.code[i] = a[i-1] - '0';
		ed.code[i] = b[i-1] - '0';
	}
	st.code[0] = 1;
}
node_t mv(node_t cur, int dir)
{
	node_t nxt;
	int tmp, i;
	memcpy(&nxt, &cur, sizeof(nxt));
	i = nxt.code[0];
	if(dir == 0 && i != 1) /* Swap0 */
	{
		tmp = nxt.code[i];
		nxt.code[i] = nxt.code[1];
		nxt.code[1] = tmp;
	}
	if(dir == 1 && i != 6) /* Swap1 */
	{
		tmp = nxt.code[i];
		nxt.code[i] = nxt.code[6];
		nxt.code[6] = tmp;
	}
	if(dir == 2 && nxt.code[i] != 9) /* Up */
		nxt.code[i]++;
	if(dir == 3 && nxt.code[i] != 0) /* Down */
		nxt.code[i]--;
	if(dir == 4 && i != 1) /* Left */
		nxt.code[0]--;
	if(dir == 5 && i != 6) /* Right */
		nxt.code[0]++;
	return nxt;
}
int check(node_t cur)
{
	int i;
	for(i = 1;i <= 6; i++) if(ed.code[i] != cur.code[i]) return 0;
	return 1;
}
void bfs()
{
	node_t cur, nxt;
	int i, k;
	memset(dist, -1, sizeof(dist));
	dist[hash(st)] = 0;
	que[0] = st;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		cur = que[head];
		k = dist[cur.key];
		for(i = 0;i < 6; i++)
		{
			nxt = mv(cur, i);
			nxt.key = hash(nxt);
			if(dist[nxt.key] == -1)
			{
				dist[nxt.key] = k + 1;
				if(check(nxt))
				{
					printf("%d\n", dist[nxt.key] + 1);
					return;
				}
				que[tail++] = nxt;
			}
		}
		head++;
	}
}
int main()
{
	init();
	bfs();
	return 0;
}
