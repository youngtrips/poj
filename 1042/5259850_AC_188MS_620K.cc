#include <cstdio>
#include <cstring>
#include <queue>
using namespace std; 
struct lake_t
{
	int fish;
	int no;
	friend bool operator < (const lake_t& a, const lake_t& b)
	{
		if(a.fish == b.fish) return a.no > b.no;
		return a.fish < b.fish;
	}
};
int main()
{
	lake_t e;
	int spend[26][26], lake[26], max, tot, walk, left, t[26], d[26], n, h, i, j, p, f = 0;
	while(1)
	{
		scanf("%d", &n); 
		if(n == 0) break;
		if(f) printf("\n");
		scanf("%d", &h);
		h *= 60;
		for(i = 1;i <= n; i++) scanf("%d", lake + i);
		for(i = 1;i <= n; i++) scanf("%d", d + i);
		for(i = 1;i < n; i++) scanf("%d", t + i);
		memset(spend, 0, sizeof(spend));
		max = 0;
		p = 1;
		for(i = 1;i <= n; i++)
		{
			priority_queue <lake_t> q;
			for(j = 1;j <= i; j++)
			{
				e.fish = lake[j];
				e.no = j;
				q.push(e);
			}
			walk = 0;
			for(j = 1;j < i; j++) walk += t[j] * 5;
			left = h - walk;
			tot = 0;
			while(left > 0)
			{
				e = q.top();
				q.pop();
				if(e.fish >= 0) 
				{ 
					tot += e.fish; 
					e.fish -= d[e.no];
					if(e.fish < 0) e.fish = 0;
				}
				spend[i][e.no] += 5;
				q.push(e);
				left -= 5;
			}
			if(max < tot) { max = tot; p = i;}
		}
		for(i = 1;i < n; i++) printf("%d, ", spend[p][i]);
		printf("%d\n", spend[p][i]);
		printf("Number of fish expected: %d\n", max);
		f = 1;
	}
	return 0;
}
