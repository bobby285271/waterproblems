#include <stdio.h>
#include <stdlib.h>

int t, a, b;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

int main()
{

    t = read();
    while (t--)
    {
        a = read();
        b = read();
        printf("%d\n", a + b);
    }
}