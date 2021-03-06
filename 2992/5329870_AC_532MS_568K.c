#include <stdio.h>
#include <string.h>
#define MAX 83
int fac[432][MAX];
int p[83] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431};
void gen()
{
	int i, j, t, x;
	memset(fac, 0, sizeof(fac));
	for(i = 2;i <= 431; i++)
	{
		for(j = 0;j < 83; j++) fac[i][j] = fac[i-1][j];
		t = i; j = 0;
		while(t > 1)
		{
			while(t % p[j] == 0)
			{ 
				fac[i][j]++; 
				t /= p[j];
			}
			j++;
		}
	}
}
int main()
{
	long long ans;
	int n, k, i;
	gen();
	while(scanf("%d %d", &n, &k) != EOF)
	{
		ans = 1;
		for(i = 0;i < 83; i++)
			ans *= (fac[n][i] - fac[k][i] - fac[n-k][i] + 1);
		printf("%lld\n", ans);
	}
	return 0;
}
