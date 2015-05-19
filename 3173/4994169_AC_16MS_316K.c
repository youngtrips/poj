#include <stdio.h>

char triangle[20][20];

void gen(int n,int s)

{

	int i,j;

	for(j = 0;j < n; j++)

	{

		for(i = 0;i < n; i++)

		{

			if(i <= j)

			{

				triangle[i][j] = (s % 10) + '0';

				s++;

				if(s % 10 == 0) s = 1;

			}

		}

	}

}

void out(char str[][20],int n)

{
	int i, j;

	for(i = 0;i < n; i++)

	{

		for(j = 0;j < n-1; j++)
			printf("%c ", str[i][j]);
		printf("%c\n", str[i][n-1]);		

	}

}
int main()

{

	int n,s;

	while(scanf("%d %d", &n, &s) != EOF)

	{

		memset(triangle,' ',sizeof(triangle));

		gen(n,s);

		out(triangle,n);

	}

	return 0;

}
