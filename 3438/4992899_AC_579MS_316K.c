#include <stdio.h>

#include <string.h>

int main()

{

	char tmp,str[1001];

	int i,c,t;

	scanf("%d",&t);

	while(t--)

	{

		scanf("%s",str);

		for(i = 0;i < strlen(str); )

		{

			c = 0;

			tmp = str[i];

			while(str[i] == tmp)

			{

				c++;

				i++;

			}

			printf("%d%c",c,tmp);

		}

		printf("\n");

	}

	return 0;

}

