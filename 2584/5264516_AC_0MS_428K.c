#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 32
int adj[MAX][MAX], num, n;
int q[MAX], visited[MAX], pre[MAX], head, tail;
int size_to_i(char ch)
{
    switch(ch)
    {
        case 'S': return 1;
        case 'M': return 2;
        case 'L': return 3;
        case 'X': return 4;
        case 'T': return 5;
    }
}
int init()
{
    char tmp[20];
    int st, ed, i, j, k;
    memset(adj, 0, sizeof(adj));
    scanf("%s", tmp);
    if(!strcmp(tmp, "ENDOFINPUT")) return 0;
    scanf("%d", &n);
    num = n;
    for(i = 0;i < n; i++)
    {
        scanf("%s", tmp);
        st = size_to_i(tmp[0]);
        ed = size_to_i(tmp[1]);
        for(j = st;j <= ed; j++) adj[j][i + 6] = 1;
        adj[i+6][n + 6] = 1;
    }
    for(i = 1;i <= 5; i++)
    {
        scanf("%d", &k);
        adj[0][i] = k;
    }
    n += 6;
    scanf("%s", tmp);
    return 1;
}
int bfs()
{
    int i, j, k;
    memset(visited, 0, sizeof(visited));
    memset(pre, -1, sizeof(pre));
    q[0] = 0;
    visited[0] = 1;
    head = 0;
    tail = 1;
    pre[0] = -1;
    while(head < tail)
    {
        k = q[head];
        for(i = 0;i <= n; i++)
        {
            if(adj[k][i] > 0 && visited[i] == 0)
            {
                pre[i] = k;
                if(i == n) return 1;
                visited[i] = 1;
                q[tail++] = i;
            }
        }
        head++;
    }
    return 0;
}
int ford()
{
    int max, i;
    max = 0;
    while(bfs() == 1)
    {
        i = n;
        while(pre[i] != -1)
        {
            adj[pre[i]][i]--;
            adj[i][pre[i]]++;
            i = pre[i];
        }
        max++;
    }
    return max;
}
int main()
{
    while(init())
    {
        if(num == ford()) printf("T-shirts rock!\n");
        else printf("I'd rather not wear a shirt anyway...\n");
    }
    return 0;
}
