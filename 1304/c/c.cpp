#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct temp
{
    ll t, l, h;
} a[110];

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        ll n, m;
        cin >> n >> m;
        a[0].t = 0;
        a[0].l = m;
        a[0].h = m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].t >> a[i].l >> a[i].h;
        }
        ll rl = a[n].l;
        ll rh = a[n].h;
        int flag = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            rl = max(rl - (a[i + 1].t - a[i].t), a[i].l);
            rh = min(rh + (a[i + 1].t - a[i].t), a[i].h);
            if (rl > a[i].h || rh < a[i].l || rh < rl)
            {
                flag = 1;
                cout << "NO" << endl;
                break;
            }
        }
        if (flag == 1)
            continue;
        cout << "YES" << endl;
    }
    return 0;
}