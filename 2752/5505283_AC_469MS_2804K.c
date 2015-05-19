#include <stdio.h>
#include <string.h>
#define MAX 400002
char s[MAX];
int next[MAX];
int ans[MAX];
int len;
int tot;
void init()
{
	int i = 0;
	int j = -1;
	next[0] = -1;
	while(i < len)
	{
		if(j == -1 || s[i] == s[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else j = next[j];
	}
}
void solve()
{
	int i;
	tot = 0;
	i = len;
	while(next[i] != -1)
	{
		ans[++tot] = i;
		i = next[i];
	}
	for(i = tot;i > 1; i--) printf("%d ", ans[i]);
	printf("%d\n", ans[i]);
}
int main()
{
	while(scanf("%s", s) != EOF)
	{
		len = strlen(s);
		init();
		solve();
	}
	return 0;
}
