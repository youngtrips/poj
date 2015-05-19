#include <stdio.h>
#include <string.h>
#define MAX 80
char url[MAX];
int main()
{
	int len, i;
	while(1)
	{
		gets(url);
		if(!strcmp(url, "#")) break;
		len = strlen(url);
		for(i = 0;i < len; i++)
		{
			//printf("%c ", url[i]);
			switch(url[i])
			{
				case ' ': putchar('\%'); break;
				case '!': putchar('\%');printf("21"); break;
				case '$': putchar('\%');printf("24"); break;
				case '%': putchar('\%');printf("25"); break;
				case '(': putchar('\%');printf("28"); break;
				case ')': putchar('\%');printf("29"); break;
				case '*': putchar('\%');printf("2a"); break;
				default: putchar(url[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
