#include <stdio.h>

int mul(char* a,char* b)

{

	int tmp = 0;

	int i;

	int j;

	for(i = 0; a[i]; i++)

		for(j = 0; b[j]; j++)

			tmp += (a[i] - '0') * (b[j] - '0');

	return tmp;

}

int main()

{

	char a[15];

	char b[15];

	int i;

	int j;

	scanf("%s %s",a,b);

	printf("%d\n",mul(a,b));

}

