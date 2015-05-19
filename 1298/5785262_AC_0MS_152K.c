#include <stdio.h>
#include <string.h>
#define MAXN 27
char re[MAXN] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
int main()
{
	char str[12];
	char ch;
	while(1)
	{
		scanf("%s", str);
		if(!strcmp(str, "ENDOFINPUT")) break;
		getchar();
		while(1)
		{
			ch = getchar();
			if(ch >= 'A' && ch <= 'Z') ch = re[ch - 'A'];
			putchar(ch);
			if(ch == '\n') break;
		}
		scanf("%s", str);
	}
	return 0;
}
