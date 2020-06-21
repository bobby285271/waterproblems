#include <bits/stdc++.h>

using namespace std;

struct temp
{
    int x, y;
} a[1100];

bool cmp(temp a, temp b)
{
    int suma = a.x + a.y;
    int sumb = b.x + b.y;
    return suma < sumb;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        a[0].x = 0;
        a[0].y = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].x >> a[i].y;
        }
        sort(a, a + n + 1, cmp);
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i].x < a[i - 1].x || a[i].y < a[i - 1].y)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++)
            {
                int cnt = a[i].x - a[i - 1].x;
                while (cnt--)
                {
                    cout << "R";
                }
                cnt = a[i].y - a[i - 1].y;
                while (cnt--)
                {
                    cout << "U";
                }
            }
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}