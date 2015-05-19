#include <stdio.h>

#include <math.h>

int main()

{

	int n,b,r;

	while(1)

	{
		scanf("%d %d", &b, &n);
		if(b == 0 && n == 0) break;

		r = pow(b,1.0/n);

		if(b - (pow(r,n)) > (pow(r+1,n) - b)) printf("%d\n", r + 1);

		else printf("%d\n", r);

	}

	return 0;

}
