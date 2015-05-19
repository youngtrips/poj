#include <stdio.h>
#include <string.h>
#define CLS(x) memset(x,'0',sizeof(x))
#define MAX 102
char visited[MAX][MAX];
char map[MAX][MAX];
int q_x[MAX * MAX];
int q_y[MAX * MAX];
int dx[4] = {0, 1, -1,  0};
int dy[4] = {1, 0,  0, -1};
int head, tail, n, m;
void init()
{
    int i, j, k;
    scanf("%d %d %d", &n, &m, &k);
    CLS(visited);
    CLS(map);
    while(k--)
    {
        scanf("%d %d", &i, &j);
        map[i][j] = '1';
    }
}
int check(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m && visited[x][y] == '0' && map[x][y] == '1');
}
int bfs(int stx, int sty)
{
    int cnt, x, y, i;
    q_x[0] = stx;
    q_y[0] = sty;
    head = 0;
    tail = 1;
    visited[stx][sty] = '1';
    cnt = 1;
    while(head < tail)
    {
        x = q_x[head];
        y = q_y[head];
        for(i = 0;i < 4; i++)
        {
            if(check(x + dx[i], y + dy[i]))
            {
                cnt++;
                visited[x + dx[i]][y + dy[i]] = '1';
                q_x[tail] = x + dx[i];
                q_y[tail] = y + dy[i];
                tail++;
            }
        }
        head++;
    }
    return cnt;
}
void search()
{
    int res, max, i, j;
    max = 0;
    for(i = 1;i <= n; i++)
    {
        for(j = 1;j <= m; j++)
        {
            if(map[i][j] == '1' && visited[i][j] == '0')
            {
                res = bfs(i, j);
                if(max < res) max = res;
            }
        }
    }
    printf("%d\n", max);
}
int main()
{
    init();
    search();
    return 0;
}
