#include <stdio.h>

#include <string.h>

char num[16][81920];

void init()

{

	int i,p;

	num[0][0] = '{';

	num[0][1] = '}';

	num[0][2] = '\0';

	strcpy(num[1],"{{}}");

	for(i = 2;i < 16; i++)

	{

		strcpy(num[i],num[i-1]);

		p = strlen(num[i]);

		num[i][p-1] = ',';

		num[i][p] = '\0';

		strcat(num[i],num[i-1]);

		p = strlen(num[i]);

		num[i][p] = '}';

		num[i][p+1] = '\0';

	}

}

int main()

{

	int i,t,a,b;

	char s[81930];

	init();

	scanf("%d",&t);

	while(t--)

	{

		scanf("%s",s);

		for(i = 0;i < 16; i++)

			if(!strcmp(s,num[i]))

			{

				a = i;

				break;

			}

		scanf("%s",s);

		for(i = 0;i < 16; i++)

			if(!strcmp(s,num[i]))

			{

				b = i;

				break;

			}

		printf("%s\n",num[a+b]);

	}

	return 0;

}

