#include <stdio.h>
#include <math.h>
#define eps 1e-12
#define pi acos(-1.0)
double w, h;
void swap()
{
	double tmp;
	if(w + eps > h)
	{
		tmp = w;
		w = h;
		h = w;
	}
}
void solve()
{
	double ans, tmp, r1, r2, r;
	swap();
	r1 = h / (2.0 * pi + 2.0);
	r2 = w / 2.0;
	if(r1 + eps < r2) r = r1;
	else r = r2;
	ans = pi * r * r * w;
	tmp = 0.0;
	r = w / (pi * 2.0);
	tmp = pi * r * r * (h - 2 * r);
	if(ans + eps < tmp) ans = tmp;
	printf("%0.3f\n", ans);
}
int main()
{
	while(1)
	{
		scanf("%lf %lf", &w, &h);
		if(w < eps && h < eps) break;
		solve();
	}
	return 0;
}
