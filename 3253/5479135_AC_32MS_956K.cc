#include <cstdio>
#include <queue>
using namespace std;
struct plank_t
{
	long long len;
	friend bool operator < (const plank_t& a, const plank_t& b)
	{
		return a.len > b.len;
	}
};
priority_queue <plank_t> q;
int main()
{
	plank_t a;
	plank_t b;
	long long ans;
	long long tmp;
	int n, i;
	ans = 0;
	scanf("%d", &n);
	for(i = 0;i < n; i++)
	{
		scanf("%lld", &a.len);
		q.push(a);
	}
	while(!q.empty())
	{
		tmp = 0;
		a = q.top();
		q.pop();
		tmp += a.len;
		if(!q.empty())
		{
			b = q.top();
			q.pop();
			tmp += b.len;
			a.len = tmp;
			q.push(a);
		}
		ans += tmp;
	}
	if(n > 1) ans -= tmp;
	printf("%lld\n", ans);
	return 0;
}
