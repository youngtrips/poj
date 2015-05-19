#include <iostream>
using namespace std;
int main()
{
    unsigned int n,top=0,res=0,hi[80010],stack[80010];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>hi[i];
        while(top>0&&hi[i]>=stack[top])  top--;
        res+=top;
        stack[++top]=hi[i];
    }
    cout<<res<<endl;     
    return (0);
}