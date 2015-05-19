#include <stdio.h>
typedef struct
{
	int r_out;
	int r_in;
}ring_t;
int check(ring_t a, ring_t b, int p)
{
	if(a.r_out >= b.r_out)
	{
		if(a.r_in >= b.r_out && p >= a.r_out) return 1;
		else if(a.r_out + b.r_out <= p) return 1;
		else return 0;
	}
	else return check(b, a, p);
}
int main()
{
	ring_t a;
	ring_t b;
	int p;
	scanf("%d %d %d %d %d", &a.r_out, &a.r_in, &b.r_out, &b.r_in, &p);
	printf("%s\n", check(a, b, p) == 1 ? "Yes" : "No");
	return 0;
}
