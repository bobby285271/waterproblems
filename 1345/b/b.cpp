#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    ll a[100010];
    for (ll i = 1; i <= 100005; i++)
    {
        a[i] = 3 * i * (i + 1) / 2 - i;
    }
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        while (n >= 2)
        {
            ll l = upper_bound(a + 1, a + 100000, n) - a;
            n -= a[l - 1];
            // cout << l << endl;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}