#include <stdio.h>
#include <math.h>
#include <string.h>
#define SQR(x) ((x)*(x))
#define oo 9999999999.999
#define eps 1e-16
#define MAXE 120002
#define MAXV 102
#define MAXN 18
typedef struct {  int u; int v; double w; int next;}edge_t;
typedef struct { double x; double y;}pt_t;
edge_t e[MAXE];
pt_t door[MAXN * 4 + 1];
pt_t wall[MAXN * 3 + 1][2];
double dis[MAXV];
int first[MAXV];
int que[MAXV * MAXV];
int has[MAXV];
int head, tail;
int ndoor, nwall;
int tot, st, ed, n;
int dcmp(double x)
{
	if(x < -eps) return -1;
	return x > eps;
}
double cross(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}
int segcross(pt_t a, pt_t b, pt_t c, pt_t d)
{
	int u = dcmp(cross(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y) * cross(b.x - a.x, b.y - a.y, d.x - a.x, d.y - a.y));
	int v = dcmp(cross(d.x - c.x, d.y - c.y, a.x - c.x, a.y - c.y) * cross(d.x - c.x, d.y - c.y, b.x - c.x, b.y - c.y));
	return u < 0 && v < 0;
}
void add(int u, int v, double w)
{
	e[++tot].u = u; e[tot].v = v; e[tot].w = w; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].w = w; e[tot].next = first[v]; first[v] = tot;
}
void add_door(double x, double y)
{
	++ndoor;
	door[ndoor].x = x;
	door[ndoor].y = y;
}
void add_wall(double x1, double y1, double x2, double y2)
{
	++nwall;
	wall[nwall][0].x = x1;
	wall[nwall][0].y = y1;
	wall[nwall][1].x = x2;
	wall[nwall][1].y = y2;
}
int init()
{
	double x, y1, y2, y3, y4;
	int i;
	scanf("%d", &n);
	if(n == -1) return 0;
	ndoor = 0; nwall = 0;
	add_door(0.0, 5.0);
	for(i = 1;i <= n; i++)
	{
		scanf("%lf %lf %lf %lf %lf", &x, &y1, &y2, &y3, &y4);
		add_door(x, y1);
		add_door(x, y2);
		add_door(x, y3);
		add_door(x, y4);
		add_wall(x, 0.0, x, y1);
		add_wall(x, y2,  x, y3);
		add_wall(x, y4,  x, 10);
	}
	add_door(10.0, 5.0);
	return 1;
}
double dist(pt_t p1, pt_t p2)
{
	return sqrt(SQR(p1.x - p2.x) + SQR(p1.y - p2.y));
}
int check(pt_t a, pt_t b)
{
	int i;
	for(i = 1;i <= nwall; i++) if(segcross(a, b, wall[i][0], wall[i][1])) return 0;
	return 1;
}
void build()
{
	double len;
	int i, j;
	memset(first, -1, sizeof(first));
	tot = -1;
	for(i = 1;i <= ndoor; i++)
	{
		for(j = i + 1;j <= ndoor; j++)
		{
			if(dcmp(fabs(door[i].x - door[j].x)) == 0) continue;
			if(check(door[i], door[j]) == 0) continue;
			len = dist(door[i], door[j]);
			add(i, j, len);
		}
	}
	st = 1; ed = ndoor;
}
void spfa()
{
	int i, j, t;
	for(i = st;i <= ed; i++) dis[i] = oo;
	memset(has, 0, sizeof(has));
	dis[st] = 0.0; has[st] = 1;
	que[0] = st; head = 0; tail = 1;
	while(head < tail)
	{
		i = que[head]; has[i] = 0;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(dis[i] + e[t].w + eps < dis[j])
			{
				dis[j] = dis[i] + e[t].w;
				if(has[j] == 0)
				{
					que[tail++] = j;
					has[j] = 1;
				}
			}
			t = e[t].next;
		}
		head++;
	}
}
int main()
{
	while(init())
	{
		build();
		spfa();
		printf("%0.2lf\n", dis[ed]);
	}
	return 0;
}
