#include <stdio.h>
#define ABS(x) ((x)<0?-(x):(x))
typedef struct
{
	int x;
	int y;
}pt_t;
pt_t pt[3];
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int main()
{
	long long area, edge, in;
	int dx, dy, i;
	while(1)
	{
		for(i = 0;i < 3; i++) scanf("%d %d", &pt[i].x, &pt[i].y);
		if(pt[0].x == 0 && pt[0].y == 0 && pt[1].x == 0 && pt[1].y == 0 && pt[2].x == 0 && pt[2].y == 0) break;
		edge = 0;
		for(i = 0;i < 3; i++)
		{
			dx = ABS(pt[i].x - pt[(i + 1) % 3].x);
			dy = ABS(pt[i].y - pt[(i + 1) % 3].y);
			edge += gcd(dx, dy);
		}
		area = ABS((pt[2].x - pt[0].x) * (pt[1].y - pt[0].y) - (pt[1].x - pt[0].x) * (pt[2].y - pt[0].y));
		in = (area - edge) / 2 + 1;
		printf("%lld\n", in);
	}
	return 0;
}
