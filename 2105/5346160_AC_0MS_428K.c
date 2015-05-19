#include <stdio.h>
char str[36];
void sovle()
{
    int a, b, c, d, i, j;
    a = 0; b = 0; c = 0; d = 0;
    for(i = 0;i < 8; i++) a = a * 2 + (str[i] - '0');
    for(j = 0;j < 8; j++, i++) b = b * 2 + (str[i] - '0');
    for(j = 0;j < 8; j++, i++) c = c * 2+ (str[i] - '0');
    for(j = 0;j < 8; j++, i++) d = d * 2+ (str[i] - '0');
    printf("%d.%d.%d.%d\n", a, b, c, d);
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", str);
        sovle();
    }
    return 0;
}
