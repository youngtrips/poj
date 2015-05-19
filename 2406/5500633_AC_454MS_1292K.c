#include <stdio.h>
#include <string.h>
#define MAX 1000002
char s[MAX];
void solve()
{
	int flag;
	int ans;
	int cnt;
	int len;
	int i, j, k;
	len = strlen(s);
	ans = 0;
	for(k = 1;k <= len; k++)
	{
		if(len % k == 0)
		{
			for(i = 0;i <= len - k; i+= k)
			{
				flag = 1;
				for(j = 0;j < k; j++)
					if(s[i+j] != s[j]) { flag = 0; break;}
				if(flag == 0) break;
			}
			if(flag)
			{
				cnt = len / k;
				if(ans < cnt) ans = cnt;
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
	while(1)
	{
		gets(s);
		if(s[0] == '.') break;
		solve();
	}
	return 0;
}
