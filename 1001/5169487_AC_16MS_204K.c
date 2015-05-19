#include <stdio.h>
#include <string.h>
void mul(char* a,char* b,char* result)
{
	int c_m,c_a;
	int la = strlen(a);
	int lb = strlen(b);
	int p = la + lb;
	int tmp_m;
	int tmp_a;
	int len;
	int i, j;
	result[p] = '\0';
	p--;
	len = p;
	c_a = 0;
	for(i = la - 1;i >= 0; i--)
	{
		p = len;
		c_m = 0;
		c_a = 0;
		for(j = lb - 1;j >= 0; j--)
		{
			tmp_m = (a[i] - '0') * (b[j] - '0');
			tmp_a = (result[p] - '0') + (tmp_m + c_m) % 10;
			result[p] = ((tmp_a + c_a) % 10) + '0';
			c_m = (tmp_m + c_m) / 10;
			c_a = (tmp_a + c_a) / 10;
			p--;
		}
		if(c_a != 0) result[p] = ((result[p] - '0') + c_a) + '0';
		if(c_m != 0) result[p] =((result[p] - '0') + c_m) + '0';
		len--;
	}
}
void out(char* str,int dot)
{
	int i;
	int start = 0;
	int n = 0;
	int end = strlen(str) - 1;
	for(i = end;i >= 0; i--)
	{
		n++;
		if(n == dot)
		{
			n = i;
			break;
		}
	}
	while(str[start] == '0') start++;
	if(dot > (end - start + 1))
	{
		printf(".");
		for(i = 0;i < dot - end + start - 1; i++) printf("0");
	}
	for(i = start;i <= end; i++)
	{
		if(i == n) printf(".%c",str[i]);
		else printf("%c",str[i]);
	}
	printf("\n");
}

int main()
{
	char a[501];
	char b[501];
	char r[501];
	char msg[7];
	int n,i,j,dot;
	while(scanf("%s %d", msg, &n) != EOF)
	{
		if(n == 0) printf("1\n");
		else if(n == 1)
		{
			int s = 0;
			int e = strlen(msg) -1;
			while(msg[e] == '0')
				e--;
			while(msg[s] == '0')
				s++;
			if(msg[e] == '.')
				e--;
			for(i = s;i <= e; i++) printf("%c", msg[i]);
			printf("\n");
		}
		else
		{
			i = 0;
			for(j = 0;j < strlen(msg); j++)
				if(msg[j] != '.') a[i++] = msg[j];
				else dot = i;
			j = 0;
			i = strlen(msg) - 1;
			while(msg[i] == '0')
			{
				i--;
				j++;
			}
			a[i] = '\0';
			dot = (strlen(msg) - dot - 1 - j) * n;
			strcpy(b,a);
			for(i = 0;i < n-1; i++)
			{
				memset(r,'0',sizeof(r));
				mul(a,b,r);
				strcpy(a,r);
			}
			out(r,dot);
		}
	}
	return 0;
}

