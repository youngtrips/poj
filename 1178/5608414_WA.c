#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define oo 9999999
#define MAXN 66
int kin_mv[8][2] = {{1,  0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, { 0, -1}, {1, -1}};
int kni_mv[8][2] = {{2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}};
int knight[MAXN][MAXN];
int king[MAXN][MAXN];
int pos_kni[MAXN];
int pos_kin;
int cnt;
char place[MAXN * 2];
void preprocess()
{
	int tx, ty, x, y, i, j, k;
	for(i = 1;i <= 64; i++)
	{
		for(j = 1;j <= 64; j++)
		{
			k = (i == j ? 0 : oo);
			knight[i][j] = k;
			king[i][j] = k;
		}
	}
	for(i = 1;i <= 64; i++)
	{
		x = (i - 1) / 8 + 1; y = (i - 1) % 8 + 1;
		for(k = 0;k < 8; k++)
		{
			tx = kni_mv[k][0] + x; ty = kni_mv[k][1] + y;
			if(tx < 1 || tx > 8 || ty < 1 || ty > 8) continue;
			j = (tx - 1) * 8 + ty;
			knight[i][j] = 1;
		}
	}
	for(k = 1;k <= 64; k++)
		for(i = 1;i <= 64; i++)
			for(j = 1;j <= 64; j++) 
				if(knight[i][j] > knight[i][k] + knight[k][j]) knight[i][j] = knight[i][k] + knight[k][j];
	for(i = 1;i <= 64; i++)
	{
		x = (i - 1) / 8 + 1; y = (i - 1) % 8 + 1;
		for(k = 0;k < 8; k++)
		{
			tx = kin_mv[k][0] + x; ty = kin_mv[k][1] + y;
			if(tx < 1 || ty > 8 || ty < 1 || ty > 8) continue;
			j = (tx - 1) * 8 + ty;
			king[i][j] = 1;
		}
	}
	for(k = 1;k <= 64; k++)
		for(i = 1;i <= 64; i++)
			for(j = 1;j <= 64; j++)
				if(king[i][j] > king[i][k] + king[k][j]) king[i][j] = king[i][k] + king[k][j];
}
void solve()
{
	int tot, ans, tmp1, tmp2, i, j, k;
	pos_kin = (place[1] - '1') * 8 + (place[0] - 'A' + 1);
	cnt = 0;
	for(i = 2, j = 3; place[j] != '\0'; i +=2, j += 2)
		pos_kni[++cnt] = (place[j] - '1') * 8 + (place[i] - 'A' + 1);
	ans = oo;
	for(k = 1;k <= 64; k++)
	{
		tot = 0;
		for(i = 1;i <= cnt; i++) tot += knight[pos_kni[i]][k];
		for(j = 1;j <= 64; j++)
		{
			tmp1 = king[pos_kin][j];
			tmp2 = oo;
			for(i = 1;i <= cnt; i++)
				tmp2 = MIN(tmp2, knight[pos_kni[i]][j] + knight[j][i] - knight[pos_kni[i]][k]);
			ans = MIN(ans, tot + tmp1 + tmp2);
		}
	}
	printf("%d\n", ans);
}
int main()
{
	int i, j, k;
	preprocess();
	while(gets(place)) solve();
	return 0;
}
