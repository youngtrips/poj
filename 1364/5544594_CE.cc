#include<iostream>
#include<cstdio>
using namespace std;
#define M 0x7fffffff

int mat[102][102];
char flg[102][102];
int n,m;
int d[10010];

bool Bellman_ford(){
    int i,j,ii,jj;
    for(i=1;i<=n+1;i++) d[i] = M;
    d[0] = 0; //any value is acceptable here
    for(i=0;i<n;i++){ //do relax n times(n+1 verticeses)
        for(ii=0;ii<=n;ii++){
            for(jj=0;jj<=n;jj++){
                if(ii!=jj && flg[ii][jj]!=0){
                    if(d[jj]>d[ii]+mat[ii][jj]) d[jj]=d[ii]+mat[ii][jj];
                }
            }
        }
    }
    for(ii=0;ii<=n;ii++){ //negative cycle detect
        for(jj=0;jj<=n;jj++){
            if(ii!=jj && flg[ii][jj]!=0){
                if(d[jj]>d[ii]+mat[ii][jj]) return false;
            }
        }
    }
    return true;
}

int main(){
    int i,j;
    int u,v,k;
    char op[4];
    bool res;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        scanf("%d",&m);
        memset(mat,0,sizeof(mat));
        memset(flg,0,sizeof(flg));
        for(i=0;i<m;i++){ //read in data and construct the graph
            scanf("%d %d %s %d",&u,&v,op,&k);
            u+=1;
            if(op[0]=='g'){
                mat[u+v][u-1] = -1-k;
                flg[u+v][u-1] = 1;
            }
            else{
                mat[u-1][u+v] = k-1;
                flg[u-1][u+v] = 1;
            }
        }
        n+=1;
        for(i=1;i<=n;i++){ //add the additional source vertices numbered 0
            mat[0][i] = 0;
            flg[0][i] = 1;
        }
        res = Bellman_ford();
        if(res) printf("lamentable kingdom\n");
        else printf("successful conspiracy\n");
    }
    return 0;
}