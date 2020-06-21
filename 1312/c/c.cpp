#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n + 10];
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int cnt[70];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 65; j++)
            {
                cnt[j] += a[i] % k;
                a[i] /= k;
            }
        }

        int flag = 0;
        for (int i = 0; i < 65; i++)
        {
            // cout << cnt[i];
            if (cnt[i] != 0 && cnt[i] != 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}