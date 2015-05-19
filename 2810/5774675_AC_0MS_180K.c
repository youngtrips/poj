#include <stdio.h>
#include <string.h>
int main()
{
	int i = 0, j;
	float a,r,p;
	char ch,u[11],v[100],nosignificant[100][100]; 
	scanf("%f %s %f",&a,u,&r);
	getchar();
	gets(v);
	while(a >= 0)
	{
		p = a / r;
		if(p <= 0.01)
		{
			strcpy(nosignificant[i],v);
			i++;
		}
		else
		{
			ch = '%';
			printf("%s %0.1f %s %0.f%c\n",v,a,u,p*100,ch);
		}
		scanf("%f %s %f",&a,u,&r);
		getchar();
		gets(v);
	}
	printf("Provides no significant amount of:\n");
	for(j = 0;j < i; j++) printf("%s\n",nosignificant[j]);
	return 0;
}
