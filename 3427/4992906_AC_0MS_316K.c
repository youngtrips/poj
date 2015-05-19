#include <stdio.h>

int heigth[30001];

int main()

{

	int n,l,i,j,min,year,tmp;

	while(scanf("%d %d",&n,&l) != EOF)

	{

		for(i = 0;i < n; i++)

			scanf("%d",&heigth[i]);

		min = 2147483641;

		for(i = 1;i <= l; i++)

		{

			tmp = 0;

			for(j = 0;j < n; j++)

			{

				tmp += heigth[j] % l;

				heigth[j]++;

			}

			if(min >= tmp)

			{

				min = tmp;

				year = i;

			}

		}

		printf("%d\n",year-1);

	}

	return 0;

}


