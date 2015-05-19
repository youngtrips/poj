#include <stdio.h>
#include <string.h>
#define MAX 1000002
char s[MAX];
int next[MAX];
int solve()
{
	int len = strlen(s);
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
	i = len - next[len];
	if(len % i == 0) i = len / i;
	else i = 1;
	printf("%d\n", i);
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
