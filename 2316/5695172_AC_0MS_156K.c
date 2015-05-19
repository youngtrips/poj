#include <stdio.h>
#include <string.h>
#define MAXN 12
char r[MAXN];
int main()
{
	char str[MAXN];
	int i;
	scanf("%s", str);
	for(i = 0;str[i] != '\0'; i++) r[i] = str[i];
	r[i] = '\0';
	while(scanf("%s", str) != EOF)
	{
		for(i = 0;str[i] != '\0'; i++) r[i] = (r[i]  - '0' + str[i] - '0') % 10 + '0';
	}
	printf("%s\n", r);
	return 0;
}
