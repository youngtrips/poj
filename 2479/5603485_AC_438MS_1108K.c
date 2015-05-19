#include <stdio.h>
#define MAXN 50002
long long l[MAXN];
long long r[MAXN];
int a[MAXN], n;
void solve()
{
	long long b;
	int i;
	l[1] = a[1]; b = a[1];
	for(i = 2;i <= n; i++)
	{
		if(b > 0) b += a[i];
		else b = a[i];
		l[i] = l[i-1] > b ? l[i-1] : b;
	}
	r[n] = a[n]; b = a[n];
	for(i = n - 1;i >= 1; i--)
	{
		if(b > 0) b += a[i];
		else b = a[i];
		r[i] = r[i+1] > b ? r[i+1] : b;
	}
	b = -500000000ll;
	for(i = 1;i < n; i++) if(b < l[i] + r[i+1]) b = l[i] + r[i+1];
	printf("%lld\n", b);
}
int main()
{
	int t, i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i = 1;i <= n; i++)  scanf("%d", &a[i]);
		solve();
	}
	return 0;
}
