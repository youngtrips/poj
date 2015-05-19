#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100002
typedef struct
{
	char a[11];
	char b[12];
}dic_t;
dic_t dic[MAX];
int tot;
int cmp(const void* p1, const void* p2)
{
	dic_t* d1 = (dic_t*)p1;
	dic_t* d2 = (dic_t*)p2;
	return strcmp(d1->b, d2->b);
}
int find(char* key)
{
	int hight, low, mid, res;
	hight = tot - 1;
	low = 0;
	while(low <= hight)
	{
		mid = (hight + low) / 2;
		res = strcmp(dic[mid].b, key);
		if(res == 0) return mid;
		else if(res < 0) low = mid + 1;
		else hight = mid - 1;
	}
	return -1;
}
int main()
{
	char tmp[22];
	int i;
	tot = 0;
	while(1)
	{
		gets(tmp);
		if(strlen(tmp) == 0) break;
		sscanf(tmp, "%s %s", dic[tot].a, dic[tot].b);
		tot++;
	}
	qsort((void*)dic, tot, sizeof(dic[0]), cmp);
	while(scanf("%s", tmp) != EOF)
	{
		i = find(tmp);
		if(i == -1) printf("eh\n");
		else printf("%s\n", dic[i].a);
	}
	return 0;
}
