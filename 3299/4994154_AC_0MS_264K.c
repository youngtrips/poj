#include <stdio.h>

#include <math.h>

int main()

{

	double x,y;

	double e;

	double t,d,h;

	char mark[2];

	while(1)

	{

		scanf("%c", &mark[0]);
		if(mark[0] == 'E') break;
		scanf("%lf %c %lf", &x, &mark[1], &y);
		getchar();

		if(mark[0] == 'T' && mark[1] == 'D')

		{

			t = x;

			d = y;

			e = 6.11*exp(5417.7530*((1.0/273.16) - (1.0/(d+273.16))));

			h = (0.5555)*(e - 10.0);

			h = t + h;

		}

		else if(mark[0] == 'T' && mark[1] == 'H')

		{

			t = x;

			h = y;

			h = h - t;

			e = h / 0.5555 + 10.0;

			d = 1.0 / (1.0/273.16 - log(e / 6.11) / 5417.7530)-273.16;

			h = y;

		}

		else if(mark[0] == 'D' && mark[1] == 'T')

		{

			t = y;

			d = x;

			e = 6.11*exp(5417.7530*((1.0/273.16) - (1.0/(d+273.16))));

			h = (0.5555)*(e - 10.0);

			h = t + h;

		}

		else if(mark[0] == 'D' && mark[1] == 'H')

		{

			d = x;

			e = 6.11*exp(5417.7530*((1.0/273.16) - (1.0/(d+273.16))));

			h = (0.5555)*(e - 10.0);

			t = y - h;

			h = y;

		}

		else if(mark[0] == 'H' && mark[1] == 'T')

		{

			h = x;

			t = y;

			h = h - t;

			e = h / 0.5555 + 10.0;

			d = 1.0 / (1.0/273.16 - log(e / 6.11) / 5417.7530)-273.16;

			h = x;

		}

		else if(mark[0] == 'H' && mark[1] == 'D')

		{

			d = y;

			e = 6.11*exp(5417.7530*((1.0/273.16) - (1.0/(d+273.16))));

			h = (0.5555)*(e - 10.0);

			t = y - h;

			h = x;

		}

		printf("T %0.1lf D %0.1lf H %0.1lf\n",t,d,h);

	}

	return 0;

}
