#include <stdio.h>
#include <string.h>
#define MAXN 26
typedef struct
{
	char word[MAXN];
	char replace[MAXN];
}list_t;
list_t list[MAXN];
char cur[MAXN], tmp[MAXN];
int l, n;
int main()
{
	int i, j;
	scanf("%d %d", &l, &n);
	for(i = 1;i <= l; i++) scanf("%s %s", list[i].word, list[i].replace);
	for(i = 1;i <= n; i++)
	{
		scanf("%s", cur);
		for(j = 1;j <= l; j++) if(!strcmp(cur, list[j].word)) break;
		if(j <= l) printf("%s\n", list[j].replace);
		else
		{
			strcpy(tmp, cur);
			j = strlen(cur) - 1;
			if(cur[j] == 'y')
			{
				if(cur[j-1] != 'a' && cur[j-1] != 'e' && cur[j-1] != 'i' && cur[j-1] != 'o' && cur[j-1] != 'u')
				{
					tmp[j] = 'i'; tmp[j+1] = 'e'; tmp[j+2] = 's'; tmp[j+3] = '\0';
				}
				else
				{
					tmp[j+1] = 's'; tmp[j+2] = '\0';
				}
			}
			else if(cur[j] == 'o' || cur[j] == 's' || cur[j] == 'x')
			{
				tmp[j+1] = 'e'; tmp[j+2] = 's'; tmp[j+3] = '\0';
			}
			else if((cur[j-1] == 'c' && cur[j] == 'h') || (cur[j-1] == 's' && cur[j] == 'h'))
			{
				tmp[j+1] = 'e'; tmp[j+2] = 's'; tmp[j+3] = '\0';
			}
			else
			{
				tmp[j+1] = 's'; tmp[j+2] = '\0';
			}
			printf("%s\n", tmp);
		}
	}
	return 0;
}
