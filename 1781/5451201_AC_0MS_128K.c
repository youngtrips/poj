#include <stdio.h>
int n;
int init()
{
	char ch;
	int k;
	ch = getchar(); n = ch - '0';
	ch = getchar(); n = n * 10 + ch - '0';
	getchar();
	ch = getchar(); k = ch - '0';
	getchar();
	while(k--) n *= 10;
	return n != 0;
}
void solve()
{
	int mask;
	int tmp;
	int k;
	tmp = n;
	k = 0;
	while(tmp)
	{
		k++;
		tmp >>= 1;
	}
	mask = 1<<k;
	n <<= 1;
	n = (n ^ mask) | 1;
}
int main()
{
	while(init())
	{
		solve();
		printf("%d\n", n);
	}
	return 0;
}
