#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string a;
        cin >> a;
        int p = k;
        int cnt[p + 10][30];
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < p / 2; j++)
        {
            for (int i = 0; j + i < n; i += p)
            {
                // cout << j + i << endl;
                cnt[j][a[j + i] - 'a']++;
                cnt[j][a[p - 1 - j + i] - 'a']++;
            }
        }
        if (p % 2 != 0)
            for (int i = p / 2; i < n; i += p)
            {
                // cout << a[i] << " ";
                cnt[p / 2][a[i] - 'a']++;
            }

        // for (int i = 0; i < p / 2 + 1; i++)
        // {
        //     for (int j = 0; j < 26; j++)
        //     {
        //         cout << cnt[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        long long ans = 0;
        if (p % 2 == 0)
        {
            for (int i = 0; i < p / 2; i++)
            {
                int maxn = 0, sum = cnt[i][0];
                for (int j = 1; j < 26; j++)
                {
                    if (cnt[i][j] > cnt[i][maxn])
                        maxn = j;
                    sum += cnt[i][j];
                }
                // cout << sum << endl;
                sum -= cnt[i][maxn];
                // cout << maxn << endl;
                ans += sum;
                // cout << ans << endl;
            }
        }
        if (p % 2 != 0)
        {
            for (int i = 0; i < p / 2 + 1; i++)
            {
                int maxn = 0, sum = cnt[i][0];
                for (int j = 1; j < 26; j++)
                {
                    if (cnt[i][j] > cnt[i][maxn])
                        maxn = j;
                    sum += cnt[i][j];
                }
                sum -= cnt[i][maxn];
                // cout << sum << endl;
                ans += sum;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}