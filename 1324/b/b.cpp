#include <bits/stdc++.h>
using namespace std;

int c[5100];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(c, -1, sizeof(c));
        int flag = 0;
        for (int i = 0, a; i < n; ++i)
        {
            cin >> a;
            if (c[a] < 0)
                c[a] = i;
            else
            {
                if (c[a] < i - 1)
                    flag = 1;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}