#include <stdio.h>
int main()
{
	int t,i,n,s;
    double r,p;
    scanf("%d",&t);
    while(t--)
	{
		scanf("%d",&n);
        r = 0;
        for(i = 0;i < 32; i++)
		{
            s = 1<<i;
            p=((n / s >>1) * s + (((n&s)==0) ? n%s:s)) / (double)n;
            r += 2 * p * (1-p) * s;
        }
        printf("%.2lf\n",r);
    }
    return 1;
}
