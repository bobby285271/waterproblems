#include <stdio.h>
char c;

int main()
{
    while (getchar() != '\n');
    while ((c = getchar()) != EOF) putchar(c == '1' ? '2' : c);
    return 0;
}