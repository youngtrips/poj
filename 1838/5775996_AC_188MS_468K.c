#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 16002
typedef struct
{
	int no;
	int x;
	int y;
}point_t;
point_t pos[MAX];
int parent[MAX], rank[MAX], n, k;
void make_set(int n)
{
	int i;
	for(i = 0;i <= n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}
int find_set(int x)
{
	if(x != parent[x]) parent[x] = find_set(parent[x]);
	return parent[x];
}
void union_set(int r1, int r2)
{
	int x = find_set(r1);
	int y = find_set(r2);
	if(x == y) return;
	if(rank[x] > rank[y]) parent[y] = x;
	else 
	{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
}
int cmp1(const void* p1, const void* p2)
{
	point_t* a = (point_t*)p1;
	point_t* b = (point_t*)p2;
	if(a->x == b->x) return a->y - b->y;
	return a->x - b->x;
}
int cmp2(const void* p1, const void* p2)
{
	point_t* a = (point_t*)p1;
	point_t* b = (point_t*)p2;
	if(a->y == b->y) return a->x - b->x;
	return a->y - b->y;
}
int cmp(const void* p1, const void* p2)
{
	return *(int*)p2 - *(int*)p1;
}
int myabs(int x) {return x < 0 ? -x : x;}
int dist(int i, int j) {return myabs(pos[i].x - pos[j].x) + myabs(pos[i].y - pos[j].y);}
void init()
{
	int i, j, d;
	scanf("%d %d", &n, &k);
	make_set(n);
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d", &pos[i].x, &pos[i].y);
		pos[i].no = i;
	}
	qsort((void*)(pos + 1), n, sizeof(pos[1]), cmp1);
	for(i = 1;i <= n; i++)
	{
		if(i - 1 >= 1)
		{
			d = dist(i, i - 1);
			if(d == 1) union_set(pos[i].no, pos[i - 1].no);
		}
		if(i + 1 <= n)
		{
			d = dist(i, i + 1);
			if(d == 1) union_set(pos[i].no, pos[i + 1].no);
		}
	}
	qsort((void*)(pos + 1), n, sizeof(pos[1]), cmp2);
	for(i = 1;i <= n; i++)
	{
		if(i - 1 >= 1)
		{
			d = dist(i, i - 1);
			if(d == 1) union_set(pos[i].no, pos[i - 1].no);
		}
		if(i + 1 <= n)
		{
			d = dist(i, i + 1);
			if(d == 1) union_set(pos[i].no, pos[i + 1].no);
		}
	}
}
int main()
{
	int max = 0, i;
	init();
	memset(rank, 0, sizeof(rank));
	for(i = 1;i <= n; i++)
		rank[find_set(i)]++;
	qsort((void*)&rank[1], n, sizeof(rank[1]), cmp);
	for(i = 1;i <= k; i++) max += rank[i];
	printf("%d\n", max);
	return 0;
}
