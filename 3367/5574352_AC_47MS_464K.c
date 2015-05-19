#include <stdio.h>
#include <string.h>
#define MAXN 10002
struct node
{
	struct node* lc;
	struct node* rc;
	char val;
};
struct node spool[MAXN];
struct node* stack[MAXN];
struct node* root;
char expr[MAXN];
int head, tail;
int top, tot;
void init()
{
	struct node* cur;
	struct node* lc;
	struct node* rc;
	int i, j;
	tot = 0; top = -1;
	for(i = 0;expr[i] != '\0'; i++)
	{
		cur = spool + tot++;
		cur->val = expr[i];
		cur->lc = NULL;
		cur->rc = NULL;
		if(expr[i] >= 'a' && expr[i] <= 'z') stack[++top] = cur;
		else
		{
			rc = stack[top--];
			lc = stack[top--];
			cur->lc = lc;
			cur->rc = rc;
			stack[++top] = cur;
		}
	}
	root = stack[top];
}
void solve()
{
	int i = 0;
	struct node* cur;
	stack[0] = root;
	head = 0; tail = 1;
	while(head < tail)
	{
		cur = stack[head];
		expr[++i] = cur->val;
		if(cur->lc != NULL) stack[tail++] = cur->lc;
		if(cur->rc != NULL) stack[tail++] = cur->rc;
		head++;
	}
	while(i >= 1) putchar(expr[i--]);
	putchar('\n');
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", expr);
		init();
		solve();
	}
	return 0;
}
