#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#define MAX 202
using namespace std;
typedef struct
{
	char chip[MAX];
	int c;
}stat;
char s1[MAX], s2[MAX], st[MAX], ed[MAX];
set <char*> has;
pair< set<char*>::iterator, bool> p;
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
int bfs(char* st, char* ed)
{
	int k;
	stat e, t1, t2, t12;
	queue<stat> q;
	strcpy(e.chip, st);
	e.c = 1;
	q.push(e);
	has.insert(st);
	while(!q.empty())
	{
		e = q.front();
		k = e.c;
		if(!strcmp(e.chip, ed)) return k;
		split(e.chip, t1.chip, t2.chip);
		form(t1.chip, t2.chip, t12.chip);
		p = has.insert(t12.chip);
		if(p.second)
		{
			t12.c = k + 1;
			q.push(t12);
		}
		q.pop();
	}
	return -1;
}
int main()
{
	int res, t, i;
	scanf("%d", &t);
	for(i = 1;i <= t; i++)
	{
		scanf("%d", &c);
		scanf("%s", s1);
		scanf("%s", s2);
		scanf("%s", ed);
		form(s1, s2, st);
		res = bfs(st, ed);
		printf("%d %d\n", i, res);
	}
	return 0;
}
