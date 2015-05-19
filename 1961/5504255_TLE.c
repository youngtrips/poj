#include <stdio.h>
#include <string.h>
#define MAX 1000002
char str[MAX];
char sub[MAX];
int next[MAX];
int n;
int t;
int find(char* s, int len)
{
	int i = 0;
	int j = -1;
	memset(next, 0, sizeof(next));
	next[0] = -1;
	while(i < len)
	{
		if(j == -1 || s[i] == s[j])
	   	{
		   	i++; 
			j++;
			if(s[i] != s[j]) next[i] = j;
			else next[i] = next[j];
		}
		else j = next[j];
	}
	i = len - next[len];
	if(len % i == 0) return len / i;
	return 1;
}
void solve()
{
	int i, j;
	strcpy(sub, str);
	printf("Test case #%d\n", t++);
	for(i = 2;i <= n; i++)
	{
		sub[i] = '\0';
		j = find(sub, i);
		if(j > 1) printf("%d %d\n", i, j);
		sub[i] = str[i];
	}
	printf("\n");
}
int main()
{
	t = 1;
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		scanf("%s", str);
		solve();
	}
	return 0;
}
