#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define pi acos(-1.0)
#define SQR(x) ((x)*(x))
#define eps 1e-16
#define MAXN 1002
typedef struct
{
    double x;
    double y;
}pt_t;
pt_t p[MAXN];
int ans[MAXN];
int q[MAXN];
int v[MAXN];
int top;
int cnt;
int n, l;
void swap(int i, int j)
{
    double tx, ty;
    tx = p[i].x;
    ty = p[i].y;
    p[i].x = p[j].x;
    p[i].y = p[j].y;
    p[j].x = tx;
    p[j].y = ty;
}
int dcmp(double x)
{
    if (x < -eps) return -1;
    else return x > eps;
}
double cross(pt_t t, pt_t i, pt_t j)
{
    return (i.x - t.x) * (j.y - t.y) - (j.x - t.x) * (i.y - t.y);
}
double dist(pt_t a, pt_t b)
{
    return sqrt(SQR(a.x - b.x) + SQR(a.y - b.y));
}

void graham_scan()
{
    int i;
    memset(v, 0, sizeof(v));
    top = 2;
    q[1] = 1;
    q[2] = 2;
    cnt = 0;
    for (i = 3;i <= n; i++)
    {
        while (top > 1 && cross(p[q[top-1]], p[q[top]], p[i]) <= 0) top--;
        q[++top] = i;
    }
    for (i = 1;i <= top; i++)
    {
        ans[++cnt] = q[i];
        v[q[i]] = 1;
    }
    top = 2;
    q[1] = n;
    q[2] = n - 1;
    for (i = n - 2;i >= 1; i--)
    {
        while (top > 1 && cross(p[q[top-1]], p[q[top]], p[i]) <= 0) top--;
        q[++top] = i;
    }
    for (i = 1;i <= top; i++)
    {
        if (v[q[i]] == 0) ans[++cnt] = q[i];
    }
}
void init()
{
    int i;
    scanf("%d %d", &n, &l);
    for (i = 1;i <= n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
}
void solve()
{
    double len = 2.0 * pi * (double)(l);
    int i, j;
    for (i = 1;i <= cnt; i++)
    {
        j = i % cnt + 1;
        len += dist(p[ans[i]], p[ans[j]]);
    }
    printf("%0.0lf\n", len);
}
int main()
{
    init();
    graham_scan();
    solve();
    return 0;
}
