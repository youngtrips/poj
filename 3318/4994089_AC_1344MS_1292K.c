#include <stdio.h>
#define bool int
#define true 1
#define false 0

int A[500][500];

int main()

{

	int v,n,i,j,tmp;

	int r1[500],r2[500],X[500];

	bool flag = true;

	scanf("%d",&n);

	for(i = 0;i < n; i++)

	{

		X[i] = rand() % n + 1;

		for(j = 0;j < n; j++)

			scanf("%d",&A[i][j]);

	}

	for(i = 0;i < n; i++)

	{

		tmp = 0;

		for(j = 0;j < n; j++)

		{

			scanf("%d",&v);

			tmp += v * X[j];

		}

		r1[i] = tmp;

	}

	for(i = 0;i < n; i++)

	{

		tmp = 0;

		for(j = 0;j < n; j++)

		{

			scanf("%d",&v);

			tmp += v * X[j];

		}

		r2[i] = tmp;

	}

	for(i = 0;i < n; i++)

	{

		tmp = 0;

		for(j = 0;j < n; j++)

			tmp += A[i][j] * r1[j];

		X[i] = tmp;

	}

	for(i = 0;i < n; i++)

	{

		if(r2[i] != X[i])

		{

			flag = false;

			break;

		}

	}

	if(flag)

		printf("YES\n");

	else

		printf("NO\n");

	return 0;

}

