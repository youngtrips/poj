#include <stdio.h>
#include <string.h>

#define oo 0x7fffffff
#define MAXN 22
#define MAXN_STATE 1024

int step[MAXN][MAXN][MAXN_STATE];
char map[MAXN][MAXN];
int n, m;
int tot;
int q[3][MAXN * MAXN * MAXN_STATE];
int head;
int tail;
int stx;
int sty;
int end;

int init()
{
    char ch;
    int i;
    int j;
    scanf("%d %d", &m, &n);
    if(n == 0 && m == 0)
        return 0;
    getchar();
    tot = 0;
    for(i = 0;i < n; i++)
    {
        for(j = 0;j < m; j++)
        {
            ch = getchar();
            if(ch == '.')
                map[i][j] = 0;
            else if(ch == 'x')
                map[i][j] = -1;
            else if(ch =='*')
                map[i][j] = ++tot;
            else
            {
                stx = i;
                sty = j;
                map[i][j] = 0;
            }
        }
        getchar();
    }

    end = (1 << tot) - 1;
    return 1;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs()
{
    int curx;
    int cury;
    int curs;
    int tmpx;
    int tmpy;
    int tmps;
    int cur_step;
    int i;
    int ans;

    head = 0;
    tail = 0;
    ans = oo;
    memset(step, -1, sizeof(step));
    step[stx][sty][0] = 0;
    q[0][tail] = stx;
    q[1][tail] = sty;
    q[2][tail] = 0;
    tail++;
    while(head < tail)
    {
        curx = q[0][head];
        cury = q[1][head];
        curs = q[2][head];
        cur_step = step[curx][cury][curs];
        for(i = 0;i < 4; i++)
        {
            tmpx = curx + dx[i];
            tmpy = cury + dy[i];
            if(tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m)
                continue;
            if(map[tmpx][tmpy] == -1)
                continue;
            tmps = curs;
            if(map[tmpx][tmpy] > 0)
                tmps |= (1 << (map[tmpx][tmpy] - 1));
            if(step[tmpx][tmpy][tmps] < 0)
            {
                step[tmpx][tmpy][tmps] = cur_step + 1;
                if(tmps == end)
                {
                    if(ans > cur_step + 1)
                        ans = cur_step + 1;
                }
                q[0][tail] = tmpx;
                q[1][tail] = tmpy;
                q[2][tail] = tmps;
                tail++;
            }
        }
        head++;
    }
    return ans;
}

int main()
{
    int res;
    while(init())
    {
        res = bfs();
        printf("%d\n", res == oo ? -1 : res);
    }
    return 0;
}
