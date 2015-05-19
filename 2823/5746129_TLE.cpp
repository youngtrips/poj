#include <stdio.h>
#include <string.h>
#define MAXN 1000002
#define _cp_min(a,b) ((a)<(b))
#define _cp_max(a,b) ((a)>(b))
typedef int elem_t;
struct minheap
{
	elem_t h[MAXN];
	int n,p,c;
	void init(){ n = 0;}
	void ins(elem_t e)
	{
		for (p=++n;p>1&&_cp_min(e,h[p>>1]);h[p]=h[p>>1],p>>=1);
		h[p] = e;
	}
	int del(elem_t& e)
	{
		if(!n) return 0;
		for(e=h[p=1],c=2;c<n&&_cp_min(h[c+=(c<n-1&&_cp_min(h[c+1],h[c]))],h[n]);h[p]=h[c],p=c,c<<=1);
		h[p]=h[n--];
		return 1;
	}
};
struct maxheap
{
	elem_t h[MAXN];
	int n,p,c;
	void init(){ n = 0;}
	void ins(elem_t e)
	{
		for (p=++n;p>1&&_cp_max(e,h[p>>1]);h[p]=h[p>>1],p>>=1);
		h[p] = e;
	}
	int del(elem_t& e)
	{
		if(!n) return 0;
		for(e=h[p=1],c=2;c<n&&_cp_max(h[c+=(c<n-1&&_cp_max(h[c+1],h[c]))],h[n]);h[p]=h[c],p=c,c<<=1);
		h[p]=h[n--];
		return 1;
	}
};
int b[MAXN][2];
int a[MAXN];
int cnt, n, l;
struct maxheap maxh;
struct minheap minh;
int main()
{
	int x, y, i, j;
	scanf("%d %d", &n, &l);
	for(i = 1;i <= n; i++) scanf("%d", &a[i]);
	i = 1;j = 1;
	cnt = 0;
	for(i = 1;i + l -1 <= n; i++)
	{
		maxh.init();
		minh.init();
		for(j = 0;j < l; j++)
		{
			maxh.ins(a[i+j]);
			minh.ins(a[i+j]);
		}
		++cnt;
		maxh.del(b[cnt][1]);
		minh.del(b[cnt][0]);
	}
	for(i = 1;i < cnt; i++) printf("%d ", b[i][0]);
	printf("%d\n", b[cnt][0]);
	for(i = 1;i < cnt; i++) printf("%d ", b[i][1]);
	printf("%d\n", b[cnt][1]);
	return 0;
}
