#include <stdio.h>

int CT(char ch)

{

	if(ch == ' ') return 0;

	else return ch - 64;

}

int main()

{

	int i = 1;

	int sum = 0;

	char ch;

	ch = getchar();

	while(ch != '#')

	{

		sum +=i * CT(ch);

		i++;

		while((ch = getchar()) != '\n')

		{

			sum +=i * CT(ch);

			i++;

		}
		printf("%d\n", sum);

		sum = 0;

		i = 1;

		ch = getchar();

	}

	return 0;

}
