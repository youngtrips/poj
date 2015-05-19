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
	if(b == 0 && w == 0) {
	    printf("Impossible\n");
	    return;
	} else if((b == 1 && w == 0) || (b == 0 && w == 1)) {
	    printf("1\n");
	    return;
	}
	if(b == w) {
	    tmp = (int)sqrt((double)(b + b));
	    printf("%d\n", tmp);
	    return;
	} else if(b > w) {
	    tmp = (int)sqrt((double)(w + w + 1));
	    printf("%d\n", tmp);
	    return;
	} else if(b < w) {
	    tmp = (int)sqrt((double)(b + b + 1));
	    printf("%d\n", tmp);
	    return;
	} else {
	    printf("Impossible\n");
	}
}
int main() {
	init();
	solve();
    return 0;
}
