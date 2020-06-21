#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")

using namespace std;

int main()
{
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n + 10];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n > m + 20)
    {
        cout << "0" << endl;
        return 0;
    }
    sort(a, a + n);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans *= (a[j] - a[i]) % m;
            ans %= m;
            if (!ans)
            {
                cout << "0" << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
