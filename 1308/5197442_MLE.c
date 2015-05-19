#include <stdio.h>
#define N 1000005
long has[N];
long rank[N];
long parent[N];
void make_set()
{
    int i;
    for(i = 1;i < N; i++)
    {
        has[i] = 0;
        rank[i] = 0;
        parent[i] = i;
    }
}
int find_set(int x)
{
    if(x != parent[x]) parent[x] = find_set(parent[x]);
    return parent[x];
}
int union_set(int r1, int r2)
{
    int x = find_set(r1);
    int y = find_set(r2);
    if(x == y) return 0;
    if(rank[x] > rank[y]) parent[y] = x;
    else
    {
        parent[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
    }
    return 1;
}
int main()
{
    long min, max, i, j;
    int flag, c;
    c = 1;
    while(1)
    {
        scanf("%ld %ld", &i, &j);
        if(i < 0 || j < 0) break;
        if(i == 0 && j == 0)
        {
            printf("Case %d is a tree.\n", c++);
            continue;
        }
        make_set();
        flag = union_set(i, j);
        min = i < j ? i : j;
        max = i > j ? i : j;
        has[i] = 1;
        has[j] = 1;
        while(1)
        {
            scanf("%ld %ld", &i, &j);
            if(i == 0 && j == 0) break;
            if(max < i) max = i;
            if(max < j) max = j;
            if(min > i) min = i;
            if(min > j) min = j;
            has[i] = 1;
            has[j] = 1;
            flag &= union_set(i, j);
        }
        if(flag == 0) printf("Case %d is not a tree.\n", c);
        else
        {
            j = 0;
            for(i = min; i <= max; i++) if(parent[i] == i && has[i] == 1) j++;
            if(j == 1) printf("Case %d is a tree.\n", c);
            else printf("Case %d is not a tree.\n", c);
        }
        c++;
    }
    return 0;
}
