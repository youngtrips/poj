#include <stdio.h>
#include <math.h>
#define MAX 10002
#define eps 1e-6
#define pi acos(-1.0)
double sum;
double s[MAX];
int n, f;
void init()
{
	int i, r;
	scanf("%d %d", &n, &f);
	sum = 0.0;
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &r);
		sum += pi * r * r * 1.0;
		s[i] = pi * r * r * 1.0;
	}
}
int check(double try_v)
{
	int cnt, i;
	cnt = 0;
	for(i = 1;i <= n; i++) cnt += int(s[i] / try_v);
	return cnt < (f + 1);
}
void solve()
{
	double mid, s, t;
	s = 0; t = sum;
	while(s + eps < t)
	{
		mid = (s + t) / 2.0;
		if(check(mid)) t = mid;
		else s = mid;
	}
	printf("%0.6f\n", s);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		solve();
	}
	return 0;
}
