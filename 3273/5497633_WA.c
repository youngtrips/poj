#include <stdio.h>
#define MAX 100002
int money[MAX];
int n, m;
void init()
{
	int i;
	scanf("%d %d", &n, &m);
	money[0] = 0;
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &money[i]);
		money[0] += money[i];
	}
}
void solve()
{
	int high;
	int low;
	int mid;
	int tmp;
	int cnt;
	int i;
	low = 0;
	high = money[0];
	while(low + 1 < high)
	{
		mid = (low + high) / 2;
		tmp = 0;
		cnt = 0;
		for(i = 1;i <= n; i++)
		{
			if(tmp + money[i] <= mid) tmp += money[i];
			else
			{
				tmp = money[i];
				cnt++;
			}
			if(i == n && tmp <= mid)
			{
				cnt++;
			}
			if(cnt > m) break;
		}
		if(cnt < m) high = mid - 1;
		else low = mid;
	}
	printf("%d\n", mid);
}
int main()
{
	init();
	solve();
	return 0;
}
