#include <stdio.h>
#include <string.h>
#define MAXN 1002
#define MAXM 32
char list[MAXN][MAXM];
int cnt;
int insert(char* key)
{
	int i;
	for(i = 0;key[i] != '\0'; i++) if(key[i] >= 'A' && key[i] <= 'Z') key[i] += 32;
	for(i = 1;i <= cnt; i++) if(!strcmp(key, list[i])) return 0;
	strcpy(list[++cnt], key);
	return 1;
}
int is_alph(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int gcd(int a, int b)
{
	int r = a % b;
	while(r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int main()
{
	char word[MAXM];
	int n, m, i, k;
	char ch;
	ch = getchar();
	cnt = 0; k = 0;
	n = 0; m = 0;
	while(ch != EOF)
	{
		i = 0;
		while(is_alph(ch) == 0 && ch != EOF) ch = getchar();
		while(is_alph(ch) == 1)
		{
			word[i++] = ch;
			ch = getchar();
		}
		word[i] = '\0';
		if(!strcmp("BULLSHIT", word)) 
		{
			m += k;	
			n++; 
			cnt = 0;
			k = 0;
		}
		else if(insert(word)) k++;
		ch = getchar();
	}
	k = gcd(m, n);
	printf("%d / %d\n", m / k, n / k);
	return 0;
}
