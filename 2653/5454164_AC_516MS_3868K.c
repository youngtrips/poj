#include <stdio.h>
#include <stdlib.h>
#define MAX 100010
typedef struct
{
	double x;
	double y;
}point_t;
point_t st[MAX];
point_t ed[MAX];
int queue[MAX];
int ans[1002];
int head, tail;
int n;
int cmp(const void* p1, const void* p2){return *(int*)p1 - *(int*)p2;}
double multi(point_t p1, point_t p2, point_t p0)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double max(double a, double b) { if(a > b) return a; return b;}
double min(double a, double b) { if(a < b) return a; return b;}
int cross(point_t s1, point_t e1, point_t s2, point_t e2)
{
	return (max(s1.x, e1.x) >= min(s2.x, e2.x)) &&
		   (max(s2.x, e2.x) >= min(s1.x, e1.x)) &&
		   (max(s1.y, e1.y) >= min(s2.y, e2.y)) &&
		   (max(s2.y, e2.y) >= min(s1.y, e1.y)) &&
		   (multi(s2, e1, s1) * multi(e1, e2, s1) > 0) &&
		   (multi(s1, e2, s2) * multi(e2, e1, s2) > 0);
}
void push(int x)
{
	queue[tail] = x;
	tail = (tail + 1) % MAX;
}
int pop()
{
	int tmp;
	tmp = queue[head];
	head = (head + 1) % MAX;
	return tmp;
}
int main()
{
	int i;
	int j;
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		head = 0;
		tail = 0;
		for(i = 1;i <= n; i++)
		{
			scanf("%lf %lf %lf %lf", &st[i].x, &st[i].y, &ed[i].x, &ed[i].y);
			push(i);
			while(head != tail && queue[head] != i)
			{
				j = pop();
				if(cross(st[i], ed[i], st[j], ed[j]) == 0) push(j);
			}
		}
		i = 0;
		while(head != tail) ans[++i] = pop();
		qsort((void*)&ans[1], i, sizeof(ans[1]), cmp);
		printf("Top sticks:");
		for(j = 1;j < i; j++) printf(" %d,", ans[j]);
		printf(" %d.\n", ans[j]);
	}
	return 0;
}
