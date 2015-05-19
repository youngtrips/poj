#include <stdio.h>
#define MAXN 1024
char str[MAXN];
int f[MAXN];
int main()
{
	int tmp, i, j;
	while(1)
	{
		scanf("%s", str+1);
		if(str[1] == '0') break;
		f[0] = 1; f[1] = 1;
		for(i = 2;str[i] != '\0'; i++)
		{
			f[i] = f[i-1];
			tmp = 0;
			tmp = (str[i-1] - '0') * 10 + (str[i] - '0');
			if(tmp >= 1 && tmp <= 26) f[i] = f[i-1] + f[i-2];
		}
		printf("%d\n", f[i-1]);
	}
	return 0;
}
