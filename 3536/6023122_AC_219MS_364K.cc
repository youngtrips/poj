/*
 * Created Time: Mon 19 Oct 2009 10:22:31 AM CST
 *    File Name: 3536.cpp
 *       Author: youngtrips
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SQR(x) ((x)*(x))
#define MAXINT 0x7FFFFFFF
#define MAXINT64 0x7FFFFFFFFFFFFFFFLL
#define AREA(a,b,c) ((a)*(b)+(b)*(c)+(a)*(c))
typedef long long int64;

#define MAXN 1000002
int f[MAXN];
int tot;
int n;
void init() {
	int i;
	scanf("%d", &n);
	tot = 0;
	for(i = 1;i <= n; i++) {
		if(n % i == 0) {
			f[++tot] = i;
		}
	}
}

void solve() {
	int a, b, c;
	int min = MAXINT;
	int tmp;
	int i, j;
	for(i = 1;i <= tot; i++) {
		for(j = 1;j <= tot; j++) {
			if(n % (f[i] * f[j]) == 0) {
				tmp = AREA(f[i], f[j], n / (f[i] * f[j]));
				if(tmp < min) {
					min = tmp;
					a = f[i];
					b = f[j];
					c = n / (f[i] * f[j]);
				}
			}
		}
	}
	printf("%d %d %d\n", a, b, c);
}

int main() {
	init();
	solve();
    return 0;
}
