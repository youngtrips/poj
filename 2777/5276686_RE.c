#include <stdio.h>
#define MAX 200000
typedef struct
{
	int col;
	int a;
	int b;
}seg_t;
seg_t seg[MAX];
int cnt;
void make_tree(int a, int b, int r)
{
	int mid;
	if(a == b)
	{
		seg[r].col = 1;
		seg[r].a = a;
		seg[r].b = b;
	}
	else
	{
		seg[r].col = 1;
		seg[r].a = a;
		seg[r].b = b;
		mid = (a + b) / 2;
		make_tree(a, mid, r * 2);
		make_tree(mid + 1, b, r * 2 + 1);
	}
}
int single(int a){ return ((a - 1) & a) == 0;}
void insert(int a, int b, int c, int r)
{
	int mid;
	if(a <= seg[r].a && seg[r].b <= b)
	{
		seg[r].col = c;
		return;
	}
	if(seg[r].col == c) return;
	if(single(seg[r].col))
	{
		seg[r * 2].col = seg[r].col;
		seg[r * 2 + 1].col = seg[r].col;
	}
	mid = (seg[r].a + seg[r].b) / 2;
	if(a <= mid) insert(a, b, c, r * 2);
	if(b > mid) insert(a, b, c, r * 2 + 1);
	seg[r].col = seg[r * 2].col | seg[r * 2 + 1].col;
}
void query(int a, int b, int r)
{
	int mid;
	if(a <= seg[r].a && seg[r].b <= b) cnt |= seg[r].col;
	else if(single(seg[r].col)) cnt |= seg[r].col;
	else
	{
		mid = (seg[r].a + seg[r].b) / 2;
		if(a <= mid) query(a, b, r * 2);
		if(b > mid) query(a, b, r * 2 + 1);
	}
}
int count(int x)
{
	int cnt = 0;
	while(x)
	{
		if(x & 1) cnt++;
		x >>= 1;
	}
	return cnt;
}
int main()
{
	char op[2];
	int l, t, o, a, b, c;
	scanf("%d %d %d", &l, &t, &o);
	make_tree(1, l, 1);
	while(o--)
	{
		scanf("%s", op);
		if(op[0] == 'C')
		{
			scanf("%d %d %d", &a, &b, &c);
			if(a > b)
			{
				t = a;
				a = b;
				b = t;
			}
			insert(a, b, 1<<(c-1), 1);
		}
		else
		{
			scanf("%d %d", &a, &b);
			if(a > b)
			{
				t = a;
				a = b;
				b = t;
			}
			cnt = 0;
			query(a, b, 1);
			printf("%d\n", count(cnt));
		}
	}
	return 0;
}
