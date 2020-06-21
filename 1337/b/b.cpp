#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, n, m;
        cin >> x >> n >> m;
        while (x >= 19 && n > 0)
        {
            x = x / 2 + 10;
            n--;
        }
        while (m > 0)
        {
            x = x - 10;
            m--;
        }
        if (x > 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}