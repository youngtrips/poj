#include <stdio.h>
int matrix[100][100];
int pi,pj;
int check(int matrix[][100],int n)
{
	int nr,nc,i,j,tmp;
	nr = 0;
	nc = 0;
	for(i = 0;i < n; i++)
	{
		tmp = 0;
		for(j = 0;j < n; j++) tmp += matrix[i][j];
		if(tmp % 2 != 0)
		{
			pi = i;
			nr++;
		}
	}
	for(j = 0;j < n; j++)
	{
		tmp = 0;
		for(i = 0;i < n; i++) tmp += matrix[i][j];
		if(tmp % 2 != 0)
		{
			pj = j;
			nc++;
		}
	}
	if(nr == 0 && nc == 0) return 1;
	else if(nr == 1 && nc == 1) return 0;
	else return -1;
}
int main()
{
	int n,i,j;
	while(scanf("%d",&n) == 1)
	{
		if(n == 0) break;
		for(i = 0;i < n; i++)
			for(j = 0;j < n; j++) scanf("%d",&matrix[i][j]);
		i = check(matrix,n);
		if(i == 1) printf("OK\n");
		else if(i == 0) printf("Change bit (%d,%d)\n",pi+1,pj+1);
		else if(i == -1) printf("Corrupt\n");
	}
	return 0;
}
