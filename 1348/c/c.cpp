#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll n, k;
        string a;
        cin >> n >> k >> a;
        sort(a.begin(), a.end());
        if (k == 1)
        {
            cout << a << endl;
            continue;
        }
        int mark = 0;
        for (int i = k - 1; i >= 0; i--)
        {
            if (a[i] != a[k - 1])
            {
                mark = i + 1;
                break;
            }
        }
        if (mark != 0)
        {
            cout << a[k - 1] << endl;
            continue;
        }
        cout << a[k - 1];
        // int cnt = 1;
        // for (int i = k + 1; i < n; i++)
        // {
        //     if (a[i] == a[i - 1])
        //     {
        //         cnt++;
        //     }
        //     else
        //     {
        //         int temp = cnt / k;
        //         if (cnt % k != 0)
        //             temp++;
        //         while (temp--)
        //         {
        //             cout << a[i - 1];
        //         }
        //         cnt = 1;
        //     }
        //     if (i == n - 1)
        //     {
        //         int temp = cnt / k;
        //         if (cnt % k != 0)
        //             temp++;
        //         while (temp--)
        //         {
        //             cout << a[n - 1];
        //         }
        //         cnt = 1;
        //     }
        // }
        // cout << endl;
        int type = 0;
        for (int i = k + 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
                type++;
        }
        if (type == 0)
        {
            int cnt1 = (n - k) / k;
            if ((n - k) % k != 0)
                cnt1++;
            for (int i = 0; i < cnt1; i++)
            {
                cout << a[k];
            }
            cout << endl;
            continue;
        }
        cout << a.substr(k) << endl;
    }
    return 0;
}