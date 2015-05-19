#include <stdio.h>
#include <string.h>
#define MAXN 1024
char str[MAXN];
int f[MAXN];
int main()
{
	int tmp, i;
	while(1)
	{
		scanf("%s", str+1);
		if(!strcmp(str+1, "0")) break;
		f[0] = 1; f[1] = 1;
		for(i = 2;str[i] != '\0'; i++)
		{
			if(str[i] == '0') f[i] = f[i-2];
			else
			{
				tmp = (str[i-1] - '0') * 10 + str[i] - '0';
				if(tmp >= 10 && tmp <= 26) f[i] = f[i-1] + f[i-2];
				else f[i] = f[i-1];
			}
		}
		printf("%d\n", f[i-1]);
	}
	return 0;
}
