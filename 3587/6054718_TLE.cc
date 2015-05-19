/*
 * Author: youngtrips
 * Created Time:  Mon 26 Oct 2009 07:50:19 PM CST
 * File Name: 3587.cpp
 * Description: 
 */
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b); i++)
#define FOR(i,n) FR(i,0,n)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SQR(x) ((x)*(x))
#define MAXINT64 0x7FFFFFFFFFFFFFFFLL
#define MAXINT 0x7FFFFFFF
#define eps 1e-12
#define MP make_pair
#define PB push_back
#define A first
#define B second

typedef long long int64;
#define MAXN 660

int64 x[MAXN];
int64 y[MAXN];
int64 l[MAXN][MAXN];
int n;

void init() {
	int i, j;
	scanf("%d", &n);
	for(i = 0;i < n; i++) {
		scanf("%lld %lld", x + i, y + i);
	}
	memset(l, -1, sizeof(l));
	for(i = 0;i < n; i++) {
		for(j = i + 1;j < n; j++) {
			l[i][j] = l[j][i] = SQR(x[i] - x[j]) + SQR(y[i] - y[j]);
		}
	}
}
int64 cross(int64 x1, int64 y1, int64 x2, int64 y2) {
	return x1 * y2 - x2 * y1;
}
int64 my_abs(int64 x) {
	return x < 0 ? -x : x;
}
void solve() {
	int i, j, k;
	double ans;
	int64 a, b;
	int64 c, d;
	a = 0; b = 1;
	for(i = 0;i < n; i++) {
		for(j = i + 1;j < n; j++) {
			for(k = j + 1;k < n; k++) {
				c = l[i][j] * l[i][k] * l[j][k];
				d = my_abs(cross(x[j] - x[i], y[j] - y[i], x[k] - x[i], y[k] - y[i]));
				d <<= 1;
				if(a * d < b * c) {
					a = c;
					b = d;
				}
			}
		}
	}
	ans = sqrt((double)a) / (double)b;
	printf("%0.3lf\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		init();
		solve();
	}
    return 0;
}

