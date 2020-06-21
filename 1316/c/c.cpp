#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m, x, p, fir = -1, sec = -1;
    cin >> n >> m >> p;
    for (long long i = 0; i < n; i++)
    {
        cin >> x;
        if (x % p != 0 && fir == -1)
        {
            fir = i;
        }
    }

    for (long long i = 0; i < m; i++)
    {
        cin >> x;
        if (x % p != 0 && sec == -1)
        {
            sec = i;
        }
    }
    cout << fir + sec << endl;
    return 0;
}