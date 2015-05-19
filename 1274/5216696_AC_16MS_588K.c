#include <stdio.h>
#include <string.h>
#define MAXN 202
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)
int adj[MAXN][MAXN];
int a[MAXN], b[MAXN];
int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2)
{
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}
int main()
{
	int max, n, m, i, j, s;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(adj, 0, sizeof(adj));
		for(i = 0;i < n; i++)
		{
			scanf("%d", &s);
			while(s--)
			{
				scanf("%d", &j);
				adj[i][j-1] = 1;
			}
		}
		max = hungary(n, m, adj, a, b);
		printf("%d\n", max);
	}
	return 0;
}
