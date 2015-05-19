#include <stdio.h>
#include <string.h>
#define CLS(x) memset(x,'0',sizeof(x))
#define MAX 102
char visited[MAX][MAX];
char map[MAX][MAX];
int dx[4] = {0, 1, -1,  0};
int dy[4] = {1, 0,  0, -1};
int cnt, n, m;
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
void dfs(int stx, int sty)
{
    int i;
    visited[stx][sty] = '1';
    for(i = 0;i < 4; i++)
        if(check(stx + dx[i], sty + dy[i]))
        {
            cnt++;
            dfs(stx + dx[i], sty + dy[i]);
        }
}
void search()
{
    int max, i, j;
    max = 0;
    for(i = 1;i <= n; i++)
    {
        for(j = 1;j <= m; j++)
        {
            if(map[i][j] == '1' && visited[i][j] == '0')
            {
                cnt = 1;
                dfs(i, j);
                if(max < cnt) max = cnt;
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
