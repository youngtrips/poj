#include <stdio.h>

int main()

{

	int i;

	char str[80];

	while(gets(str))

	{

		if(str[0] == '#') break;

		i = 0;

		while(str[i])

		{

			if(str[i] == ' ') printf("%%20");

			else if(str[i] == '!') printf("%%21");

			else if(str[i] == '$') printf("%%24");

			else if(str[i] == '%') printf("%%25");

			else if(str[i] == '(') printf("%%28");

			else if(str[i] == ')') printf("%%29");

			else if(str[i] == '*') printf("%%2a");

			else printf("%c",str[i]);

			i++;

		}

		printf("\n");

	}

	return 0;

}

