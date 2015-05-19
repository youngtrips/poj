#include <stdio.h>
#define MAX 1000002
int next[MAX];
char s[MAX];
int len;
int t;
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
	int i, j, k;
	printf("Test case #%d\n", t++);
	for(i = 2;i <= len; i++)
	{
		j = i - next[i];
		if(i % j == 0)
		{
			k = i / j;
			if(k > 1) printf("%d %d\n", i, k);
		}
	}
	printf("\n");
}
int main()
{
	int i;
	t = 1;
	while(1)
	{
		scanf("%d", &len);
		if(len == 0) break;
		scanf("%s", s);
		init();
		solve();
	}
	return 0;
}
