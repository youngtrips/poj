#include <stdio.h>
char board[5][5], map[5][5];
int n;
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
int find(int x, int y)
{
    int cnt, i, j;
    map[x][y] = 'r';
    cnt = 1;
    for(i = 1;i <= n; i++)
    {
        for(j = 1;j <= n; j++)
        {
            if(check(i, j))
            {
                map[i][j] = 'r';
                cnt++;
            }
        }
    }
    return cnt;
}
void search()
{
    int max = 0, res, i, j;
    for(i = 1;i <= n; i++)
    {
        for(j = 1;j <= n; j++)
        {
            if(board[i][j] == '.')
            {
                init_map();
                res = find(i, j);
                if(max < res) max = res;
            }
        }
    }
    printf("%d\n", max);
}
int main()
{
    while(init()) search();
    return 0;
}
