#include <stdio.h>
#include <string.h>
#define MAX 10
char a[MAX];
int main()
{
	int c, n, i, j, l, t;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", a);
		l = strlen(a);
		c = 0;
		for(i = l - 1;i >= 1; i--)
		{
			t = a[i] - '0' + c;
			if(t >= 5) c = 1;
			else c = 0;
			a[i] = '0';
		}
		if(a[0] - '0' + c >= 10)
		{
			a[0] = '0';
			printf("1%s\n", a);
		}
		else
		{
			a[0] += c;
			printf("%s\n", a);
		}
	}
	return 0;
}
