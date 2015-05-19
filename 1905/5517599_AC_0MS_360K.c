#include <stdio.h>
#include <math.h>
#define eps 1e-6
double l1, l2, r, h;
double n, c;
void solve()
{
	double tmp;
	double mid, s, t;
	if(fabs(n) < eps) 
	{
		h = 0.0; 
		return;
	}
	l2 = (1.0 + n * c) * l1;
	l1 /= 2.0; l2 /= 2.0;
	s = 0.0; t = l1;
	while(s + eps < t)
	{
		mid = (s + t) / 2.0;
		r = (l1 * l1 + mid * mid) / (2.0 * mid);
		tmp = asin(l1 / r) * r;
		if(tmp + eps < l2) s = mid;
		else t = mid;
	}
	h = s;
}
int main()
{
	while(1)
	{
		scanf("%lf %lf %lf", &l1, &n, &c);
		if(l1 < 0) break;
		solve();
		printf("%0.3f\n", h);
	}
	return 0;
}
