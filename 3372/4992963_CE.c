#include <stdio.h>

#include <math.h>

int main()

{

	bool flag;

	int i,n;

	while(scanf("%d",&n) != EOF)

	{

		flag = false;

		for(i = 0;i < 40; i++)

		{

			if(pow(2,i) == n)

			{

				flag = true;

				break;

			}

			if(pow(2,i) > n) break;

		}

		if(flag) printf("YES\n");

		else printf("NO\n");

	}

	return 0;

}

