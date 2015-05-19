#include <stdio.h>
#include <string.h>
#define MAXL 64
#define MAXN 11
char dna[MAXN][MAXL];
char sub[MAXL];
char ans[MAXL];
int next[MAXL];
int n;
void gen_next(char* t)
{
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
int kmp(char* s, char* t, int pos)
{
	int len_s = strlen(s);
	int len_t = strlen(t);
	int i = pos;
	int j = 0;
	while(i < len_s && j < len_t)
	{
		if(j == -1 || s[i] == t[j]) { i++; j++;}
		else j = next[j];
	}
	if(j >= len_t) return i - len_t;
	return -1;
}
void solve()
{
	int len = strlen(dna[1]);
	int flag;
	int max;
	int st;
	int i, j, k;
	int p, q;
	ans[0] = '\0';
	max = 0;
	for(k = 1;k <= strlen(dna[1]); k++)
	{
		for(i = 0;i < len - k; i++)
		{
			for(p = 0, j = i;p < k; j++, p++) sub[p] = dna[1][j];
			sub[p] = '\0';
			gen_next(sub);
			flag = 1;
			for(j = 2;j <= n; j++) 
			{
				if(kmp(dna[j], sub, 0) == -1) 
				{ 
					flag = 0; 
					break;
				}
			}
			if(flag)
			{
				if(max < k)
				{
					strcpy(ans, sub);
					max = k;
				}
				else if(max == k)
					if(strcmp(sub, ans) < 0) strcpy(ans, sub);
			}
		}
	}
	if(max < 3) printf("no significant commonalities\n");
	else printf("%s\n", ans);
}
int main()
{
	int s, i;
	scanf("%d", &s);
	while(s--)
	{
		scanf("%d", &n);
		getchar();
		for(i = 1;i <= n; i++) gets(dna[i]);
		solve();
	}
	return 0;
}
