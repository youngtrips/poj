#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1002
typedef struct
{
	long long x;
	long long y;
}pt_t;
typedef struct
{
	pt_t u;
	pt_t l;
}line_t;
line_t line[MAXN];
pt_t quar[MAXN+10][4];
int cnt[MAXN + 10];
int ans[MAXN];
int tot;
int x1, y1, x2, y2, n, m;
int cmp(const void* p1, const void* p2)
{
	line_t* a = (line_t*)p1;
	line_t* b = (line_t*)p2;
	return a->l.x - b->l.x;
}
void add(pt_t a, pt_t b, pt_t c, pt_t d)
{
	++tot;
	quar[tot][0].x = a.x; quar[tot][0].y = a.y;
	quar[tot][1].x = b.x; quar[tot][1].y = b.y;
	quar[tot][2].x = c.x; quar[tot][2].y = c.y;
	quar[tot][3].x = d.x; quar[tot][3].y = d.y;
}
long long cross(long long x1, long long y1, long long x2, long long y2)
{
	return x1 * y2 - x2 * y1;
}
long long dot(long long x1, long long y1, long long x2, long long y2)
{
	return x1 * x2 + y1 * y2;
}
long long in_quar(pt_t a, pt_t b, pt_t c, pt_t d, pt_t p)
{
	long long u = cross(p.x - a.x, p.y - a.y, b.x - p.x, b.y - p.y);
	long long v = cross(p.x - b.x, p.y - b.y, c.x - p.x, c.y - p.y);
	long long w = cross(p.x - c.x, p.y - c.y, d.x - p.x, d.y - p.y);
	long long x = cross(p.x - d.x, p.y - d.y, a.x - p.x, a.y - p.y);
	if(v == 0 && dot(b.x - p.x, b.y - p.y, c.x - p.x, c.y - p.y) < 0) return 1;
	if(x == 0 && dot(a.x - p.x, a.y - p.y, d.x - p.x, d.y - p.y) < 0) return 1;
	if(u * v < 0) return 0;
	if(u * w < 0) return 0;
	if(u * x < 0) return 0;
	return 1;
}
long long init()
{
	pt_t a, b, c, d;
	int ui, li, i;
	scanf("%d", &n);
	if(n == 0) return 0;
	scanf("%d %d %d %d %d", &m, &x1, &y1, &x2, &y2);
	tot = 0;
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d", &ui, &li);
		line[i].u.x = ui; line[i].u.y = y1;
		line[i].l.x = li; line[i].l.y = y2;
	}
	qsort((void*)&line[1], n, sizeof(line[1]), cmp);
	for(i = 1;i <= n; i++)
	{
		if(i == 1)
		{
			a.x = x1; a.y = y1;
			b.x = x1; b.y = y2;
			c.x = line[i].l.x; c.y = line[i].l.y;
			d.x = line[i].u.x; d.y = line[i].u.y;
		}
		else
		{
			a.x = line[i-1].u.x; a.y = line[i-1].u.y;
			b.x = line[i-1].l.x; b.y = line[i-1].l.y;
			c.x = line[i].l.x; c.y = line[i].l.y;
			d.x = line[i].u.x; d.y = line[i].u.y;
		}
		add(a, b, c, d);
	}
	a.x = line[n].u.x; a.y = line[n].u.y;
	b.x = line[n].l.x; b.y = line[n].l.y;
	c.x = x2; c.y = y2;
	d.x = x2; d.y = y1;
	add(a, b, c, d);
	return 1;
}
int find(pt_t p)
{
	int high = tot; 
	int low = 1;
	int mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(p.x < quar[mid][1].x) high = mid - 1;
		else if(p.x > quar[mid][2].x) low = mid + 1;
		else
		{
			if(in_quar(quar[mid][0], quar[mid][1], quar[mid][2], quar[mid][3], p)) return mid;
			else if(mid > 1 && in_quar(quar[mid-1][0], quar[mid-1][1], quar[mid-1][2], quar[mid-1][3], p)) return mid - 1;
			else if(mid + 1 <= tot && in_quar(quar[mid+1][0], quar[mid+1][1], quar[mid+1][2], quar[mid+1][3], p))
				return mid+1;
		}
	}
	return -1;
}
void solve()
{
	pt_t p;
	int res, max, i;
	memset(cnt, 0, sizeof(cnt));
	memset(ans, 0, sizeof(ans));
	while(m--)
	{
		scanf("%lld %lld", &p.x, &p.y);
		/*
		for(i = 1;i <= tot; i++) if(in_quar(quar[i][0], quar[i][1], quar[i][2], quar[i][3], p)) break;
		*/
		i = find(p);
		if(i != -1) cnt[i]++;
		/*
		if(i >= 1 && i <= tot) cnt[i]++;
		*/
	}
	max = 0;
	for(i = 1;i <= tot; i++)
	{
		ans[cnt[i]]++;
		if(max < cnt[i]) max = cnt[i];
	}
	printf("Box\n");
	for(i = 1;i <= max; i++) if(ans[i] > 0) printf("%d: %d\n", i, ans[i]);
}
int main()
{
	while(init()) solve();
	return 0;
}
