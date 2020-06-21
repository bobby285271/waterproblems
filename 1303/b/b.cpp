#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, g, b;
        cin >> n >> g >> b;
        long long nb = n / 2;
        long long ng = n - nb;
        long long ans1 = floor(ng * 1.0 / g);
        long long ans2 = floor(nb * 1.0 / b);
        long long ans = min(ans1, ans2);
        n -= ans;
        ng -= ans * g;
        nb -= ans * b;
        ans *= g + b;
        // cout << ans << " " << ng << " " << nb << endl;
        if (ng <= g)
        {
            ans += ng + nb;
            cout << ans << endl;
        }
        else if (nb <= b)
        {
            //so ng > g
            ans1 = floor(ng * 1.0 / g);
            if (ng % g == 0)
                ans1--;
            ans += ans1 * (g + b);
            ng -= ans1 * g;
            ans += ng;
            cout << ans << endl;
        }
    }

    return 0;
}