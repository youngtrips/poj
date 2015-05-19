#include <stdio.h>
int mv[16][2] = { {1, 1}, {1, 2}, {1, 3}, {1, 4},
                  {2, 1}, {2, 2}, {2, 3}, {2, 4},
                  {3, 1}, {3, 2}, {3, 3}, {3, 4},
                  {4, 1}, {4, 2}, {4, 3}, {4, 4}};
char board[5][5], map[5][5];
int cnt, n;
int init()
{
    int i, j;
    scanf("%d", &n); if(n == 0) return 0;
    getchar();
    for(i = 1;i <= n; i++)
    {
        for(j = 1;j <= n; j++) board[i][j] = getchar();
        getchar();
    }
}
void init_map()
{
    int i, j;
    for(i = 1;i <= n; i++)
        for(j = 1;j <= n; j++) map[i][j] = board[i][j];
}
int check(int x, int y)
{
    int i;
    if(map[x][y] != '.') return 0;
    for(i = x + 1;i <= n && map[i][y] != 'X'; i++) if(map[i][y] == 'r') return 0;
    for(i = x - 1;i >= 1 && map[i][y] != 'X'; i--) if(map[i][y] == 'r') return 0;
    for(i = y + 1;i <= n && map[x][i] != 'X'; i++) if(map[x][i] == 'r') return 0;
    for(i = y - 1;i >= 1 && map[x][i] != 'X'; i--) if(map[x][i] == 'r') return 0;
    return 1;
}
void dfs(int p)
{
    int x;
    int y;
    if(p >= n * n) return;
    x = mv[p][0];
    y = mv[p][1];
    if(check(x, y))
    {
        map[x][y] = 'r';
        cnt++;
    }
    dfs(p + 1);
}
int search()
{
    int max = 0, i;
    for(i = 0;i < n * n; i++)
    {
        init_map();
        cnt = 0;
        dfs(i);
        if(max < cnt) max = cnt;
    }
    return max;
}
int main()
{
    while(init()) printf("%d\n", search());
    return 0;
}
