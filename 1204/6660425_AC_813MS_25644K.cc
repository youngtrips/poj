#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define sz 197260

int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
int rx[1011], ry[1011], rd[1011], len[1011];
char text[1001][1010];
bool vsd[1011];
int afcg[1011];
int next[sz][26], pos;
int fa[sz], fp[sz], isword[sz], val[sz], id[sz];
int r, c, zf, rm;

inline bool valid(const int &x, const int &y)
{
    return (x >= 0 && x < r && y >= 0 && y < c);
}

inline void build(const int &cur, char *st, const int &k)
{
    int op = *st - 'A';
    int ps;
    if (!next[cur][op])
    {
        ps = pos;
        next[cur][op] = pos ++;
        val[ps] = op;
        fa[ps] = cur;
    }
    else
        ps = next[cur][op];
    if (*(st + zf) == '\0')
    {
        if (isword[ps])
        {
            if (zf > 0) afcg[k] = -id[ps];
        }
        else
        {
            isword[ps] = 1;
            id[ps] = k * zf;
        }
    }
    else
        build(ps, st + zf, k);
}

inline void bfs()
{
    int i, j, op, now, nxt, root = 0;
    fp[root] = -1;
    queue <int> qq;
    while (!qq.empty()) qq.pop();
    for (i = 0; i < 26; i++)
    {
        if (next[root][i])
            qq.push(next[root][i]);
    }

    while (!qq.empty())
    {
        now = qq.front(), qq.pop();
        nxt = fa[now];
        op = val[now];
        do
        {
            nxt = fp[nxt];
        }
        while (nxt != -1 && !next[nxt][op]);
        if (nxt == -1)
            fp[now] = root;
        else
            fp[now] = next[nxt][op];
        for (i = 0; i < 26; i++)
        {
            if (next[now][i])
                qq.push(next[now][i]);
        }
    }
}

inline void search(const int &x, const int &y, const int &k)
{
    int tx = x, ty = y;
    int op, tmp, dd, cur = 0;
    while (valid(tx, ty))
    {
        op = text[tx][ty] - 'A';
        while (cur != -1 && next[cur][op] == 0)
        {
            cur = fp[cur];
        }
        if (cur == -1) cur = 0;
        else
        {
            cur = next[cur][op];
            tmp = cur;
            while (tmp != -1)
            {
                if (isword[tmp])
                {
                    dd = abs(id[tmp]);
                    if (vsd[dd]) break;
                    if (id[tmp] < 0)
                    {
                        rx[dd] = tx;
                        ry[dd] = ty;
                        rd[dd] = (k + 4) & 7;
                    }
                    else
                    {
                        rx[dd] = tx - dir[k][0] * (len[dd] - 1);
                        ry[dd] = ty - dir[k][1] * (len[dd] - 1);
                        rd[dd] = k;
                    }
                    vsd[dd] = 1;
                    rm --;
                }
                tmp = fp[tmp];
            }
        }
        tx += dir[k][0];
        ty += dir[k][1];
    }
}

inline void init(const int &cur)
{
    for (int i = 0; i < 26; i++)
    {
        if (next[cur][i])
        {
            init(next[cur][i]);
            next[cur][i] = 0;
        }
    }
    isword[cur] = 0;
}

int main()
{


    char ln[1500];
    int n, root = 0;
    int i, j;
    while (scanf("%d %d %d", &r, &c, &n) != EOF)
    {
        getchar();
        for (i = 0; i < r; i++)
        {
            gets(text[i]);
        }
        init(root);
        pos = 1;
        for (i = 1; i <= n; i++)
        {
            gets(ln + 1);
            afcg[i] = i;
            ln[0] = '\0';
            len[i] = strlen(ln + 1);
            zf = 1;
            build(root, ln + 1, i);
            zf = -1;
            build(root, ln + len[i], i);
        }
        rm = n;
        bfs();

        memset(vsd, 0, sizeof(vsd));
        int tr = r - 1, tc = c - 1;
        for (i = 1; i < 5; i++)
        {
            switch (i)
            {
            case 1:
                for (j = 0; j < c; j++)
                {
                    search(tr, j, i);
                }
            case 2:
                for (j = 0; j < r; j++)
                {
                    search(j, root, i);
                }
                break;
            case 3:
                for (j = 0;  j < r; j++)
                {
                    search(j, root, i);
                }
            case 4:
                for (j = 0; j < c; j++)
                {
                    search(root, j, i);
                }
                break;
            }
        }
        for (i = 1; i <= n; i++)
        {
            if (afcg[i] != i)
            {
                j = afcg[i];
                rd[i] = (rd[j] + 4) % 8;
                rx[i] = rx[j] + (len[j] - 1) * dir[rd[j]][0];
                ry[i] = ry[j] + (len[j] - 1) * dir[rd[j]][1];
            }
            printf("%d %d %c\n", rx[i], ry[i], rd[i] + 'A');
        }
    }
    return 0;
}

