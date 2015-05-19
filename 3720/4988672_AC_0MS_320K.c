#include <stdio.h>

#include <memory.h>



int flag[101][10];

int result[200];

int mod[100];

int hp_div(int n)

{

	int tmp;

	int a;

	int i;

	memset(result, 0, sizeof(result));

	memset(mod, 0, sizeof(mod));

	i = 0;

	a = 1;

	tmp = a % n;

	mod[tmp] = 1;

	result[i] = a / n;

	i++;

	while(tmp)

	{

		a = tmp * 10;

		tmp = a % n;

		result[i] = a / n;

		i++;

		if(1 == mod[tmp])

			break;

		mod[tmp] = 1;

	}

	return i;

}

int count(int len, int k)

{

	int tmp;

	int i;

	tmp = 0;

	for(i = 1;i < len; i++)

		if(result[i] == k)

			tmp++;

	return tmp;

}

int dosome(int n, int k)

{

	int tmp;

	int len;

	int i;

	memset(flag, 0, sizeof(flag));

	tmp = 0;

	for(i = 2;i <= n; i++)

	{

		len = hp_div(i);

		tmp += count(len, k);

	}

	return tmp;

}

int main()

{

	int n;

	int k;

	while(scanf("%d %d",&n,&k) != EOF)

		printf("%d\n",dosome(n,k));

	return 0;

}
