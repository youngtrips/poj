#include <stdio.h>

#include <stdlib.h>

int cmp(const void* p1,const void * p2)

{

	long t= *((long *)p1)-*((long *)p2);

	if (t>0) return 1;

	else if(t==0) return 0;

	else return -1;

}

int main()

{

	int i;

	int scores[100];

	int score;

	int n;

	scanf("%d",&n);

	while(n != 0)

	{

		score = 0;

		for(i = 0;i < n; i++)

		{

			scanf("%d",&scores[i]);

			score += scores[i];

		}

		qsort((void*)&scores[0],n,sizeof(scores[i]),cmp);

		score = score - scores[0] - scores[n-1];

		score /= (n - 2);

		printf("%d\n",score);

		scanf("%d",&n);

	}

	return 0;

}
