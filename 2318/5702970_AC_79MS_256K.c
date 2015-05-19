#include <stdio.h>
#include <string.h>
#define MAXN 5002
typedef struct
{
	int x_u, y_u;
	int x_l, y_l;
}board_t;
board_t bd[MAXN];
int cnt[MAXN];
int x1, y1, x2, y2, n, m;
int cross(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - x2 * y1;
}
int init()
{
	int ui, li, i, j;
	scanf("%d", &n);
	if(n == 0) return 0;
	scanf("%d %d %d %d %d", &m, &x1, &y1, &x2, &y2);
	j = 1;
	bd[j].x_u = x1; bd[j].y_u = y1;
	bd[j].x_l = x1; bd[j].y_l = y2;
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d", &ui, &li);
		++j;
		bd[j].x_u = ui; bd[j].y_u = y1;
		bd[j].x_l = li; bd[j].y_l = y2;
	}
	++j;
	bd[j].x_u = x2; bd[j].y_u = y1;
	bd[j].x_l = x2; bd[j].y_l = y2;
	n = j;
	return 1;
}
int find(int x, int y)
{
	int high = n;
	int low = 0;
	int mid;
	int u;
	while(low < high)
	{
		mid = (low + high)>>1;
		u = cross(x - bd[mid].x_l, y - bd[mid].y_l, bd[mid].x_u - bd[mid].x_l, bd[mid].y_u - bd[mid].y_l);
		if(u < 0) high = mid;
		else low = mid + 1;
	}
	return low;
}
void solve()
{
	int x, y, i;
	memset(cnt, 0, sizeof(cnt));
	while(m--)
	{
		scanf("%d %d", &x, &y);
		i = find(x, y);
		if(i > n) i--;
		cnt[i]++;
	}
	for(i = 2;i <= n; i++) printf("%d: %d\n", i - 2, cnt[i]);
	printf("\n");
}
int main()
{
	while(init()) { solve();}
	return 0;
}
