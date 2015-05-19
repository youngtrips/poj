#include <stdio.h>

#include <string.h>

int test(char s[],int l)

{

	int i, cap = 0;

	int ch = 0;

	if((s[0] >= 65 && s[0] <= 90) || s[0] == '_' || s[l-1] == '_') return 0;

	for(i = 0;i < l; i++)

	{

		if(s[i] == '_')

		{

			if(s[i+1] == '_') return 0;

			else ch = 1;

		}

		if(s[i] == ' ') return 0;

		if(s[i] >= 65 && s[i] <= 90) cap = 1;

	}

	if(cap == 1 && ch == 1) return 0;

	else if(cap == 1 && ch == 0) return 2;

	else if(cap == 0 && ch == 1) return 1;

	else if(cap == 0 && ch == 0) return 3;

	else return 0;

}

int main()

{

	char s[100];

	int i, c, l;

	while(gets(s))

	{

		l = strlen(s);

		c  = test(s,l);

		if(c == 0) printf("Error!");

		else if(c == 3) printf("%s", s);

		else if(c == 1)

		{

			for(i = 0;i < l; i++)

			{

				if(s[i] == '_') s[i+1] -= 32;

				else printf("%c", s[i]);

			}

		}

		else if(c == 2)

		{

			for(i = 0;i < l; i++)

			{

				if(s[i] >= 65 && s[i] <= 90)

				{

					printf("_");

					s[i] += 32;

				}

				printf("%c", s[i]);

			}

		}

		printf("\n");

	}

	return 0;

}
