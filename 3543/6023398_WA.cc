/*
 * Created Time: Mon 19 Oct 2009 10:51:26 AM CST
 *    File Name: 3543.cpp
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

typedef long long int64;


int b, w;

void init() {
	scanf("%d %d", &b, &w);
}
void solve() {
	int tmp;
	int s, i;
	int x, y;
	tmp = b + w;
	if(tmp == 0) {
		printf("Impossible\n");
		return;
	} else if((b == 1 && w == 0) || (b == 0 && w == 1)) {
		printf("1\n");
		return;
	} else {
		s = (int)sqrt((double)tmp);
		for(i = s;i >= 1; i--) {
			if(SQR(i) <= tmp) {
				x = i * i / 2;
				y = i * i - x;
				if(b < x || b < y || w < x || w < y) {
					continue;
				} else {
					printf("%d\n", i);
					return;
				}
			}
		}
	}
	printf("Impossible\n");
}
int main() {
	init();
	solve();
    return 0;
}

