#include <bits/stdc++.h>

using namespace std;

long long a[100010];

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        long long ans = (1 + n) * n / 2;
        long long res = n - m;
        if (res >= m + 1)
        {
            if (res % (m + 1) == 0)
            {
                long long zone = res / (m + 1);
                ans -= (1 + zone) * zone / 2 * (m + 1);
            }
            else
            {
                long long zone = res / (m + 1);
                res -= zone * (m + 1);
                ans -= (2 + zone) * (zone + 1) / 2 * res;
                ans -= (1 + zone) * zone / 2 * (m + 1 - res);
            }
            cout << ans << endl;
        }
        else
        {
            cout << ans - res << endl;
        }
    }
    return 0;
}