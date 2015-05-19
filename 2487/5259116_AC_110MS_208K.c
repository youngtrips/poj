#include <stdio.h>
#include <stdlib.h>
#define MAX 1002
int a[MAX];
int cmp(const void* p1, const void* p2) {return *(int*)p2 - *(int*)p1;}
int main()
{
	int need, t, s, i, n;
	scanf("%d", &t);
	for(s = 1;s <= t; s++)
	{
		scanf("%d %d", &need, &n);
		for(i = 0;i < n; i++) scanf("%d", a + i);
		printf("Scenario #%d:\n", s);
		qsort((void*)a, n, sizeof(a[0]), cmp);
		for(i = 0;i < n; i++)
		{
			need -= a[i];
			if(need <= 0) break;
		}
		if(need > 0) printf("impossible\n");
		else printf("%d\n", i + 1);
		printf("\n");
	}
	return 0;
}
