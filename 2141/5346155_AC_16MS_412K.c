#include <stdio.h>
char key[28];
char tmp[28];
char msg[82];
void decoding()
{
    int i;
    for(i = 0;msg[i] != '\0'; i++)
    {
        if(msg[i] >= 'A' && msg[i] <= 'Z') msg[i] = key[msg[i] - 'A'] - 32;
        else if(msg[i] >= 'a' && msg[i] <= 'z') msg[i] = key[msg[i] - 'a'];
    }
}
int main()
{
    gets(key);
    gets(msg);
    decoding();
    printf("%s\n", msg);
    return 0;
}
