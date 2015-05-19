/*
 * Author: youngtrips
 * Created Time:  Fri 23 Oct 2009 03:00:40 PM CST
 * File Name: 1020.cpp
 * Description: 
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SQR(x) ((x)*(x))
#define MAXINT 0x7FFFFFFF
#define MAXINT64 0x7FFFFFFFFFFFFFFFLL
typedef long long int64;

#define MAXN 18

int map[MAXN][MAXN];
int row[MAXN];
int side[MAXN];
int m;
int n;
int ok;

void init() {
	int sum;
	int i;
	scanf("%d %d", &n, &m);
	sum = 0;
	for(i = 1;i <= m; i++) {
		scanf("%d", side + i);
		sum += side[i] * side[i];
	}
	ok = (sum == (n * n));
}

int fill(int s, int stx, int sty) {
	int r = stx + s - 1;
	int c = sty + s - 1;
	int i, j;
	if(r > n || c > n) return 0;
	for(i = stx;i <= r; i++) {
		for(j = sty;j <= c; j++) {
			if(map[i][j] == 1) return 0;
		}
	}
	for(i = stx; i <= r; i++) {
		for(j = sty;j <= c; j++) {
			map[i][j] = 1;
		}
		row[i] += s;
	}
	return 1;
}

void debug() {
	int i, j;
	for(i = 1;i <= n; i++) {
		for(j = 1;j <= n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void dfs(int r, int p) {
	int i;
	if(r > n) return;
	if(p == n) {
		ok = 1;
		return;
	}
	if(fill(side[p], r, row[r])) {
		for(i = 1;i <= n; i++) {
			if(row[i] <= n) {
				dfs(i, p + 1);
			}
		}
	} else {
		dfs(r + 1, p);
	}
}
						

void solve() {
	if(ok == 0) {
		printf("HUTUTU!\n");
	} else {
		memset(row, 0, sizeof(row));
		memset(map, 0, sizeof(map));
		row[1] = 1;
		ok = 0;
		dfs(1, 1);
		if(ok) {
			printf("KHOOOOB!\n");
		} else {
			printf("HUTUTU!\n");
		}
	}
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
