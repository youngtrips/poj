#include <stdio.h>
#include <math.h>
int main()
{
	double x1,y1,x2,y2,x3,y3,s,a,b,c,r,c1,c2,x0,y0;
	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3) != EOF)
	{
		s = fabs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
		a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
		c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
		r = a * b * c / (s + s + s + s);
		c1 = (x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2) / 2;
		c2 = (x1 * x1 + y1 * y1 - x3 * x3 - y3 * y3) / 2;
		x0 = (c1 * (y1 - y3) - c2 * (y1 - y2)) / ((x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2));
		y0 = (c1 * (x1 - x3) - c2 * (x1 - x2)) / ((y1 - y2) * (x1 - x3) - (y1 - y3) * (x1 - x2));
		a = -2 * x0;
		b = -2 * y0;
		c = x0 * x0 + y0 * y0 - r * r;
		if(x0 > 0)
		{
			if(y0 > 0)
				printf("(x - %0.3lf)^2 + (y - %0.3lf)^2 = %0.3lf^2\n",x0,y0,r);
			else if(y0 < 0)
				printf("(x - %0.3lf)^2 + (y + %0.3lf)^2 = %0.3lf^2\n",x0,-y0,r);
			else
				printf("(x - %0.3lf)^2 + y^2 = %0.3lf^2\n",x0,r);
		}
		else if(x0 < 0)
		{
			if(y0 > 0)
				printf("(x + %0.3lf)^2 + (y - %0.3lf)^2 = %0.3lf^2\n",-x0,y0,r);
			else if(y0 < 0)
				printf("(x + %0.3lf)^2 + (y + %0.3lf)^2 = %0.3lf^2\n",-x0,-y0,r);
			else
				printf("(x + %0.3lf)^2 + y^2 = %0.3lf^2\n",-x0,r);
		}
		else
		{
			if(y0 > 0)
				printf("x^2 + (y - %0.3lf)^2 = %0.3lf^2\n",y0,r);
			else if(y0 < 0)
				printf("x^2 + (y + %0.3lf)^2 = %0.3lf^2\n",x0,-y0,r);
			else 
				printf("x^2 + y^2 = %0.3lf^2\n",r);
		}
		if(a > 0)
		{
			if(b > 0)
			{
				if(c > 0)
					printf("x^2 + y^2 + %0.3lfx + %0.3lfy + %0.3lf = 0\n",a,b,c);
				else if(c < 0)
					printf("x^2 + y^2 + %0.3lfx + %0.3lfy - %0.3lf = 0\n",a,b,-c);
				else
					printf("x^2 + y^2 + %0.3lfx + %0.3lfy = 0\n",a,b);
			}
			else if(b < 0)
			{
				if(c > 0)
					printf("x^2 + y^2 + %0.3lfx - %0.3lfy + %0.3lf = 0\n",a,-b,c);
				else if(c < 0)
					printf("x^2 + y^2 + %0.3lfx - %0.3lfy - %0.3lf = 0\n",a,-b,-c);
				else
					printf("x^2 + y^2 + %0.3lfx - %0.3lfy = 0\n",a,-b);
			}
			else
			{
				if(c > 0)
					printf("x^2 + y^2 + %0.3lfx + %0.3lf = 0\n",a,c);
				else if(c < 0)
					printf("x^2 + y^2 + %0.3lfx - %0.3lf = 0\n",a,-c);
				else 
					printf("x^2 + y^2 = 0\n");
			}
		}
		else if(a < 0)
		{
			if(b > 0)
			{
				if(c > 0)
					printf("x^2 + y^2 - %0.3lfx + %0.3lfy + %0.3lf = 0\n",-a,b,c);
				else if(c < 0)
					printf("x^2 + y^2 - %0.3lfx + %0.3lfy - %0.3lf = 0\n",-a,b,-c);
				else 
					printf("x^2 + y^2 - %0.3lfx + %0.3lfy = 0\n",-a,b);
			}
			else if(b < 0)
			{
				if(c > 0)
					printf("x^2 + y^2 - %0.3lfx - %0.3lfy + %0.3lf = 0\n",-a,-b,c);
				else if(c < 0)
					printf("x^2 + y^2 - %0.3lfx - %0.3lfy - %0.3lf = 0\n",-a,-b,-c);
				else
					printf("x^2 + y^2 - %0.3lfx - %0.3lfy = 0\n",-a,-b);
			}
			else
			{
				if(c > 0)
					printf("x^2 + y^2 + %0.3lfx + %0.3lf = 0\n",a,c);
				else if(c < 0)
					printf("x^2 + y^2 + %0.3lfx - %0.3lf = 0\n",a,-c);
				else
					printf("x^2 + y^2 + %0.3lfx = 0\n",a);
			}
		}
		else
		{
			if(b > 0)
			{
				if(c > 0)
					printf("x^2 + y^2 + %0.3lfy + %0.3lf = 0\n",b,c);
				else if(c < 0)
					printf("x^2 + y^2 + %0.3lfy - %0.3lf = 0\n",b,-c);
				else
					printf("x^2 + y^2 + %0.3lfy = 0\n",b);
			}
			else if(b < 0)
			{
				if(c > 0)
					printf("x^2 + y^2 - %0.3lfy + %0.3lf = 0\n",-b,c);
				else if(c < 0)
					printf("x^2 + y^2 - %0.3lfy - %0.3lf = 0\n",-b,-c);
				else
					printf("x^2 + y^2 - %0.3lfy = 0\n",-b);
			}
			else
			{
				if(c > 0)
					printf("x^2 + y^2 + %0.3lf = 0\n",c);
				else if(c < 0)
					printf("x^2 + y^2 - %0.3lf = 0\n",-c);
				else
					printf("x^2 + y^2 = 0\n");
			}
		}
		printf("\n");
	}
	return 0;
}
