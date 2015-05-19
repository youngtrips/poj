#include <stdio.h>
typedef struct
{
	int x;
	int y;
}pt_t;
int cross(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - x2 * y1;
}
int online(pt_t a, pt_t b, pt_t c, pt_t d)
{
	int u = cross(c.x - a.x, c.y - a.y, d.x - c.x, d.y - c.y);
	int v = cross(d.x - b.x, d.y - b.y, c.x - d.x, c.y - d.y);
	return u == 0 && v == 0;
}
int onpara(pt_t a, pt_t b, pt_t c, pt_t d)
{
	int u = cross(b.x - a.x, b.y - a.y, d.x - c.x, d.y - c.y);
	return u == 0;
}
void intersec(pt_t a, pt_t b, pt_t c, pt_t d, double* x, double* y)
{
	int u = cross(d.x - a.x, d.y - a.y, b.x - a.x, b.y - a.y);
	int v = cross(c.x - a.x, c.y - a.y, b.x - a.x, b.y - a.y);
	int w = u - v;
	*x = (u * 1.0 * c.x - v * 1.0 * d.x) / (w * 1.0);
	*y = (u * 1.0 * c.y - v * 1.0 * d.y) / (w * 1.0);
}
int main()
{
	pt_t a, b, c, d;
	double x, y;
	int n;
	scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--)
	{
		scanf("%d %d %d %d %d %d %d %d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
		if(online(a, b, c, d)) printf("LINE\n");
		else if(onpara(a, b, c, d)) printf("NONE\n");
		else
		{
			intersec(a, b, c, d, &x, &y);
			printf("POINT %0.2lf %0.2lf\n", x, y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
