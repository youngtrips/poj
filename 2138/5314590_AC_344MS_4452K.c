#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1002
char dic[MAX][82], ans[82], st[82];
int adj[MAX][MAX], n;
int has[MAX];
int q[MAX], head, tail, x;
int check(char* a, char* b)
{
	int la = strlen(a);
	int lb = strlen(b);
	int flag, i, j, k;
	if(lb - la != 1) return 0;
	j = 0;
	for(i = 0;i < la; i++)
	{
		flag = 0;
		for(;j < lb; j++) if(a[i] == b[j]) { flag = 1; break; }
		if(flag == 0) return 0;
		j++;
	}
	return 1;
}
int cmp(const void* p1, const void* p2)
{
	return strlen((char*)p1) - strlen((char*)p2);
}
void init()
{
       int i, j;
       scanf("%d %s", &n, &st);
       for(i = 1;i <= n; i++) scanf("%s", dic[i]);
       memset(adj, 0, sizeof(adj));
	   qsort((void*)&dic[1], n, sizeof(dic[1]), cmp);
       for(i = 1;i <= n; i++)
       {
               if(!strcmp(dic[i], st)) x = i;
               for(j = i + 1;j <= n; j++)
                       if(check(dic[i], dic[j])) adj[i][j] = 1;
       }
}
void bfs()
{
       int i, j;
       memset(has, 0, sizeof(has));
       has[x] = 1;
       q[0] = x;
       head = 0; tail = 1;
       while(head < tail)
       {
               i = q[head];
               for(j = 1;j <= n; j++)
               {
                       if(adj[i][j] && has[j] == 0)
                       {
                               if(strlen(dic[j]) > strlen(st)) strcpy(st, dic[j]);
                               has[j] = 1;
                               q[tail++] = j;
                       }
               }
               head++;
       }
}
int main()
{
       init();
	   bfs();
	   printf("%s\n", st);
	   return 0;
}
