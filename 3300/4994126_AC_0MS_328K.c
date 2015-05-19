#include <stdio.h>

void sort(float value[],int count)

{

    int k, i, j;

    float temp;

    for(i = 0;i < count-1; i++)

    {

        k = i;

        for(j = i + 1;j < count; j++)

            if(value[j] - value[k] < 0.000001) k = j; 

        if(k != i)

        {

                temp = value[i];

                value[i] = value[k];

                value[k] = temp;

        }

    }

}

int fss[10];

int rss[10];

float radio[100];

float max;

int main()

{

    int f,r,i,j,p;

    while(1)

    {

            scanf("%d",&f);

            if(f == 0) break;

	    scanf("%d",&r);

            for(i = 0;i < f; i++) scanf("%d",&fss[i]);

            for(i = 0;i < r; i++) scanf("%d",&rss[i]);

            p = 0;

            for(i = 0;i < f; i++)

            {

                  for(j = 0;j < r; j++)

                  {

                        radio[p] = (rss[j] * 1.0) / fss[i];

                        p++;

                  }

            }

            sort(radio,p);

            max = radio[1] / radio[0];
	    for(i = 2;i < p; i++)

	    {

                  if(max - radio[i] / radio[i-1] < 1e-15) max = radio[i] / radio[i-1];

            }

	    printf("%0.2f\n",max);

    }

    return 0;

}
