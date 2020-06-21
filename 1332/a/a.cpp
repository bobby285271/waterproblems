#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int x, y, x1, y1, x2, y2;
        scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
        if ((c != 0 || d != 0) && d - c > 0 && y2 - y < d - c)
        {
            printf("No\n");
            continue;
        }
        if ((c != 0 || d != 0) && d - c < 0 && y - y1 < c - d)
        {
            printf("No\n");
            continue;
        }
        if ((b != 0 || a != 0) && b - a > 0 && x2 - x < b - a)
        {
            printf("No\n");
            continue;
        }
        if ((b != 0 || a != 0) && b - a < 0 && x - x1 < a - b)
        {
            printf("No\n");
            continue;
        }
        if ((b != 0 || a != 0) && b - a == 0 && x1 == x && x2 == x)
        {
            printf("No\n");
            continue;
        }
        if ((c != 0 || d != 0) && d - c == 0 && y == y1 && y == y2)
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }
    return 0;
}