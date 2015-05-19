#include <stdio.h>
#define MAX 1002
int a[MAX];
int s[MAX];
int n;
int l;
void init()
{
	int i;
	scanf("%d", &n);
	for(i = 1;i <= n; i++) scanf("%d", &a[i]);
}
void solve()
{
	int mid;
	int st;
	int ed;
	int i;
	s[1] = a[1];
	l = 1;
	for(i = 2;i <= n; i++)
	{
		st = 1;
		ed = l + 1;
		while(ed > st)
		{
			mid = (st + ed) / 2;
			if(a[i] <= s[mid]) ed = mid;
			else st = mid + 1;
		}
		s[ed] = a[i];
		if(ed > l) l = ed;
	}
	printf("%d\n", l);
}
int main()
{
	init();
	solve();
	return 0;
}
