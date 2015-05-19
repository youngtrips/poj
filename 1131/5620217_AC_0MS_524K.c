#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
void Div(char* a,int b,char* result)
{
	int m,i;
	int r;
	m = a[0] - '0';
	r = m % b;
	result[0] = m / b + '0';
	result[1] = '.';
	i = 2;
	while(r != 0 || (i < strlen(a)))
	{
		if(i >= strlen(a))
			m = r * 10;
		else
			m = r * 10 + (a[i] - '0');
		r = m % b;
		result[i] = m / b + '0';
		i++;
	}
	result[i] = '\0';
}
void add(char* a,char* b,char* sum)
{
	int la = strlen(a);
	int lb = strlen(b);
	int p1 = max(la,lb);
	int p2 = min(la,lb);
	int tmp, i, c = 0;
	sum[p1] = '\0';
	if(la != lb)
	{
		for(i = p2;i < p1; i++)
		{
			if(p1 == la)
				sum[i] = a[i];
			else
				sum[i] = b[i];
		}
	}
	for(i = p2 - 1;i >= 2; i--)
	{
		tmp = (a[i] - '0') + (b[i] - '0');
		sum[i] = ((tmp + c) % 10) + '0';
		c = (tmp + c) / 10;
	}
	if(c != 0)
		sum[0] = c + '0';
	else
	{
		sum[0] = '0';
		sum[1] = '.';
	}
}
int main()
{
	long long n;
	int m, i, k;
	char a[100000];
	char b[100000];
	char r[100000];
	char str[100000];
	while(scanf("%s", str) != EOF)
	{
		if(strlen(str) == 1)
		{
			if(str[0] == '0') printf("%s [8] = 0 [10]\n", str);
			else printf("%s [8] = 1 [10]\n", str);
		}
		else
		{
			n = 8;
			strcpy(r, "0.0");
			for(i = 2;i < strlen(str); i++)
			{
				m = str[i] - '0';
				if(m != 0)
				{
					a[0] = str[i];
					a[1] = '.';
					a[2] = '0';
					a[3] = '\0';
					for(k = 0;k < i-1; k++)
					{
						Div(a,n,b);
						strcpy(a,b);
					}
					add(b,r,r);
				}
			}
			printf("%s [8] = %s [10]\n", str, r);
		}
	}
	return 0;
}
