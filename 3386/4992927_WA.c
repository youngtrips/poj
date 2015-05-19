#include <stdio.h>

typedef struct

{

	int r1;

	int r2;

}ring;

int check(ring a,ring b,int p)

{

	if(a.r1 > b.r1)

	{

		if(p >= a.r1 && a.r2 >= b.r1) 1;

		else if(a.r1 + b.r1 <= p) 1;

		else 0;

	}

	else

	{

		if(p >= b.r1 && b.r2 >= a.r1) 1;

		else if(a.r1 + b.r1 <= p) 1;

		else 0;

	}

}

int main()

{

	ring a,b;

	int p;

	while(scanf("%d %d %d %d %d",&a.r1,&a.r2,&b.r1,&b.r2,&p) != EOF)

	{

		if(check(a,b,p))

			printf("Yes\n");

		else

			printf("No\n");

	}

	return 0;

}
