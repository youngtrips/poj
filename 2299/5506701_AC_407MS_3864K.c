#include <stdio.h>
#define MAX 500002
long long cnt;
int a[MAX];
int b[MAX];
int n;
int init()
{
	int i;
	scanf("%d", &n);
	if(n == 0) return 0;
	for(i = 1;i <= n; i++) scanf("%d", &a[i]);
	cnt = 0;
	return 1;
}
void merge(int s, int m, int t)
{
	int j = m + 1;
	int i = s;
	int k = 0;
	while(i <= m && j <= t)
	{
		if(a[i] <= a[j]) b[k++] = a[i++];
		else
		{
			cnt += m - i + 1;
			b[k++] = a[j++];
		}
	}
	while(i <= m) b[k++] = a[i++];
	while(j <= t) b[k++] = a[j++];
	for(i = 0;i < k; i++) a[s + i] = b[i];
}
void merge_sort(int s, int t)
{
	int m;
	if(s < t)
	{
		m = (s + t) / 2;
		merge_sort(s, m);
		merge_sort(m + 1, t);
		merge(s, m, t);
	}
}
void solve()
{
	int i;
	merge_sort(1, n);
	printf("%lld\n", cnt);
}
int main()
{
	while(init()) solve();
	return 0;
}
