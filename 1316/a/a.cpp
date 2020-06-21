#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n + 10];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i != 0)
                sum += a[i];
        }
        if (n == 1)
        {
            cout << a[0] << endl;
            continue;
        }
        if (sum > m - a[0])
        {
            cout << m << endl;
        }
        else
        {
            cout << a[0] + sum << endl;
        }
    }
    return 0;
}