#include <stdio.h>
#define MASK_ALL 0xFFFFFFFF
typedef unsigned int uint_32;

int main()
{
	uint_32 mask;
	uint_32 r;
	uint_32 x;
	uint_32 y;
	
	scanf("%x,%d,%d", &r, &x, &y);
	mask = MASK_ALL ^ (1<<x);
	r = r & mask;
	mask = (1 << (y)) | (1<<(y-1));
	r = r | mask;
	mask = MASK_ALL ^ (1<<(y-2));
	r = r & mask;
	printf("%x\n", r);
	
	return 0;
}
