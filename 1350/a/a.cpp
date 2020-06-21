#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        while (k--)
        {
            if (n % 2 == 0)
            {
                n += 2;
                break;
            }
            else
            {
                int flag = 0;
                for (int i = 2; i * i <= n; i++)
                {
                    // cout << "d" << n << endl;
                    if (n % i == 0)
                    {

                        flag = 1;
                        n += i;
                        break;
                    }
                }
                if (flag == 0)
                {
                    n *= 2;
                    break;
                }
            }
        }
        n += 2 * k;
        cout << n << endl;
    }
}