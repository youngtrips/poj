#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10002
char tel[MAX][11];
char ans[2][4] = {"NO", "YES"};
int cmp(const void* p1, const void* p2){return strcmp((char*)p1, (char*)p2);}
int check(int n)
{
	int i, j, l;
	if(n == 1) return 1;
	l = strlen(tel[0]);
	for(i = 0;i < l; i++) if(tel[0][i] != tel[1][i]) return 1;
	return 0;
}
int main()
{
	int t, i, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i = 0;i < n; i++) scanf("%s", tel[i]);
		qsort((void*)tel, n, sizeof(tel[0]), cmp);
		printf("%s\n", ans[check(n)]);
	}
	return 0;
}
