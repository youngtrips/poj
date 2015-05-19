#include <stdio.h>
#include <string.h>
#define MAXN 27
char expr[MAXN * MAXN];
char tmp[MAXN * MAXN];
int stack[MAXN];
int val[MAXN][2];
int has[MAXN];
int top;
int len;
int evaluate(char* expr, int len)
{
	char ch, op;
	int val1, val2, cnt, i, j;
	for(i = 1;i <= 26; i++)
	{
		val[i][0] = i;
		val[i][1] = i;
	}
	for(i = 0;i < len; i++)
	{
		if(expr[i] == '+' || expr[i] == '-') continue;
		if(i >= 2 && expr[i-1] == expr[i-2] && expr[i-1] == '+')
		{
			val[expr[i] - 'a' + 1][0]++;
			val[expr[i] - 'a' + 1][1]++;
			expr[i-1] = ' ';
			expr[i-2] = ' ';
		}
		if(i >= 2 && expr[i-1] == expr[i-2] && expr[i-1] == '-')
		{
			val[expr[i] - 'a' + 1][0]--;
			val[expr[i] - 'a' + 1][1]--;
			expr[i-1] = ' ';
			expr[i-2] = ' ';
		}
		if(i + 2 < len && expr[i+1] == expr[i+2] && expr[i+1] == '+')
		{
			val[expr[i] - 'a' + 1][1]++;
			expr[i+1] = ' ';
			expr[i+2] = ' ';
		}
		if(i + 2 < len && expr[i+1] == expr[i+2] && expr[i+1] == '-')
		{
			val[expr[i] - 'a' + 1][1]--;
			expr[i+1] = ' ';
			expr[i+2] = ' ';
		}
	}
	top = -1; cnt = 0;
	for(i = 0;i <= len; i++)
	{
		ch = expr[i];
		if(ch >= 'a' && ch <= 'z')
		{
			stack[++top] = val[ch - 'a' + 1][0];
			cnt++;
		}
		if(cnt == 2)
		{
			val1 = stack[top--];
			val2 = stack[top--];
			if(op == '+') val2 += val1;
			if(op == '-') val2 -= val1;
			stack[++top] = val2;
			cnt = 1;
		}
		if(ch == '+' || ch == '-') op = ch;
	}
	return stack[top];
}
int main()
{
	int res, t, i, j;
	char ch;
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		memset(has, 0, sizeof(has));
		i = 0; j = 0;
		ch = getchar();
		while(ch != '\n')
		{
			while(ch == ' ')
			{
				tmp[j++] = ch;
				ch = getchar();
			}
			if(ch >= 'a' && ch <= 'z') has[ch - 'a' + 1] = 1;
			expr[i++] = ch;
			tmp[j++] = ch;
			ch = getchar();
		}
		expr[i] = '\0';
		tmp[j] = '\0';
		len = i;
		res = evaluate(expr, len);
		printf("Expression: %s\n", tmp);
		printf("value = %d\n", res);
		for(i = 1;i <= 26; i++)
			if(has[i]) printf("%c = %d\n", 'a' + i - 1, val[i][1]);
	}
	return 0;
}
