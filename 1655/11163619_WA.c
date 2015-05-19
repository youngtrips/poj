#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 20000

typedef struct {
	int u;
	int v;
	int next;
} edge_t;

edge_t e[MAXN * 2];
int first[MAXN+1];
int tot;
int n;
int visited[MAXN+1];

void init() {
	memset(visited, -1, sizeof(visited));
	memset(first, -1, sizeof(first));
	tot = -1;
}

void add(int u, int v) {
	e[++tot].u = u; e[tot].v = v; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].next = first[v]; first[v] = tot;
}

int dfs(int i, int depth) {
	int t = first[i];
	int max;
	int d;
	max = depth;
	visited[i] = 0;
	while (t != -1) {
		if (visited[e[t].v] == -1) {
			depth++;
			d = dfs(e[t].v, depth);
			depth--;
			if (max < d) {
				max = d;
			}
		}
		t = e[t].next;
	}
	return max;
}

void solve() {
	int min_idx = -1;
	int min_dep = MAXN;
	int i;
	int d;
	for (i = 1;i <= n; i++) {
		memset(visited, -1, sizeof(visited));
		d = dfs(i, 0);
		if (min_dep > d) {
			min_dep = d;
			min_idx = i;
		}
	}
	printf("%d %d\n", min_idx, min_dep);
}

int main() {
	int t;
	int i;
	int u;
	int v;
	scanf("%d", &t);
	while (t--) {
		init();
		scanf("%d", &n);
		for (i = 0;i < n; i++) {
			scanf("%d %d", &u, &v);
			add(u, v);
		}
		solve();
	}
	return 0;
}

