#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a, b;
    long long cnt = 0;
    for (long long i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        if (temp == 1)
            cnt++;
        if (temp != 1 || i == n - 1)
        {
            a.push_back(cnt);
            cnt = 0;
        }
    }
    cnt = 0;
    for (long long i = 0; i < m; i++)
    {
        long long temp;
        cin >> temp;
        if (temp == 1)
            cnt++;
        if (temp != 1 || i == m - 1)
        {
            b.push_back(cnt);
            cnt = 0;
        }
    }

    long long ans = 0;
    for (int i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            long long cnt1 = 0, cnt2 = 0;
            long long l = i, r = k / i;
            for (int j = 0; j < a.size(); j++)
            {
                if (a[j] >= l)
                {
                    cnt1 += a[j] - l + 1;
                }
            }
            for (int j = 0; j < b.size(); j++)
            {
                if (b[j] >= r)
                {
                    cnt2 += b[j] - r + 1;
                }
            }
            ans += cnt1 * cnt2;
            cnt1 = 0, cnt2 = 0;
            if (l != r)
            {
                for (int j = 0; j < a.size(); j++)
                {
                    if (a[j] >= r)
                    {
                        cnt1 += a[j] - r + 1;
                    }
                }
                for (int j = 0; j < b.size(); j++)
                {
                    if (b[j] >= l)
                    {
                        cnt2 += b[j] - l + 1;
                    }
                }
                ans += cnt1 * cnt2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}