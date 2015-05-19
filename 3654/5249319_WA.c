#include <stdio.h>
#include <string.h>
typedef struct
{
	char e;
	char r[26];
}Ans;
Ans ans[26];
int acl[26][26];
int ent[26], tot;
char log[80];
char s1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char s2[] = "abcdefghijklmnopqrstuvwxyz";
int init()
{
	gets(log);
	if(log[0] == '#') return 0;
	return 1;
}
int is_letter(char ch) { return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');}
void compute()
{
	char rights[80], cur[80], r;
	int len, lc, lr, i, j, k;
	memset(acl, 0, sizeof(acl));
	memset(ent, 0, sizeof(ent));
	len = strlen(log);
	i = 0;
	while(1)
	{
		lc = 0;
		while(is_letter(log[i]))
		{
			cur[lc] = log[i];
			ent[cur[lc] - 'A'] = 1;
			lc++;
			i++;
		}
		if(log[i] == '+' || log[i] == '-' || log[i] == '=')
		{
			r = log[i++];
			lr = 0;
			while(log[i] != ',' && log[i] != '\0')
			{
				rights[lr] = log[i];
				lr++;
				i++;
			}
			if(r == '=')
			{
				for(k = 0;k < lc; k++)
				{
					for(j = 0;j < 26; j++) acl[cur[k] - 'A'][j] = 0;
					for(j = 0;j < lr; j++) acl[cur[k] - 'A'][rights[j] - 'a'] = 1;
				}
			}
			else
			{
				for(k = 0;k < lc; k++)
				{
					for(j = 0;j < lr; j++)
					{
						if(r == '+') acl[cur[k] - 'A'][rights[j] - 'a'] = 1;
						else if(r == '-') acl[cur[k] - 'A'][rights[j] - 'a'] = -1;
					}
				}
			}
			if(log[i] == '\0') break;
			i++;
		}
		else if(log[i] == ',') i++;
		else if(log[i] == '\0') break;
	}
}
int main()
{
	int flag, i, j, k, t = 0;
	while(init())
	{
		t++;
		compute();
		flag = 0;
		tot = 0;
		for(i = 0; i < 26; i++)
		{
			if(ent[i] == 1)
			{
				k = 0;
				ans[tot].e = s1[i];
				for(j = 0;j < 26; j++)
				{
					if(acl[i][j] == 1)
					{
						flag = 1;
						ans[tot].r[k++] = s2[j];
					}
				}
				ans[tot].r[k] = '\0';
				if(k > 0) tot++;
			}
		}
		if(flag == 0) printf("%d:\n", t);
		else
		{
			printf("%d:", t);
			for(i = 0;i < tot; )
			{
				j = i + 1;
				printf("%c", ans[i].e);
				while(strcmp(ans[i].r, ans[j].r) == 0)
				{
					printf("%c", ans[j].e);
					j++;
				}
				printf("%s", ans[i].r);
				i = j;
			}
			printf("\n");
		}
	}
	return 0;
}
