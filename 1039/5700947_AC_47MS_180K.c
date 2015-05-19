#include <stdio.h>
#include <math.h>
#define eps 1e-12
#define MAXN 22
typedef struct
{
	double x;
	double y;
}pt_t;
pt_t upper[MAXN];
pt_t botto[MAXN];
pt_t p1, p2;
int n;
int dcmp(double x)
{
	if(x < -eps) return -1;
	return x > eps;
}
int init()
{
	int i;
	scanf("%d", &n);
	if(n == 0) return 0;
	for(i = 1;i <= n; i++)
	{
		scanf("%lf %lf", &upper[i].x, &upper[i].y);
		botto[i].x = upper[i].x;
		botto[i].y = upper[i].y - 1.0;
	}
	p1.x = upper[1].x; p1.y = upper[1].y;
	p2.x = botto[1].x; p2.y = botto[1].y;
	return 1;
}
double cross(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}
int online(pt_t a, pt_t b, pt_t c, pt_t d)
{
	double u = cross(c.x - a.x, c.y - a.y, d.x - c.x, d.y - c.y);
	double v = cross(d.x - b.x, d.y - b.y, c.x - d.x, c.y - d.y);
	return dcmp(u) == 0 && dcmp(v) == 0;
}
int onpara(pt_t a, pt_t b, pt_t c, pt_t d)
{
	double u = cross(b.x - a.x, b.y - a.y, d.x - c.x, d.y - c.y);
	return dcmp(u) == 0;
}
void intersec(pt_t a, pt_t b, pt_t c, pt_t d, double* x, double* y)
{
	double u = cross(d.x - a.x, d.y - a.y, b.x - a.x, b.y - a.y);
	double v = cross(c.x - a.x, c.y - a.y, b.x - a.x, b.y - a.y);
	double w = u - v;
	*x = (u * 1.0 * c.x - v * 1.0 * d.x) / (w * 1.0);
	*y = (u * 1.0 * c.y - v * 1.0 * d.y) / (w * 1.0);
}
int check(pt_t a, pt_t b, pt_t c, pt_t d)
{
	double tx, ty;
	intersec(a, b, c, d, &tx, &ty);
	if(dcmp(ty - d.y) >= 0 && dcmp(c.y - ty) >= 0) return 1;
	return 0;
}
void solve()
{
	double maxx, tx, ty;
	int flag, i, j, k;
	pt_t a, b;
	maxx = upper[1].x;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++)
		{
			flag = 0;
			if(i == j) continue;
			a.x = upper[i].x; a.y = upper[i].y;
			b.x = botto[j].x; b.y = botto[j].y;
			for(k = (i > j ? i : j);k >= 1; k--)
			{
				if(check(a, b, upper[k], botto[k]) == 0) break;
			}
			if(k >= 1) continue;
			for(k = 1;k <= n; k++)
			{
				if(check(a, b, upper[k], botto[k]) == 0) break;
			}
			if(k > n) { flag = 1; break;}
			intersec(a, b, upper[k-1], upper[k], &tx, &ty);
			if(dcmp(tx - upper[k-1].x) >= 0 && dcmp(upper[k].x - tx) >= 0)
			{
				if(maxx + eps < tx) maxx = tx;
			}
			intersec(a, b, botto[k-1], botto[k], &tx, &ty);
			if(dcmp(tx - botto[k-1].x) >= 0 && dcmp(botto[k].x - tx) >= 0)
			{
				if(maxx + eps < tx) maxx = tx;
			}
		}
		if(flag) break;
	}
	if(flag) printf("Through all the pipe.\n");
	else printf("%0.2lf\n", maxx);
}
int main()
{
	while(init()) solve();
	return 0;
}
