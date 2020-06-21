#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if (k >= m)
            k = m - 1;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i <= k; i++)
        {
            int temp = 1000000001;
            for (int j = 0; j <= m - 1 - k; j++)
            {
                int sec = max(a[1 + i + j], a[n - m + i + j + 1]);
                temp = min(temp, sec);
                // cout << temp << endl;
            }
            ans = max(ans, temp);
        }
        cout << ans << endl;
    }
    return 0;
}