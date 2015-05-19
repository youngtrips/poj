#include <stdio.h>
#include <string.h>
#define MAX 202
char s1[MAX], s2[MAX], st[MAX], ed[MAX], s12[MAX];
int c;
void form(char* s1, char* s2, char* s12)
{
	int i, j;
	for(i = 0, j = 0;i < c; i++, j += 2) s12[j] = s2[i];
	for(i = 0, j = 1;i < c; i++, j += 2) s12[j] = s1[i];
	s12[c + c] = '\0';
}
void split(char*  s12, char* s1, char* s2)
{
	int i, j;
	for(i = 0;i < c; i++) s1[i] = s12[i];
	s1[i] = '\0';
	for(j = 0;j < c; j++, i++) s2[j] = s12[i];
	s2[j] = '\0';
}
int main()
{
	int cnt, t, i;
	scanf("%d", &t);
	for(i = 1;i <= t; i++)
	{
		scanf("%d", &c);
		scanf("%s", s1);
		scanf("%s", s2);
		scanf("%s", ed);
		form(s1, s2, st);
		if(!strcmp(st, ed)) cnt = 1;
		else
		{
			cnt = 1;
			strcpy(s12, st);
			while(1)
			{
				cnt++;
				split(s12, s1, s2);
				form(s1, s2, s12);
				if(!strcmp(s12, st)) { cnt = -1; break;}
				if(!strcmp(s12, ed)) break;
			}
		}
		printf("%d %d\n", i, cnt);
	}
	return 0;
}
