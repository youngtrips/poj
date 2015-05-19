#include <stdio.h>
#include <string.h>
#define MAXN 1002
char real[MAXN];
int parse(char* real)
{
	char ch;
	int len = strlen(real);
	int stat = 1, i;
	for(i = 0;i <= len; i++)
	{
		ch = real[i];
		switch(stat)
		{
			case 1:
				if(ch == ' ') stat = 1;
				else if(ch >= '0' && ch <= '9') stat = 2;
				else if(ch == '+' || ch == '-') stat = 3;
				else stat = 4;
				break;
			case 2:
				if(ch >= '0' && ch <= '9') stat = 2;
				else if(ch == 'e' || ch == 'E') stat = 6;
				else if(ch == '.') stat = 5;
				else if(ch == '\0') return 1;
				else stat = 4;
				break;
			case 3:
				if(ch >= '0' && ch <= '9') stat = 2;
				else stat = 4;
				break;
			case 4:
				return 0;
			case 5:
				if(ch >= '0' && ch <= '9') stat = 7;
				else stat = 4;
				break;
			case 6:
				if(ch == '+' || ch == '-') stat = 8;
				else if(ch >= '0' && ch <= '9') stat = 7;
				else stat = 4;
				break;
			case 7:
				if(ch >= '0' && ch <= '9') stat = 7;
				else if(ch == ' ') stat = 9;
				else if(ch == 'e' || ch == 'E') stat = 6;
				else if(ch == '\0') return 1;
				else stat = 4;
				break;
			case 8:
				if(ch >= '0' && ch <= '9') stat = 7;
				else stat = 4;
				break;
			case 9:
				if(ch == ' ') stat = 9;
				else if(ch == '\0') return 1;
				else stat = 4;
				break;
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		gets(real);
		printf("%s\n", parse(real) == 1 ? "LEGAL" : "ILLEGAL");
	}
	return 0;
}
