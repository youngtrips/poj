#include <stdio.h>

unsigned long long mod_exp(unsigned long long a,unsigned long long b,unsigned long long n)

{

	unsigned long long t;

	unsigned long long y;

	t = 1;

	y = a;

	while(b != 0)

	{

		if(b % 2 == 1)

			t = t * y % n;

		y = y * y % n;

		b = b / 2;

	}

	return t;

}



int is_prime(unsigned long long x)

{

	unsigned long long i;

	if(x % 2 == 0)

		return 0;

	for(i = 2;i * i <= x; i++)

		if(x % i == 0)

			return 0;

	return 1;

}

int main()

{

	unsigned long long a;

	unsigned long long p;

	while(scanf("%lld %lld",&p,&a) != EOF)

	{

		if(p == 0 && a == 0)

			break;

		if(is_prime(p))

			printf("no\n");

		else 

		{

			if(mod_exp(a,p,p) == a)

				printf("yes\n");

			else

				printf("no\n");

		}

	}

	return 0;

}

