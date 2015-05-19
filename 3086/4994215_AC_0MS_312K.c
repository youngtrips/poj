#include <stdio.h>

int w[301];

int main()

{

	int N,n,i;

	w[1] = 3;

	for(i = 2;i <= 300; i++) w[i] = w[i-1] + 0.5 * i * (i + 1) * (i + 2);
	scanf("%d", &N);

	for(i = 0;i < N; i++)

	{

		scanf("%d", &n);
		printf("%d %d %d\n", i + 1, n, w[n]);

	}

	return 0;

}
