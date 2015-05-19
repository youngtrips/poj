#include <stdio.h>
#include <string.h>
#define MAX 202
#define MAX_HASH 2002
int x[MAX], y[MAX], n;
int has1[MAX_HASH][MAX_HASH];
int has2[MAX_HASH][MAX_HASH];
int has3[MAX_HASH][MAX_HASH];
int has4[MAX_HASH][MAX_HASH];
int set_hash(int x, int y)
{
    int res = 0;
    if(x >= 0 && y >= 0)
    {
        if(has1[x][y] == 0)
        {
            has1[x][y] = 1;
            res = 1;
        }
    }
    else if(x <= 0 && y >= 0)
    {
         if(has2[-x][y] == 0)
         {
             has2[-x][y] == 1;
             res = 1;
         }
    }
    else if(x <= 0 && y <= 0)
    {
         if(has3[-x][-y] == 0)
         {
             has2[-x][-y] = 1;
             res = 1;
         }
    }
    else if(x >= 0 && y <= 0)
    {
        if(has4[x][-y] == 0)
        {
            has4[x][-y] = 1;
            res = 1;
        }
    }
    return res;
}
int my_abs(int x)
{
    if(x > 0) return x;
    return -x;
}
int gcd(int m, int n)
{
    int r = m % n;
    while(r != 0)
    {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}
int main()
{
    int cnt, vx, vy, i, j, d;
    memset(has1, 0, sizeof(has1));
    memset(has2, 0, sizeof(has1));
    memset(has3, 0, sizeof(has1));
    memset(has4, 0, sizeof(has1));
    cnt = 0;
    scanf("%d", &n);
    for(i = 0;i < n; i++) scanf("%d %d", &x[i], &y[i]);
    for(i = 0;i < n; i++)
    {
        for(j = i + 1;j < n; j++)
        {
            vx = x[i] - x[j];
            vy = y[i] - y[j];
            if(vx == 0 && vy != 0) vy = 1;
            if(vy == 0 && vx != 0) vx = 1;
            if(vx != 0 && vy != 0)
            {
                d = gcd(my_abs(vx), my_abs(vy));
                vx /= d;
                vy /= d;
                if(vx < 0)
                {
                    vx = -vx;
                    vy = -vy;
                }
            }
            if(set_hash(vx, vy) == 1) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
