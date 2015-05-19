#include <stdio.h>
#include <string.h>
#define ABS(x) {return(x)<0?(-x):(x);}
#define MAX 10002
char dic[MAX][28];
char word[28];
int n;
int check(char* str, char* sub)
{
	int l1 = strlen(str);
	int l2 = strlen(sub);
	int i, j;
	for(i = 0, j = 0; i < l1 && j < l2;)
	{
		if(str[i] == sub[j]) { i++; j++;}
		else i++;
	}
	return j >= l2;
}
int miss()
{
	int l1, l2, i, j, k;
	l1 = strlen(word);
	for(i = 1;i <= n; i++)
	{
		l2 = strlen(dic[i]);
		if(l1 == l2)
		{
			k = 0;
			for(j = 0;j < l1; j++) if(dic[i][j] != word[j]) k++;
			if(k == 1) return i;
			if(k == 2)
			{
				for(j = 0;j < l1; j++)
				{
					if(dic[i][j] != word[j]) break;
				}
				if(j + 1 < l1 && dic[i][j] == word[j+1] && dic[i][j+1] == word[j]) return i;
			}
		}
		if(l1 - l2 == 1 && check(word, dic[i])) return i;
		if(l2 - l1 == 1 && check(dic[i], word)) return i;
	}
	return -1;
}
void solve()
{
	int flag, i, j, p;
	flag = -1;
	for(i = 1;i <= n; i++) if(!strcmp(dic[i], word)) { flag = 1; break;}
	if(flag == 1) printf("%s is correct\n", word);
	else
	{
		flag = miss();
		if(flag == -1) printf("%s is unknown\n", word);
		else printf("%s is a misspelling of %s\n", word, dic[flag]);
	}
}
int main()
{
	int m, i, j;
	scanf("%d", &n);
	for(i = 1;i <= n; i++) scanf("%s", dic[i]);
	scanf("%d", &m);
	while(m--)
	{
		scanf("%s", word);
		solve();
	}
	return 0;
}
