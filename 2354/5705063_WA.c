#include <stdio.h>
#include <string.h>
#include <math.h>
#define pi acos(-1.0)
#define r 3437.5
#define eps 1e-12
typedef struct
{
	double x;
	double y;
	double z;
}point;
void change(double latitude,double longitude,point* p)
{
	p->x = r * cos(latitude) * cos(longitude);
	p->y = r * cos(latitude) * sin(longitude);
	p->z = r * sin(latitude);
}
double distance(point A,point B)
{
	double angle, si, d;
	d = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) + (A.z - B.z) * (A.z - B.z));
	si = d / 2.0 / r;
	if(si == 1) angle = pi / 2.0;
	else angle = atan(si / sqrt(1 - si * si));
	return r * angle * 2.0;
}
int main()
{
	int d, m, s;
	char tmp[21];
	point ship, ice;
	double theta, phi, len, v;
	while(1)
	{
		gets(tmp);
		gets(tmp);
		gets(tmp);
		scanf("%d^%d'%d\" %s",&d,&m,&s,tmp);
		v = d + m / 60.0 + s / 3600.0;
		if(tmp[0] == 'S') theta = -1 * v;
		else theta = v;
		scanf("%s",tmp);
		scanf("%d^%d'%d\" %s",&d,&m,&s,tmp);
		v = d + m / 60.0 + s / 3600.0;
		if(tmp[0] == 'W') phi = -1 * v;
		else phi = v;
		theta = theta * pi / 180.0;
		phi = phi * pi / 180.0;
		change(theta,phi,&ship);
		getchar();
		gets(tmp);
		scanf("%d^%d'%d\" %s",&d,&m,&s,tmp);
		v = d + m / 60.0 + s / 3600.0;
		if(tmp[0] == 'S') theta = -1 * v;
		else theta =v;
		scanf("%s",tmp);
		scanf("%d^%d'%d\" %s",&d,&m,&s,tmp);
		v = d + m / 60.0 + s / 3600.0;
		if(tmp[0] == 'W') phi = -1 * v;
		else phi = v;
		theta = theta * pi / 180.0;
		phi = phi * pi / 180.0;
		change(theta,phi,&ice);
		scanf("%s",tmp);
		len = distance(ship,ice);
		printf("The distance to the iceberg: %0.2lf miles.\n",len);
		if(len + eps < 100.0) printf("DANGER!\n");
		if(!strcmp(tmp,"===")) break;
	}
	return 0;
}
