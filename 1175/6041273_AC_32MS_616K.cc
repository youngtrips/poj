/*
 * Author: youngtrips
 * Created Time:  Fri 23 Oct 2009 11:15:52 AM CST
 * File Name: 1175.cpp
 * Description: 
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SQR(x) ((x)*(x))
#define MAXINT 0x7FFFFFFF
#define MAXINT64 0x7FFFFFFFFFFFFFFFLL
typedef long long int64;
#define MP make_pair
#define X first
#define Y second
#define MAXN 102
#define eps 1e-12

int dx[8] = { 0,  1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1,  1,  0, -1};

vector < pair<double, char> > set;
char has[MAXN][MAXN];
char map[MAXN][MAXN];
int w, h;

void init() {
	int i, j;
	scanf("%d", &w);
	scanf("%d", &h);
	getchar();
	for(i = 1;i <= h; i++) {
		for(j = 1;j <= w; j++) {
			map[i][j] = getchar();
		}
		getchar();
	}
}

double dist(pair<double ,double> a, pair<double ,double> b) {
	return sqrt(SQR(a.X - b.X) + SQR(a.Y - b.Y));
}
double dist_sum(vector < pair<int, int> > block) {
	unsigned int i, j;
	double ret = 0.0;
	for(i = 0;i < block.size(); i++) {
		for(j = i + 1;j < block.size(); j++) {
			ret += dist(block[i], block[j]);
		}
	}
	return ret;
}

vector <pair<int, int> > bfs(pair<int, int> st) {
	int tx, ty, x, y, i;
	vector < pair<int, int> > res;
	queue < pair<int, int> > q;
	has[st.X][st.Y] = 1;
	q.push(st);
	res.push_back(st);
	while(!q.empty()) {
		x = q.front().X;
		y = q.front().Y;
		q.pop();
		for(i = 0;i < 8; i++) {
			tx = x + dx[i];
			ty = y + dy[i];
			if(tx < 1 || tx > h || ty < 1 || ty > w) continue;
			if(map[tx][ty] == '0') continue;
			if(has[tx][ty] == 1) continue;
			has[tx][ty] = 1;
			q.push(MP(tx, ty));
			res.push_back(MP(tx, ty));
		}
	}
	return res;
}

void debug(vector < pair<int, int> > a) {
	unsigned int i;
	for(i = 0;i < a.size(); i++) {
		printf("(%d, %d)\n", a[i].X, a[i].Y);
	}
	printf("\n");
}
void mark(vector < pair<int, int> > block) {
	double sum = dist_sum(block);
	char k;
	unsigned int i;
	k = '#';
	for(i = 0;i < set.size(); i++) {
		if(fabs(set[i].first - sum) < eps) {
			k = set[i].second;
		}
	}
	if(k == '#') {
		k = set.size() + 'a';
		set.push_back(MP(sum, k));
	}
	for(i = 0;i < block.size(); i++) {
		map[block[i].X][block[i].Y] = k;
	}
//	printf("k: %c\n", k);
}
	
void solve() {
	int i, j;
	memset(has, 0, sizeof(has));
	vector < pair<int, int> > block;
	set.clear();
	for(i = 1;i <= h; i++) {
		for(j = 1;j <= w; j++) {
			if(map[i][j] == '0') continue;
			if(has[i][j] == 1) continue;
			block = bfs(MP(i, j));
			mark(block);
		}
	}
}

void output() {
	int i, j;
	for(i = 1;i <= h; i++) {
		for(j = 1;j <= w; j++) printf("%c", map[i][j]);
		printf("\n");
	}
}
int main() {
	init();
	solve();
	output();
    return 0;
}

