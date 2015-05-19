#include <stdio.h>
#include <string.h>
#define MAXN 4194304
#define MAXM 1500000
#define key(x) ((x)&(MAXN-1))
struct hash_t
{
	int val;
	int cnt;
	int next;
};
struct hash_t hash[MAXN + MAXM];
char flag[MAXN];
int ptr;
int cnt, mid, n, m;
int k[6], p[6];
void init_hash()
{
	memset(flag, '0', sizeof(flag));
	ptr = MAXN;
}
void insert(int x)
{
	int k;
	k = key(x);
	if(k < 0) k *= -1;
	k = key(k);
	if(flag[k] == '0')
	{
		hash[k].val = x;
		hash[k].cnt = 1;
		hash[k].next = -1;
		flag[k] = '1';
		return;
	}
	while(k != -1)
	{
		if(hash[k].val == x)
		{
			hash[k].cnt++;
			return;
		}
		if(hash[k].next == -1) break;
		k = hash[k].next;
	}
	hash[k].next = +ptr;
	hash[ptr].val = x;
	hash[ptr].cnt = 1;
	hash[ptr].next = -1;
}
int find(int x)
{
	int k = key(x);
	if(k < 0) k *= -1;
	k = key(k);
	if(flag[k] == '0') return 0;
	while(k != -1)
	{
		if(hash[k].val == x) return hash[k].cnt;
		if(hash[k].next == -1) break;
		k = hash[k].next;
	}
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
