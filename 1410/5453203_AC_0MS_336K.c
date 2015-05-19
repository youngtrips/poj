#include <stdio.h>
typedef struct
{
	double x;
	double y;
}Point;
double multi(Point p1,Point p2,Point p0)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double max(double a,double b)
{
	if(a > b) return a;
	return b;
}
double min(double a,double b)
{
	if(a < b) return a;
	return b;
}
int intersect(Point s1,Point e1,Point s2,Point e2)
{
	return max(s1.x,e1.x) >= min(s2.x,e2.x) &&
			max(s2.x,e2.x) >= min(s1.x,e1.x) &&
			max(s1.y,e1.y) >= min(s2.y,e2.y) &&
			max(s2.y,e2.y) >= min(s1.y,e1.y) &&
			multi(s2,e1,s1) * multi(e1,e2,s1) >= 0 &&
			multi(s1,e2,s2) * multi(e2,e1,s2) >= 0;
}
int is_in(Point p1,Point p3,Point start,Point end)
{
	return (start.x >= p1.x && start.x <= p3.x && start.y >= p3.y && start.y <= p1.y) ||
			(end.x >= p1.x && end.x <= p3.x && end.y >= p3.y && end.y <= p1.y);
}
int check(Point p1,Point p2,Point p3,Point p4,Point start,Point end)
{
	if(is_in(p1,p3,start,end)) return 1;
	return intersect(p1,p2,start,end) ||
			intersect(p2,p3,start,end) ||
			intersect(p3,p4,start,end) ||
			intersect(p4,p1,start,end);
}
int main()
{
	double tmp;
	int n;
	Point p1,p2,p3,p4;
	Point start,end;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&start.x,&start.y,&end.x,&end.y,&p1.x,&p1.y,&p3.x,&p3.y);
		if(p1.x > p3.x)
		{
			tmp = p1.x;
			p1.x = p3.x;
			p3.x = tmp;
		}
		if(p1.y < p3.y)
		{
			tmp = p1.y;
			p1.y = p3.y;
			p3.y = tmp;
		}
		p2.x = p1.x;
		p2.y = p3.y;
		p4.x = p3.x;
		p4.y = p1.y;
		if(check(p1,p2,p3,p4,start,end)) printf("T\n");
		else printf("F\n");
	}
	return 0;
}
