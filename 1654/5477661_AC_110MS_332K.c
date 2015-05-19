#include <stdio.h>
typedef struct
{
	long x;
	long y;
}vector;
long long cross(vector a,vector b)
{
	long long t = a.x * b.y - b.x * a.y;
	return t;
}
vector dv(char x)
{
	vector a;
	switch(x)
	{
		case '1':
			a.x = -1;
			a.y = -1;
			break;
		case '2':
			a.x = 0;
			a.y = -1;
			break;
		case '3':
			a.x = 1;
			a.y = -1;
			break;
		case '4':
			a.x = -1;
			a.y = 0;
			break;
		case '6':
			a.x = 1;
			a.y = 0;
			break;
		case '7':
			a.x = -1;
			a.y = 1;
			break;
		case '8':
			a.x = 0;
			a.y = 1;
			break;
		case '9':
			a.x = 1;
			a.y = 1;
			break;
		default:
			a.x = 0;
			a.y = 0;
			break;
	}
	return a;
}

int main()
{
	int t, i, k;
	char ch;
	long long s;
	vector v,temp;
	scanf("%d",&t);
	getchar();
	for(i = 0;i < t; i++)
	{
		s = 0;
		temp.x = 0;
		temp.y = 0;
		v.x = 0;
		v.y = 0;
		while((ch = getchar()) != '5')
		{
			v.x += dv(ch).x;
			v.y += dv(ch).y;
			s += cross(v,temp);
			temp.x = v.x;
			temp.y = v.y;
		
		}
		if(s < 0) s = -s;
		k = 0;
		if(s % 2 == 0) k = 1;
		s = s / 2;
		if(k) printf("%lld\n",s);
		else printf("%lld.5\n",s);
	}
	return 0;
}
