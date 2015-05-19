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
int find(int mid)
{
	int tmp = money[1];
	int cnt = 1;
	int i;
	if(mid < money[1]) return 0;
	for(i = 2;i <= n; i++)
	{
		if(tmp + money[i] <= mid) tmp += money[i];
		else
		{
			if(mid < money[i]) return 0;
			cnt++;
			tmp = money[i];
		}
	}
	return cnt <= m;
}
void solve()
{
	int high;
	int flag;
	int low;
	int mid;
	int tmp;
	int cnt;
	int i;
	low = 0;
	high = money[0];
	while(low < high)
	{
		mid = (low + high)>>1;
		if(find(mid)) high = mid - 1;
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
