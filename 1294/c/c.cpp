#include <bits/stdc++.h>
     
    using namespace std;
     
    long long a[100000], b[100000];
     
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int T;
        cin >> T;
        while (T--)
        {
            long long n;
            cin >> n;
            long long saven = n;
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            b[0] = 1;
            int preflag = 0;
            int lena = 0;
            for (long long i = 2;i*i<=n; i++)
            {
                while (n % i == 0)
                {
                    a[lena] = i;
                    b[lena + 1] = b[lena] * i;
                    n = n / i;
                    lena++;
                    if (lena >= 2)
                    {
                        long long suma, sumb;
                        long long sumtemp = saven / n;
                        for (int k = 0; k < lena; k++)
                        {
                            suma = b[k + 1];
                            sumb = sumtemp / suma;
                            if (sumb == 1)
                                break;
                            long long sumc = saven / suma / sumb;
                            if (sumc == 1)
                                break;
                            if (suma != sumb && sumb != sumc && suma != sumc)
                            {
                                cout << "YES" << endl;
                                cout << suma << " " << sumb << " " << saven / suma / sumb << endl;
                                preflag = 1;
                                break;
                            }
                        }
                    }
                    if (preflag == 1)
                        break;
                }
                if (n == 1 || preflag == 1)
                    break;
            }
            if (preflag == 1)
                continue;
            cout << "NO" << endl;
        }
     
        return 0;
    }