#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define oo 99999999
#define MAXN 100
int kin_mv[8][2] = {{1,  0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, { 0, -1}, {1, -1}};
int kni_mv[8][2] = {{2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}};
int knight[MAXN][MAXN];
int king[MAXN][MAXN];
int pos_kni[MAXN];
int pos_kin, cnt, ans;
char place[MAXN + MAXN];
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
			tx = x + kni_mv[k][0]; ty = y + kni_mv[k][1];
			if(tx < 1 || tx > 8 || ty < 1 || ty > 8) continue;
			j = (tx - 1) * 8 + ty;
			knight[i][j] = 1;
		}
	}
	for(k = 1;k <= 64; k++)
		for(i = 1;i <= 64; i++)
			for(j = 1;j <= 64; j++) 
				if(knight[i][j] > knight[i][k] + knight[k][j])	knight[i][j] = knight[i][k] + knight[k][j];
	for(i = 1;i <= 64; i++)
	{
		x = (i - 1) / 8 + 1; y = (i - 1) % 8 + 1;
		for(k = 0;k < 8; k++)
		{
			tx = x + kin_mv[k][0]; ty = y + kin_mv[k][1];
			if(tx < 1 || tx > 8 || ty < 1 || ty > 8) continue;
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
	int tot, tmp1, tmp2, i, j, k;
	pos_kin = (place[1] - '1') * 8 + (place[0] - 'A' + 1);
	cnt = (strlen(place) - 2) / 2;
	for(i = 0, j = 2;i < cnt; i++, j += 2) pos_kni[i+1] = (place[j+1] - '1') * 8 + (place[j] - 'A' + 1);
	if(cnt == 0) { ans = 0; return;}
	ans = oo;
	for(i = 1;i <= 64; i++)
	{
		tot = 0;
		for(k = 1;k <= cnt; k++) tot += knight[pos_kni[k]][i];
		for(j = 1;j <= 64; j++)
		{
			tmp1 = king[pos_kin][j];
			tmp2 = oo;
			for(k = 1;k <= cnt; k++)
				tmp2 = MIN(tmp2, knight[pos_kni[k]][j] + knight[j][i] - knight[pos_kni[k]][i]);
			ans = MIN(ans, tot + tmp1 + tmp2);
		}
	}
}
int main()
{
	int i, j, k;
	preprocess();
	while(scanf("%s", place) != EOF) 
	{
		solve();
		printf("%d\n", ans);
	}
	return 0;
}
