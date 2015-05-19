#include <stdio.h>

#include <math.h>

#include <string.h>

int cmp(const void* p1,const void * p2)

{

	long t= *((long *)p1)-*((long *)p2);

	if (t>0) return 1;

	else if(t==0) return 0;

	else return -1;

}

int check(int start,int end,int set[])

{

	int i;

	int sum = 0;

	for(i = start;i <= end; i++)

		sum += set[i];

	sum /= (end - start + 1);

	for(i = start;i <= end; i++)

	{

		if(abs(sum - set[i]) > 2)

			return 0;

	}

	return 1;

}

int main()

{

	int d;

	int cases = 0;

	char name[1000][81];

	int len[1000];

	int n,k,i,j, flag;
	scanf("%d %d", &n, &k);

	while(n != 0 || k != 0)

	{

		cases++;

		for(i = 0;i < n; i++)

		{
			scanf("%s", name[i]);

			len[i] = strlen(name[i]);

		}

		qsort((void*)&len[0],n,sizeof(len[0]),cmp);

		if(n == k)

		{

			if(check(0,n-1,len) == 1) printf("Case %d: yes\n", cases);

			else printf("Case %d: no\n", cases);

		}

		else

		{

			flag = 1;

			for(i = 0;i < n / k; i++)

			{

				if(check(i * k,i * k + k - 1,len) == 0)

				{
					printf("Case %d: no\n", cases);

					flag = 0;

					break;

				}

			}

			if(flag == 1) printf("Case %d: yes\n", cases);

		}
		printf("\n");
		scanf("%d %d", &n, &k);

	}

	return 0;

}

