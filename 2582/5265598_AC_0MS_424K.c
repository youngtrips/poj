#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-20
#define MAXD 11
#define MAXF 16
typedef struct
{
	int x;
	int y;
	int z;
}point_t;
point_t bomb[MAXD];
point_t fish[MAXF];
int flag[MAXF];
int n_b, n_f;
int to_array(char* str, point_t point[])
{
	int tmp[50];
	int i, j, n;
	i = 0;
	j = 0;
	while(1)
	{
		n = 0;
		while(str[i] >= '0' && str[i] <= '9')
		{
			n = n * 10 + str[i] - '0';
			i++;
		}
		tmp[j++] = n;
		while(str[i] == ' ') i++;
		if(str[i] == '#') break;
	}
	n = j;
	j = 0;
	for(i = 0;i < n; i += 3)
	{
		point[j].x = tmp[i];
		point[j].y = tmp[i+1];
		point[j].z = tmp[i+2];
		j++;
	}
	return j;
}
int init()
{
	int l, w, d, i, x, y, z;
	char tmp[1000], ch;
	scanf("%s", tmp);
	if(!strcmp(tmp, "ENDOFINPUT")) return 0;
	scanf("%d %d %d", &l, &w, &d);	
	getchar();
	gets(tmp);
	for(i = 0; tmp[i] != '\0'; i++) if(tmp[i] == ',') tmp[i] = ' ';
	tmp[i] = ' ';tmp[i+1] = '#';
	n_b = to_array(tmp, bomb);
	for(i = 0;i < n_b; i++) if(bomb[i].z > d) bomb[i].z = d;
	gets(tmp);
	for(i = 0; tmp[i] != '\0'; i++) if(tmp[i] == ',') tmp[i] = ' ';
	tmp[i] = ' ';tmp[i+1] = '#';
	n_f = to_array(tmp, fish);
	scanf("%s", tmp);
	for(i = 0;i < n_f; i++) flag[i] = 0;
	return 1;
}
int check(int i, int j)
{
	double x1, y1, z1;
	double x2, y2, z2;
	double d;
	x1 = (double)bomb[i].x;
	y1 = (double)bomb[i].y;
	z1 = (double)bomb[i].z;
	x2 = (double)fish[j].x;
	y2 = (double)fish[j].y;
	z2 = (double)fish[j].z;
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
	if(d + eps <= 1.0) return 1;
	return 0;
}
int count()
{
	int cnt = 0, i, j;
	for(i = 0;i < n_b; i++)
		for(j = 0;j < n_f; j++)
			if(flag[j] == 0)
				if(check(i, j)){ flag[j] = 1; cnt++;}
	return cnt;
}
int main()
{
	int res;
	while(init())
	{
		res = count();
		if(res == 0) printf("None of dem fish blowed up!\n");
		else printf("AIEE, I got %d fish, me!\n", res);
	}
	return 0;
}
