#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n + 10];
        ll b[n + 10];
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 2; i < n; i++)
        {
            b[i] = b[i - 1];
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                // cout << i << endl;
                b[i]++;
            }
        }
        b[n] = b[n - 1];
        ll ans = 0, ansi = 0;
        for (int i = k; i <= n; i++)
        {
            if (b[i] - b[i - 1] == 0 && b[i - k + 1] - b[i - k] == 0)
            {
                if (b[i] - b[i - k] > ans)
                {
                    ans = b[i] - b[i - k];
                    ansi = i - k;
                }
            }
            else if (b[i] - b[i - 1] == 1 && b[i - k + 1] - b[i - k] == 1)
            {
                if (b[i] - b[i - k] - 2 > ans)
                {
                    ans = b[i] - b[i - k] - 2;
                    ansi = i - k;
                }
            }
            else
            {
                if (b[i] - b[i - k] - 1 > ans)
                {
                    ans = b[i] - b[i - k] - 1;
                    ansi = i - k;
                }
            }
            // cout << b[i] - b[i - k] << endl;
        }
        cout << ans + 1 << " " << ansi + 1 << endl;
    }
    return 0;
}