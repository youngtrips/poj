#include <stdio.h>
#include <string.h>

const char* table = "VWXYZABCDEFGHIJKLMNOPQRSTU";

void decode(char* buf)
{
	size_t len = strlen(buf);
	size_t i;
	for(i = 0;i < len; i++)
	{
		if(buf[i] >= 'A' && buf[i] <= 'Z')
		{
			buf[i] = table[buf[i] - 'A'];
		}
	}
}

int main()
{
	char buf[1024];
	gets(buf);
	while(strcmp(buf, "ENDOFINPUT") != 0)
	{
		while(1)
		{
			gets(buf);
			if(!strcmp(buf, "END")) break;
			decode(buf);
			printf("%s\n", buf);
		}
		gets(buf);
	}
	return 0;
}
