#include <stdio.h>
typedef long long int64;
int64 ext_gcd(int64 m, int64 n, int64* x, int64* y)
{
	int64 x1, y1, x0, y0;
	int64 r, q;
	x0 = 1;
	y0 = 0;
    x1 = 0;
	y1 = 1;
    r = (m % n + n) % n;
    q = (m - r) / n;
    *x = 0;
	*y = 1;
    while(r)
	{ 
		*x = x0 - q * x1;
		*y = y0 - q * y1; 
		x0 = x1;
		y0 = y1;
		x1 = *x;
		y1 = *y;
		m = n;
		n = r;
		r = m % n;
		q = (m - r) / n;
	}
	return n;

}
int64 mod_equa(int64 a, int64 b, int64 n)
{
	int64 d, x, y, e, i;
	d = ext_gcd(a, n, &x, &y);
	if(b % d > 0) return -1;
	e = x * (b / d) % n;
	e = (e + (n / d)) % n;
	return e;
}
int main()
{
	int64 r, x, y, m, n, l;
	scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l);
	r = mod_equa((m - n), (y - x), l);
	if(r == -1) printf("Impossible\n");
	else printf("%lld\n", r);
	return 0;
}
