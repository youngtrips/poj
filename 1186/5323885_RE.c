#include <stdio.h>
#define MAX 4000037
struct hash_t
{
	int v;
	int cnt;
	struct hash_t* next;
};
struct hash_t has[MAX];
struct hash_t list[MAX];
struct hash_t* ptr;
int cnt, mid, n, m;
int k[6], p[6];
void init_hash()
{
	int i;
	ptr = list;
	for(i = 0;i < MAX; i++) { has[i].next = NULL; has[i].cnt = 0;}
}
int hash(int x)
{
	return (x + 4000037) % MAX;
}
void insert(int x)
{
	struct hash_t* t;
	int i;
	i = hash(x);
	if(has[i].cnt > 0 && has[i].v != x)
	{
		t = ptr++;
		t->v = x;
		t->cnt++;
		t->next = has[i].next;
		has[i].next = t;
	}
	else if(has[i].cnt > 0 && has[i].v == x) has[i].cnt++;
	else if(has[i].cnt == 0)
	{
		has[i].v = x;
		has[i].cnt++;
	}
}
int find(int x)
{
	struct hash_t* t;
	int i, j;
	i = hash(x);
	if(has[i].cnt > 0 && has[i].v != x)
	{
		t = has[i].next;
		while(t != NULL)
		{
			if(t->v == x) return t->cnt;
			t = t->next;
		}
		return 0;
	}
	else if(has[i].cnt > 0 && has[i].v == x) return has[i].cnt;
	return 0;
}
int qpow(int a, int b)
{

      int ret = 1;
      for(; b; b >>= 1) 
	  {
           if(b & 0x1)  ret *= a;
           a *= a;
      }
      return ret;
}
void left(int val, int dp)
{
	int i;
	if(dp == mid)
	{
		insert(val); 
		return;
	}
	for(i = 1;i <= m; i++) left(val + k[dp] * qpow(i, p[dp]), dp + 1);
}
void right(int val, int dp)
{
	int i;
	if(dp == n) 
	{
		cnt += find(-val); 
		return;
	}
	for(i = 1;i <= m; i++) right(val + k[dp] * qpow(i, p[dp]), dp + 1);
}
int main()
{
	int i;
	init_hash();
	cnt = 0;
	scanf("%d %d", &n, &m);
	for(i = 0;i < n; i++) scanf("%d %d", k + i, p + i);
	mid = n / 2;
	left(0, 0);
	right(0, mid);
	printf("%d\n", cnt);
	return 0;
}
