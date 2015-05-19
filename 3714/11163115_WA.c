#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define eps 1e-12
#define oo 1e20
#define MAXN 100000

#define STATION 0x1
#define AGENT	0x2

typedef double real;
typedef struct {
	real  x;
	real y;
	unsigned char type;
} point_t;

#define SQR(x) ((x) * (x))
#define DIST(a,b) sqrt(SQR(a.x - b.x) + SQR(a.y - b.y))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

point_t tmp_points[MAXN*2+1];

static int cmp_x(const void *p1, const void *p2) {
	point_t *a = (point_t*)p1;
	point_t *b = (point_t*)p2;
	real d = a->x - b->x;
	if (fabs(d) < -eps) return 0;
	return d < 0 ? -1 : 1;
}

static int cmp_y(const void *p1, const void *p2) {
	point_t *a = (point_t*)p1;
	point_t *b = (point_t*)p2;
	real d = a->y - b->y;
	if (fabs(d) < -eps) return 0;
	return d < 0 ? -1 : 1;
}

static real _closest_pair(point_t *points, size_t left, size_t right) {
	size_t mid;
	size_t i;
	size_t j;
	size_t n;
	real d1;
	real d2;
	real d;
			
	if (left == right) {
		return oo;
	}
	if (left + 1 == right) {
		if (points[left].type != points[right].type) {
			return DIST(points[left], points[right]);
		} else {
			return oo;
		}
	}
	mid = (left + right) >> 1;
	d1 = _closest_pair(points, left, mid);
	d2 = _closest_pair(points, mid+1, right);
	d = MIN(d1, d2);
	n = 0;
	for (i = left;i <= right; i++) {
		if (fabs(points[i].x - points[mid].x) + eps <= d) {
			tmp_points[n++] = points[i];
		}
	}
	qsort((void*)tmp_points, n, sizeof(point_t), cmp_y);
	for (i = 0;i < n; i++) {
		for (j = i+1;j < n && tmp_points[j].y - tmp_points[i].y + eps <= d; j++) {
			if (tmp_points[i].type != tmp_points[j].type) {
				d1 = DIST(tmp_points[i], tmp_points[j]);
				d = MIN(d, d1);
			}
		}
	}
	return d;
}

real closest_pair(point_t *points, size_t size) {
	qsort((void*)points, size, sizeof(point_t), cmp_x);
	return _closest_pair(points, 0, size - 1);
}

point_t points[MAXN * 2 + 1];
int main() {
	int x, y;
	int t;
	int n;
	int i;
	int j;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		j = 0;
		for (i = 0;i < n; i++) {
			scanf("%d %d", &x, &y);
			points[j].x = (real)x;
			points[j].y = (real)y;
			points[j].type = STATION;
			++j;
		}
		for (i = 0;i < n; i++) {
			scanf("%d %d", &x, &y);
			points[j].x = (real)x;
			points[j].y = (real)y;
			points[j].type = AGENT;
			++j;
		}
		printf("%0.3lf\n", closest_pair(points, n + n));
	}
	return 0;
}

