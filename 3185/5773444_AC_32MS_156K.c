#include <stdio.h>
#define MASK (0xFFFFF << 1)
int count (int bowl, int n, int nflips)
{
    if ((bowl & MASK) == 0) return nflips;
    if (n == 1) return 99999;
    if (bowl & (1 << n))   /* then flip and recursively count */
        return count (bowl ^ (7 << (n-2)), n-1, nflips+1);
    return count (bowl, n-1, nflips);
}
int main() 
{
    int i, bit, bowl = 0, a, b;
    for (i = 0; i < 20; i++) 
	{
        scanf ("%d", &bit);
        bowl = (bowl << 1) | bit;
    }
    bowl = bowl << 1;
    a = count (bowl ^ (3<<19), 20, 1);
    b = count (bowl          , 20, 0);
    printf ("%d\n", a < b ? a : b);
	return 0;
}
