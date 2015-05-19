#include <stdio.h>

#include <memory.h>

int a[351][351];

int travel(int n)

{

	int i,j;

	for(i = n-1;i >= 1; i--)

	{

		for(j = 0;j < n; j++)

		{

			if(a[i][j] + a[i-1][j] > a[i-1][j] + a[i][j+1]) a[i-1][j] = a[i][j] + a[i-1][j];

			else a[i-1][j] = a[i-1][j] + a[i][j+1];

		}

	}

	return a[0][0];

}

int main()

{

	int n,i,j;

	memset(a,0,sizeof(a));

	scanf("%d",&n);

	for(i = 0;i < n; i++)

		for(j = 0;j <= i; j++)

			scanf("%d",&a[i][j]);

	printf("%d\n",travel(n));

	return 0;

}
