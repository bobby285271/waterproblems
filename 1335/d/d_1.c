#include <stdio.h>

int main()
{
    int t;
    scanf("%d\n", &t);
    t *= 90;
    while (t--)
    {
        char temp = getchar();
        putchar(temp == '1' ? '2' : temp);
    }
    return 0;
}