#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	int need, sum, t, s, a, i, n;
	scanf("%d", &t);
	for(s = 1;s <= t; s++)
	{
		priority_queue<int> q;
		scanf("%d %d", &need, &n);
		sum = 0;
		for(i = 0;i < n; i++)
		{
			scanf("%d", &a);
			sum += a;
			q.push(a);
		}
		printf("Scenario #%d:\n", s);
		if(sum < need) printf("impossible\n");
		else
		{
			i = 1;
			sum = 0;
			while(!q.empty())
			{
				sum += q.top();
				if(sum >= need) break;
				q.pop();
				i++;
			}
			printf("%d\n", i);
		}
		printf("\n");
	}
	return 0;
}
