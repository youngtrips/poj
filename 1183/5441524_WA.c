#include <stdio.h>
int main()
{
     long long a, b, c;
     long long i;
	 scanf("%lld", &a);
     for(i = a + 1;i <= 2 * a + 2; i++)
     {
          b = i;
          if((a * b + 1) % (b - a) == 0)
          {
               c = (a * b + 1) / (b - a);
               break;
          }
     }
     b += c;
     printf("%lld\n", b);
     return 0;
}
