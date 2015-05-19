#include <stdio.h>

#include <math.h>

int main()

{

	int flag;

	int i,n;

	while(scanf("%d",&n) != EOF)

	{

		flag = 0;

		for(i = 0;i < 40; i++)

		{

			if(pow(2,i) == n)

			{

				flag = 1;

				break;

			}

			if(pow(2,i) > n) break;

		}

		if(flag) printf("YES\n");

		else printf("NO\n");

	}

	return 0;

}
