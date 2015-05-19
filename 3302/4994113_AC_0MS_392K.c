#include <stdio.h>

#include <string.h>

int L[101][101],S[101][101];

int check(int m, int n, char x[], char y[], char z[])

{

	int i,j,k;

	for(j = 0;j <= n; j++) L[0][j] = 0;

	for(i = 0;i <= m; i++) L[i][0] = 0;

	for(i = 1;i <= m; i++)

		for(j = 1;j <= n; j++)

            if(x[i] == y[j]) 

			{

				L[i][j] = L[i-1][j-1] + 1;

				S[i][j] = 1; 

			}

			else if(L[i][j-1] >= L[i-1][j])

			{

				L[i][j] = L[i][j-1]; 

				S[i][j] = 2;

			}

			else 

			{

				L[i][j] = L[i-1][j];

				S[i][j] = 3; 

			}

	i = m;

	j = n;

	k = L[m][n];

	while(i > 0 && j > 0)

	{

		if(S[i][j] == 1)

		{

			z[k] = x[i]; 

			k--; 

			i--;

			j--;

		}

		else if(S[i][j] == 2) j--;

		else  i--;

	}

	for(i = k+1,j = 1;i <= L[m][n]; i++,j++)

		if(z[i] != y[j])

			return 0;

	return 1;

}

void ct(char* s1)

{

	char tmp[102];

	tmp[0] = ' ';

	tmp[1] = '\0';

	strcat(tmp,s1);

	strcpy(s1,tmp);

}

int main()

{

	int i,t,j, k;

	char s1[101],s2[102],re_s2[102],s[102],z[102];

	scanf("%d",&t);

	for(i = 0;i < t; i++)

	{

		scanf("%s %s",s1,s2);

		if(strlen(s1) < strlen(s2)) printf("NO\n");

		else

		{

			k = 0;

			for(j = strlen(s2) - 1;j >= 0; j--) re_s2[k++] = s2[j];

			re_s2[k] = '\0';

			ct(s1);

			ct(s2);

			ct(re_s2);

			if(check(strlen(s1),strlen(s2),s1,s2,z) || check(strlen(s1),strlen(re_s2),s1,re_s2,z)) printf("YES\n");

			else printf("NO\n");

		}

	}

	return 0;

}

