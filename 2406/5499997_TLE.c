#include <stdio.h>
#include <string.h>
#define MAX 1000002
int next[MAX];
int len;
char s[MAX];
void gen_next(char* t)
{
	len = strlen(t);
	int i = 0;
	int j = -1;
	next[0] = -1;
	while(i < strlen(t))
	{
		if(j == -1 || t[i] == t[j])
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
	int cnt = 0;
	int i = len - 1;
	while(next[i] != -1)
	{
		cnt++;
		i = next[i];
	}
	if(len % cnt != 0) cnt = len;
	printf("%d\n", cnt);
}
int main()
{
	while(1)
	{
		scanf("%s", s);
		if(!strcmp(s, ".")) break;
		gen_next(s);
		solve();
	}
	return 0;
}
