#include <stdio.h>
#include <math.h>
int main()
{
	double p;
	int n;
	while(scanf("%d %lf", &n, &p) != EOF) printf("%0.0f\n", pow(p, 1.0 / n));
	return 0;
}
