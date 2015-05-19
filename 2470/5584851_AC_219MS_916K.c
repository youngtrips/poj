#include <stdio.h>
#define MAXN 100002
int inv[MAXN];
int p[MAXN];
int n;
int main()
{
	int flag, i;
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		for(i = 1;i <= n; i++) scanf("%d", &p[i]);
		for(i = 1;i <= n; i++) inv[p[i]] = i;
		flag = 0;
		for(i = 1;i <= n; i++) if(inv[i] != p[i]) { flag = 1; break;}
		printf("%s\n", flag == 1 ? "not ambiguous" : "ambiguous");
	}
	return 0;
}
