#include <stdio.h>
int main()
{
    unsigned int n,top=0,res=0,hi[80010],stack[80010];
    int i;
	scanf("%d", &n);
	for(i=0;i<n;i++)
    {
		scanf("%d", &hi[i]);
        while(top>0&&hi[i]>=stack[top])  top--;
        res+=top;
        stack[++top]=hi[i];
    }
	printf("%d\n", res);	
    return 0;
}
