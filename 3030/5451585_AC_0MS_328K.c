#include <stdio.h>
int main()
{
	int r;
	int e;
	int c;
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d %d", &r, &e, &c);
		e -= c;
		if(r == e) printf("does not matter\n");
		else if(r > e) printf("do not advertise\n");
		else printf("advertise\n");
	}
	return 0;
}
