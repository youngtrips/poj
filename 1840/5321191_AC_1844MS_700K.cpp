#include <cstdio>
#include <map>
using namespace std;
map <int , int> hash;
int pow3[120];
void init()
{
	int i;
	for(i = -50;i <= 50; i++) pow3[i + 50] = i * i * i;
}
int main()
{
	int a1, a2, a3, a4, a5;
	int ans, i, j, k, t;
	init();
	scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
	for(i = -50;i <= 50; i++)
	{
		if(i == 0) continue;
		for(j = -50;j <= 50; j++)
		{
			if(j == 0) continue;
			k = a1 * pow3[i + 50] + a2 * pow3[j + 50];
			if(hash.end() == hash.find(k)) hash[k] = 1;
			else hash[k]++;
		}
	}
	ans = 0;
	for(i = -50;i <= 50; i++)
	{
		if(i == 0) continue;
		for(j = -50;j <= 50; j++)
		{
			if(j == 0) continue;
			for(k = -50;k <= 50; k++)
			{
				if(k == 0) continue;
				t = a3 * pow3[i + 50] + a4 * pow3[j + 50] + a5 * pow3[k + 50];
				if(hash.find(-t) != hash.end()) ans += hash[-t];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
