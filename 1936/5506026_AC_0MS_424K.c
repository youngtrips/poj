#include <stdio.h>
#include <string.h>
#define MAX 100002
char s[MAX];
char t[MAX];
int check()
{
	int len_s = strlen(s);
	int len_t = strlen(t);
	int i = 0;
	int j = 0;
	if(len_s > len_t) return 0;
	while(i < len_s && j < len_t)
	{
		if(s[i] == t[j]) { i++; j++;}
		else j++;
	}
	return i >= len_s;
}
int main()
{
	while(scanf("%s %s", s, t) != EOF) printf("%s\n", check() == 1 ? "Yes":"No");
	return 0;
}
