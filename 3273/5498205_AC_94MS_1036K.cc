#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n,m;
int a[100000];
bool ok(int mid)
{
    int i,j,k;
    if(mid<a[0]) return false;
    int cur=a[0],cnt=1;
    for(i=1;i<n;i++)
    {
        if(cur+a[i]<=mid) cur+=a[i];
        else
        {
            if(mid<a[i]) return false;
            cnt++;
            cur=a[i];
        }    
    }    
    return cnt<=m;
}    

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,k=1,ca,sum;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        sum=0;
        for(i=0;i<n;i++) {scanf("%d",a+i);sum+=a[i];}
        int ll=0,rr=sum;
        int mid;
        while(ll<rr)
        {
            mid=(ll+rr)>>1;
            if(ok(mid)) rr=mid;
            else ll=mid+1;
        }    
        printf("%d\n",rr);
    }
    //system("pause");
    return 0;
} 