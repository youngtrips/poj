#include <stdio.h>
int main()
{
	int f, a[3], i;
	while(scanf("%d %d %d", &a[0], &a[1], &a[2]) != EOF)
	{
		f = 0;
		for(i = 0;i < 3; i++) if(a[i] <= 168) { f = 1; break;}
		if(f == 0) printf("NO CRASH\n");
		else printf("CRASH %d\n", a[i]);
	}
	return 0;
}
