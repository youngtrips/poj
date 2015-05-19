#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SQR(x) ((x)*(x))
#define PI acos(-1.0)
#define eps 1e-16
#define MAXN 1002
typedef struct
{
	double x;
	double y;
}pt_t;
pt_t pt[MAXN];
pt_t bp;
int stack[MAXN * 2];
int top;
int n, l;
double dist(pt_t p1, pt_t p2)
{
	return sqrt(SQR(p1.x - p2.x) + SQR(p1.y - p2.y));
}
int dcmp(double x)
{
	if(x < -eps) return -1;
	else return x > eps;
}
double cross(pt_t p0, pt_t p1, pt_t p2)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
int cmp(const void* a, const void* b)
{
	pt_t p1 = *(pt_t*)a;
	pt_t p2 = *(pt_t*)b;
	int u = dcmp(cross(bp, p1, p2));
	if(u > 0 || (u == 0 && dcmp(dist(bp, p1) - dist(bp, p2)) < 0)) return -1;
	return 1;
}
void init()
{
	int i;
	scanf("%d %d", &n, &l);
	for(i = 1;i <= n; i++) scanf("%lf %lf", &pt[i].x, &pt[i].y);
}
void graham_scan()
{
	double tx, ty;
	int i, j;
	for(i = 1, j = 2;j <= n; j++)
		if(pt[i].y > pt[j].y || (pt[i].y == pt[j].y && pt[i].x > pt[j].x)) i = j;
	bp.x = pt[i].x;