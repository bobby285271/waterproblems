#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n], b[n], c[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        memset(b, 0, sizeof(b));
        b[i] = a[i];
        long long flag = 0;
        for (long long j = 1;; j++)
        {
            if (i + j < n)
                b[i + j] = min(b[i + j - 1], a[i + j]);
            if (i - j >= 0)
                b[i - j] = min(b[i - j + 1], a[i - j]);

            if ((i + j < n && b[i + j] < 1) || (i - j >= 0 && b[i - j] < 1))
            {
                flag = 1;
                break;
            }
            if (i + j > n && i - j < 0)
            {
                break;
            }
        }

        if (flag == 0)
        {
            long long sum = 0;
            for (long long k = 0; k < n; k++)
            {
                sum += b[k];
            }
            if (sum > ans)
            {
                for (long long k = 0; k < n; k++)
                {
                    c[k] = b[k];
                }
                ans = sum;
            }
        }
    }
    for (long long i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}