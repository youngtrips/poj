#include <stdio.h>
#include <string.h>

#define EVENT 1
#define OLD 0
#define MAXN 16
char board[MAXN][MAXN];
int cnt[4];

int n;
int m;
int pos[2][MAXN * MAXN];
int tot;

int init()
{
    char ch;
    int i;
    int j;

    scanf("%d %d", &n, &m);
    if(n == 0 && m == 0) 
        return 0;

    memset(cnt, 0x0, sizeof(cnt));
    getchar();
    tot = 0;
    for(i = 1;i <= n; i++)
    {
        for(j = 1;j <= m; j++)
        {
            ch = getchar();
            board[i][j] = ch;
            if(ch >= 'A' && ch <= 'D')
            {
                cnt[ch - 'A']++;
                pos[0][++tot] = i;
                pos[1][tot] = j;
            }
        }
        getchar();
    }
    for(i = 0;i <= n + 1; i++)
    {
        board[i][0] = '*';
        board[i][m + 1] = '*';
    }
    for(j = 0;j <= m + 1; j++)
    {
        board[0][j] = '*';
        board[n + 1][j] = '*';
    }
    return 1;
}

int check_old_even()
{
    int i;
    for(i = 0;i < 4; i++)
        if(cnt[i] & 1)
            return OLD;
    return EVENT;
}

int sucess;
int tmp;

int check()
{
    int i;
    int j;
    for(i = 1;i < n; i++)
    {
        for(j = 1;j < m; j++)
        {
            if(board[i][j] == board[i+1][j+1] && 
               board[i+1][j] == board[i][j+1] &&
               cnt[board[i][j] - 'A'] == 2 &&
               cnt[board[i+1][j] - 'A'] == 2)
                return 0;
        }
    }
    return 1;
}
void bfs(int, int);
void dfs()
{
    int curx;
    int cury;
    int i;
    if(sucess == 1)
        return;
    if(check() == 0)
        return;
    if(tot == 0)
    {
        sucess = 1;
        return;
    }
    for(i = 1;i <= tmp; i++)
    {
        curx = pos[0][i];
        cury = pos[1][i];
        if(board[curx][cury] != '*')
        {
            bfs(curx, cury);
        }
    }
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int stx, int sty)
{
    char flag[MAXN][MAXN];
    char ch;
    int q[4][MAXN * MAXN];
    int head;
    int tail;
    int curx;
    int cury;
    int curt;
    int curd;
    int tmpx;
    int tmpy;
    int i;
    int t;


    ch = board[stx][sty];
    memset(flag, 0x0, sizeof(flag));
    head = 0;
    tail = 0;

    flag[stx][sty] = 1;
    q[0][tail] = stx;
    q[1][tail] = sty;
    q[2][tail] = 0;
    q[3][tail] = -1;
    tail++;

    while(head < tail)
    {
        curx = q[0][head];
        cury = q[1][head];
        curt = q[2][head];
        curd = q[3][head];
        for(i = 0;i < 4; i++)
        {
            tmpx = curx + dx[i];
            tmpy = cury + dy[i];
            
            if(tmpx < 0 || tmpx > n + 1 || tmpy < 0 || tmpy > m + 1)
                continue;
            if(flag[tmpx][tmpy] == 1)
                continue;
            if(board[tmpx][tmpy] != '*' && board[tmpx][tmpy] != ch)
                continue;
         
            if(curd == -1)
                t = 0;
            else if(curd == i)
                t = curt;
            else
                t = curt + 1;
            if(t > 2)
                continue;
            
            if(board[tmpx][tmpy] == ch)
            {
                board[tmpx][tmpy] = '*';
                board[stx][sty] = '*';
                tot -= 2;
                cnt[ch - 'A'] -= 2;
                dfs();
                tot += 2;
                cnt[ch - 'A'] += 2;
                board[tmpx][tmpy] = ch;
                board[stx][sty] = ch;
            }
            
            flag[tmpx][tmpy] = 1;
            q[0][tail] = tmpx;
            q[1][tail] = tmpy;
            q[2][tail] = t;
            q[3][tail] = i;
            tail++;
        }
        head++;
    }
}

void solve()
{
    tmp = tot;
    sucess = 0;
    dfs();
    printf("%s\n", sucess ? "yes" : "no");
}

int main()
{
    while(init())
    {
        if(check_old_even() == OLD)
            printf("no\n");
        else
            solve();
    }
    return 0;
}
