#include <stdio.h>
#define MAX_ROBOTS 105
#define WALL 9999
typedef struct
{
	int x;
	int y;
}Pt2D;
typedef struct
{
	Pt2D pos;
	Pt2D dir;
	int stat;
}Robot;
Robot robot[MAX_ROBOTS];
int a, b, n, m;
int check(int i)
{
	int tx = robot[i].pos.x;
	int ty = robot[i].pos.y;
	int j;
	if(tx <= 0 || tx > a || ty <= 0 || ty > b) return WALL;
	for(j = 1;j <= n; j++) if(i != j && tx == robot[j].pos.x && ty == robot[j].pos.y) return j;
	return 0;
}
void turn(Pt2D* v, char dir)
{
	int tx, ty;
	if(dir == 'L')
	{
		tx = -(v->y);
		ty = v->x;
	}
	else 
	{
		tx = v->y;
		ty = -(v->x);
	}
	v->x = tx;
	v->y = ty;
}
void move(int no, char action, int repeat)
{
	int res, i;
	if(action != 'F') for(i = 0;i < repeat % 4; i++) turn(&(robot[no].dir), action);
	else
	{
		for(i = 1;i <=repeat; i++)
		{
			robot[no].pos.x += robot[no].dir.x;
			robot[no].pos.y += robot[no].dir.y;
			res = check(no);
			if(res != 0)
			{
				robot[no].stat = res;
				break;
			}
		}
	}
}

void init()
{
	char str[2];
	int i, j, x, y;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &n, &m);
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d %s", &x, &y, str);
		robot[i].pos.x = x;
		robot[i].pos.y = y;
		robot[i].stat = -1;
		switch(str[0])
		{
			case 'S': robot[i].dir.x =  0;robot[i].dir.y = -1;break;
			case 'E': robot[i].dir.x =  1;robot[i].dir.y =  0;break;
			case 'N': robot[i].dir.x =  0;robot[i].dir.y =  1;break;
			case 'W': robot[i].dir.x = -1;robot[i].dir.y =  0;break;
		}
	}
}
void run()
{
	char str[2];
	int flag, no, re, i;
	flag = -1;
	for(i = 1;i <= m; i++)
	{
		scanf("%d %s %d", &no, str, &re);
		if(flag == -1)
		{
			move(no, str[0], re);
			if(robot[no].stat != -1) flag = no;
		}
	}
	if(flag == -1) printf("OK\n");
	else
	{
		if(robot[flag].stat == WALL) printf("Robot %d crashes into the wall\n", flag);
		else printf("Robot %d crashes into robot %d\n", flag, robot[flag].stat);
	}
}
int main()
{
	int k;
	scanf("%d", &k);
	while(k--)
	{
		init();
		run();
	}
	return 0;
}
