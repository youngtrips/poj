#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char tel[100000][8];
char chto(char ch)
{
	char d;
	switch(ch)
	{
		case 'A':
		case 'B':
		case 'C':
			d='2'; break;
		case 'D':
		case 'E':
		case 'F':
			d='3'; break;
		case 'G':
		case 'H':
		case 'I':
			d='4'; break;
		case 'J':
		case 'K':
		case 'L':
			d='5'; break;
		case 'M':
		case 'N':
		case 'O':
			d='6'; break;
		case 'P':
		case 'R':
		case 'S':
			d='7'; break;
		case 'T':
		case 'U':
		case 'V':
			d='8'; break;
		case 'W':
		case 'X':
		case 'Y':
			d='9'; break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			d=ch;	
			break;
	}
	return d;
}
int cmp(const void* p1,const void* p2)
{
	return strcmp((char*)p1,(char*)p2);
}
int main()
{
	char ch;
	int t,i,j,flag,num;
	scanf("%d",&t);
	getchar();
	for(i = 0;i < t; i++)
	{	
		j = 0;
		ch = getchar();
		while(ch != '\n')
		{
			if(ch != '-') tel[i][j++] = chto(ch);
			ch = getchar();	
		}
		tel[i][j] = '\0';
	}
	qsort(tel,t,sizeof(tel[0]),cmp);
	j = 1;
	flag = 0;
	while(j < t)
	{
		num = 1;
		while(!strcmp(tel[j],tel[j-1]))
		{
			num++;
			j++;
		}
		if(num>1)
		{
			flag = 1;
			for(i = 0;i < 3; i++) printf("%c",tel[j-1][i]);
			printf("-");
			for(i = 3;i < 7; i++) printf("%c",tel[j-1][i]);
			printf(" %d\n",num);
		}
		j++;
	}
	if(flag == 0) printf("No duplicates.\n");
	return 0;
}
