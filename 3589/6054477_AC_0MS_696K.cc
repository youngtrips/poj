/*
 * Author: youngtrips
 * Created Time:  Mon 26 Oct 2009 07:23:38 PM CST
 * File Name: 3589.cpp
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

int pos[10];
string x;
string y;

void init() {
	cin >>x>>y;
}
void solve() {
	int a = 0;
	int b = 0;
	memset(pos, -1, sizeof(pos));
	FOR(i, x.length()) {
		pos[x[i] - '0'] = i;
	}
	FOR(i, y.length()) {
		if(pos[y[i] - '0'] == i) {
			a++;
		} else if(pos[y[i] - '0'] != i && pos[y[i] - '0'] != -1) {
			b++;
		}
	}
	printf("%dA%dB\n", a, b);
}
int main() {
	int t;
	cin >>t;
	while(t--) {
		init();
		solve();
	}
    return 0;
}

