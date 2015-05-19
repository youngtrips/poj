#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXN 5002
char face[MAXN];
char tmp[MAXN];
int n;
int check(int k)
{
	int cnt, i;
	memcpy(tmp, face, n);
	cnt = 0;
	for(i = 0;i <= n - k; i++)
	{
		cnt += tmp[i];
		tmp[i + k] ^= tmp[i];
	}
	while(i < n) if(tmp[i++]) return oo;
	return cnt;
}
int main()
{
	char ch, t;
	int mink, minn, res, i;
	scanf("%d", &n);
	getchar();
	ch = 'F';
	for(i = 0;i < n; i++)
	{
		face[i] = 0;
		t = getchar();getchar();
		if(t != ch)
		{
			ch = t;
			face[i] = 1;
		}
	}
	minn = oo;
	for(i = 1;i <= n; i++)
	{
		res = check(i);
		if(res < minn)
		{
			mink = i;
			minn = res;
		}
	}
	printf("%d %d\n", mink, minn);
	return 0;
}
