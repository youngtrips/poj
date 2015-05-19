#include <stdio.h>

int main()

{

	int i,p,t,n,num;

	char name[11];

	while(scanf("%d %d",&t,&n) == 2)

	{

		if(t == 0) break;

		num = 0;

		for(i = 0;i < t;i++)

		{

			scanf("%s %d",name,&p);

			num += p;

		}

		num = n + n + n - num;

		printf("%d\n",num);

	}

	return 0;

}
