#include <stdio.h>
#include <string.h>
void ct(char s[],long num)
{
	long b;
	int i = 0;
	while(num != 0)
	{
		b = num % 26;
		if(b == 0) s[i++] = 'Z';
		else s[i++] = (char)(b + 64);
		if(b == 0) num -= 26;
		else num -= b;
		num = num / 26;
	}
	s[i] = '\0';
}
int main()
{
	char s[12];
	int i;
	long r,c;
	scanf("R%dC%d",&r,&c);
	getchar();
	while(r != 0 || c!= 0)
	{
		ct(s,c);
		for(i = strlen(s)-1;i >= 0; i--) printf("%c", s[i]);
		printf("%ld\n", r);
		scanf("R%dC%d",&r,&c);
		getchar();
	}
	return 0;
}
