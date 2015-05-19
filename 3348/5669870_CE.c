#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define pi acos(-1.0)
#define SQR(x) ((x)*(x))
#define eps 1e-16
#define MAXN 10002
typedef struct
{
    double x;
    double y;
}pt_t;
pt_t pt[MAXN];
int right[MAXN * 2];
int left[MAXN * 2];
int topl;
int topr;
int cnt;
int n;
int dcmp(double x)
{
    if (x < -eps) return -1;
    else return x > eps;
}
int cmp(const void* p1, const void* p2)
{
    pt_t* a = (pt_t*)p1;
    pt_t* b = (pt_t*)p2;
    int u = dcmp(a->y - b->y);
    if(u == 0) return dcmp(a->x - b->x);
    return u;
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
    qsort((void*)&pt[1], n, sizeof(pt[1]), cmp);
	topr = 2; right[1] = 1; right[2] = 2;
	for(i = 3;i <= n; i++)
	{
		while(topr > 1 && cross(pt[right[topr-1]], pt[right[topr]], pt[i]) < 0) topr--;
		right[++topr] = i;
	}
	topl = 2; left[1] = n; left[2] = n - 1;
	for(i = n - 2;i >= 1; i--)
	{
		while(topl > 1 && cross(pt[left[topl-1]], pt[left[topl]], pt[i]) < 0) topl--;
		left[++topl] = i;
	}
	for(i = 1;i <= topl; i++) right[++topr] = left[i];
}
void init()
{
    int i;
    scanf("%d", &n);
    for (i = 1;i <= n; i++) scanf("%lf %lf", &pt[i].x, &pt[i].y);
}
void solve()
{
	double ans = 0.0;
	int i;
	for(i = 2;i <= topr; i++)
		ans += pt[right[i-1]].x * pt[right[i]].y - pt[right[i]].x * pt[right[i-1]].y;
	ans = fabs(ans / 2 / 50);
	printf("%0.0lf\n", trunc(ans));
}
int main()
{
    init();
    graham_scan();
    solve();
    return 0;
}
