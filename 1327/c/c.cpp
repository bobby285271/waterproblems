#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int sx[k + 10], sy[k + 10], fx[k + 10], fy[k + 10];
    for (int i = 0; i < k; i++)
    {
        cin >> sx[i] >> sy[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> fx[i] >> fy[i];
    }
    if (n == 1 && m == 1)
    {
        cout << "1" << endl
             << "R" << endl;
        return 0;
    }

    if (n + m - 3 <= m * n && n + m + m * n - 3 > 0)
    {
        cout << n + m + m * n - 3 << endl;
        for (int i = 1; i < m; i++)
        {
            cout << "L";
        }

        for (int i = 1; i < n; i++)
        {
            cout << "U";
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (i % 2 == 0)
                    cout << "R";
                else
                    cout << "L";
            }
            if (i != n - 1)
                cout << "D";
        }
    }
    cout << endl;
    return 0;
}