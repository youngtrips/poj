#include <stdio.h>
int main()
{
     long long ans, i, a, b, c;
	 ans = 9999999999999999ll;
	 scanf("%lld", &a);
     for(i = a + 1;i <= 2 * a + 2; i++)
     {
          b = i;
          if((a * b + 1) % (b - a) == 0)
          {
               c = (a * b + 1) / (b - a) + b;
			   if(c < ans) ans = c;
          }
     }
     printf("%lld\n", ans);
     return 0;
}
