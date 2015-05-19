#include <stdio.h>
#include <string.h>
#define max 1008
void xp_add(char* a,char* b,char* c)
{
	int i,j,k,x,y,carry;
	char tmp[max+1];
	char* p;
	if(strlen(a) < strlen(b))
	{
		p = a;
		a = b;
		b = p;
	}
	j = strlen(b) - 1;
	k = max;
	carry = 0;
	for(i = strlen(a) - 1;i >= 0; i--)
	{
		x = a[i] - '0';
		if(j < 0) y = 0;
		else y = b[j] - '0';
		carry += x + y;
		tmp[k] = carry % 10 + '0';
		carry /= 10;
		k--;
		j--;
	}
	if(carry != 0)
	{
		tmp[k] = carry + '0';
		k--;
	}
	k++;
	i = 0;
	for(;k <= max; k++)
	{
		c[i] = tmp[k];
		i++;
	}
	c[i] = '\0';
}
int main()
{
	char a[max], r[max];
	r[0] = '0';r[1] = '\0';
	while(1)
	{
		scanf("%s", a);
		if(a[0] == '0') break;
		xp_add(a, r, r);
	}
	printf("%s\n", r);
	return 0;
}
