#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ll a[n + 10];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> b;
        b.clear();
        ll maxn = a[0];
        if (n == 1)
        {
            cout << a[0] << endl;
            continue;
        }

        for (int i = 1; i < n; i++)
        {
            if (a[i] * a[i - 1] < 0)
            {
                b.push_back(maxn);
                maxn = a[i];
            }
            maxn = max(maxn, a[i]);
            if (i == n - 1)
            {
                b.push_back(maxn);
            }
        }
        ll sum = 0;
        for (int i = 0; i < b.size(); i++)
        {
            sum += b[i];
        }
        cout << sum << endl;
    }
    return 0;
}