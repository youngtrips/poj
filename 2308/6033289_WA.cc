/*
 * Author: youngtrips
 * Created Time:  Wed 21 Oct 2009 03:54:00 PM CST
 * File Name: 2308.cpp
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

#define MP(x,y) make_pair((x),(y))
#define MAXN 12
typedef pair<int, int> pt;


char map[MAXN][MAXN];
bool hash[MAXN][MAXN];
bool hash2[MAXN][MAXN];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
int tot;
int ok;

int init() {
	int i, j;
	scanf("%d %d", &n, &m);
	if(n == 0 && m == 0) {
		return 0;
	}
	getchar();
	tot = 0;
	memset(map, '*', sizeof(map));
	for(i = 1;i <= n; i++) {
		for(j = 1;j <= m; j++) {
			map[i][j] = getchar();
			tot += (map[i][j] != '*');
		}
		getchar();
	}
	return 1;
}
pair<int, int> bfs(pair<int, int> st) {
	queue < pair<int, int> > q;
	int tx, ty, x, y, i;
	memset(hash, 0, sizeof(hash));
	hash[st.first][st.second] = 1;
	q.push(st);
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(i = 0;i < 4; i++) {
			tx = x + dx[i];
			ty = y + dy[i];
			if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
			if(hash[tx][ty] == 1) continue;
			if(map[tx][ty] == '*') {
				hash[tx][ty] = 1;
				q.push(MP(tx, ty));
			} else if(map[tx][ty] == map[st.first][st.second]) {
				return MP(tx, ty);
			}
		}
	}
	return MP(-1, -1);
}
void check(pair<int, int> src, pair<int, int> dst, int pre, int dp) {
	int cnt, tx, ty, i;
	if(dst.first == -1 && dst.second == -1) {
		ok = 0;
		return;
	}
	if(dp > 2) {
		return;
	}
	for(i = 0;i < 4; i++) {
		tx = src.first + dx[i];
		ty = src.second + dy[i];
		if(tx < 0 || tx > n + 1 || ty < 0 || ty > m + 1) continue;
		if(tx == dst.first && ty == dst.second) {
			cnt = dp + ((pre != i) && (pre != -1));
			if(cnt <= 2) {
				ok = 1;
			}
			return;
		}
		if(map[tx][ty] == '*' && !hash2[tx][ty]) {
			hash2[tx][ty] = true;
			cnt = dp + ((pre != i) && (pre != -1));
			check(MP(tx, ty), dst, i, cnt);
			hash2[tx][ty] = false;
		}
	}
}
void solve() {
	int flag;
	int i, j;
	while(tot > 0) {
		flag = 1;
		for(i = 1;i <= n; i++) {
			for(j = 1;j <= m; j++) {
				if(map[i][j] != '*') {
					pair<int, int> res = bfs(MP(i, j));
					ok = 0;
					memset(hash2, false, sizeof(hash2));
					hash2[i][j] = true;
					check(MP(i, j), res, -1, 0);
					if(ok) {
						map[i][j] = '*';
						map[res.first][res.second] = '*';
						flag = 0;
						tot -= 2;
					}
				}
			}
		}
		if(flag) {
			printf("no\n");
			return;
		}
	}
	printf("yes\n");
}

int main() {
	while(init()) {
		solve();
	}
    return 0;
}
