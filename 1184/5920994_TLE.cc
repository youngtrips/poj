#include <stdio.h>
#include <string.h>
#include <queue>
#define MAXN 1000002
using namespace std;
struct node_t
{
	int code;
	int step;
	int px;
};
node_t st, ed;
char hash[MAXN][6];
void init()
{
	char a[8], b[8];
	int res, i;
	scanf("%s %s", a, b);
	for(res = 0, i = 0;i < 6; i++) res = res * 10 + a[i] - '0';
	st.code = res;
	st.step = 0;
	st.px = 0;
	for(res = 0, i = 0;i < 6; i++) res = res * 10 + b[i] - '0';
	ed.code = res;
}
node_t mv(node_t cur, int dir)
{
	node_t nxt;
	int num[6], tmp, px, i;
	memset(num, 0, sizeof(num));
	tmp = cur.code;
	px = cur.px;
	i = 5;
	while(tmp > 0)
	{
		num[i--] = tmp % 10;
		tmp /= 10;
	}
	if(dir == 0 && px != 0) /* Swap0 */
	{
		tmp = num[px];
		num[px] = num[0];
		num[0] = tmp;
	}
	if(dir == 1 && px != 5) /* Swap1 */
	{
		tmp = num[px];
		num[px] = num[5];
		num[5] = tmp;
	}
	if(dir == 2 && num[px] != 9) /* Up */
		num[px]++;
	if(dir == 3 && num[px] != 0) /* Downn */
		num[px]--;
	if(dir == 4 && px != 0) /* Left */
		px--;
	if(dir == 5 && px != 5) /* Right */
		px++;
	for(tmp = 0, i = 0;i < 6; i++) tmp = tmp * 10 + num[i];
	nxt.code = tmp;
	nxt.step = cur.step + 1;
	nxt.px = px;
	return nxt;
}
void bfs()
{
	queue < node_t > q;
	node_t cur, nxt;
	int i, j, k;
	memset(hash, 0, sizeof(hash));
	hash[st.code][st.px] = 1;
	q.push(st);
	while(!q.empty())
	{
		cur = q.front();
		for(i = 0;i < 6; i++)
		{
			nxt = mv(cur, i);
			if(hash[nxt.code][nxt.px] == 0)
			{
				hash[nxt.code][nxt.px] = 1;
				if(nxt.code == ed.code)
				{
					printf("%d\n", nxt.step);
					return;
				}
				q.push(nxt);
			}
		}
		q.pop();
	}
}
int main()
{
	init();
	bfs();
	return 0;
}
