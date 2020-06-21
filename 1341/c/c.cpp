#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

struct temp
{
    int id;
    int val;
} a[100010];

bool cmp(temp a, temp b)
{
    return a.val < b.val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            a[i].id = i;
            cin >> a[i].val;
        }
        sort(a + 1, a + n + 1, cmp);
        ll cnt[n + 10];
        memset(cnt, 0, sizeof(cnt));
        int flag = 0;
        ll maxn = 0;
        for (int i = 1; i <= n; i++)
        {
            if (maxn != cnt[a[i].id - 1])
            {
                flag = 1;
                break;
            }
            cnt[a[i].id] = cnt[a[i].id - 1] + 1;
            int p = a[i].id;
            if (cnt[a[i].id + 1] != 0)
            {
                while (1)
                {
                    p++;
                    if (cnt[p + 1] == 0 || p == n)
                    {
                        cnt[p] += cnt[a[i].id];
                        break;
                    }
                }
            }
            if (p != n)
                maxn = max(maxn, cnt[p]);
            else
            {
                int flag2 = 0;
                maxn = 0;
                while (1)
                {
                    p--;
                    if (cnt[p] == 0)
                    {
                        flag2 = 1;
                    }
                    if (flag2 == 1)
                    {
                        maxn = max(maxn, cnt[p]);
                    }
                    if (p == 0)
                    {
                        // cout << maxn;
                        break;
                    }
                }
            }
            // for (int j = 1; j <= n; j++)
            // {
            //     cout << cnt[j] << " ";
            // }
            // cout << endl;
        }
        if (flag == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}