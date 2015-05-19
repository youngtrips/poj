#include <stdio.h>
#include <string.h>
#define MAX 8
char str[MAX];
int  ans;
int n;
int init()
{
	int i;
	scanf("%s", str);
	if(!strcmp(str, "00e0")) return 0;
	n = str[0] - '0';
	n = n * 10 + str[1] - '0';
	for(i = 0;i < str[3] - '0'; i++) n *= 10;
	return 1;
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
	ans = (n ^ mask) | 1;
}
int main()
{
	while(init())
	{
		solve();
		printf("%d\n", ans);
	}
	return 0;
}
