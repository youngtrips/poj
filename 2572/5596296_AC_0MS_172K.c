#include <stdio.h>
#include <math.h>
#define MAXN 1024
int a, b, c;
char equa[MAXN];
int is_dig(char ch)
{
	return  ch >= '0' && ch <= '9';
}
void parse()
{
	int i, j;
	a = 0; b = 0; c = 0;
	for(i = 0, j = 0; is_dig(equa[i]); i++, j++) a += (equa[i] - '0') * pow(10.0, j);
	for(;is_dig(equa[i]) == 0; i++);
	for(j = 0;is_dig(equa[i]); i++, j++) b += (equa[i] - '0') * pow(10.0, j);
	for(;is_dig(equa[i]) == 0; i++);
	for(j = 0;is_dig(equa[i]) && equa[i] != '\0'; i++, j++) c += (equa[i] - '0') * pow(10.0, j);
}
int main()
{
	while(gets(equa))
	{
		parse();
		printf("%s\n", a + b == c ? "True" : "False");
	}
	return 0;
}
