#include <stdio.h>
#include <stdlib.h>
#define MAXN 50002
typedef struct
{
	int a;
	int b;
	int p;
}vote_t;
vote_t v[MAXN];
int n, k;
int cmpa(const void* p1, const void* p2)
{
	vote_t* v1 = (vote_t*)p1;
	vote_t* v2 = (vote_t*)p2;
	return v2->a - v1->a;
}
int cmpb(const void* p1, const void* p2)
{
	vote_t* v1 = (vote_t*)p1;
	vote_t* v2 = (vote_t*)p2;
	return v2->b - v1->b;
}
int main()
{
	int i;
	scanf("%d %d", &n, &k);
	for(i = 1;i <= n; i++) 
	{
		scanf("%d %d", &v[i].a, &v[i].b);
		v[i].p = i;
	}
	qsort((void*)&v[1], n, sizeof(v[1]), cmpa);
	qsort((void*)&v[1], k, sizeof(v[1]), cmpb);
	printf("%d\n", v[1].p);
	return 0;
}
