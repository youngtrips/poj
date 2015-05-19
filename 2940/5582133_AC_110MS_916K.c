#include <stdio.h>
#define MAX 100002
long long a[MAX];
long long sum;
int n;
long long my_abs(long long x) { return x < 0 ? -x : x;}
void solve()
{
	int i;
	sum = 0;
	for(i = 1;i < n; i++)
	{
		sum += my_abs(a[i]);
		a[i+1] += a[i];
	}
	printf("%lld\n", sum);
}
int main()
{
	int i;
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		for(i = 1;i <= n; i++) scanf("%lld", &a[i]);
		solve();
	}
	return 0;
}
