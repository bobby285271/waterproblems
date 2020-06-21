#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        long long x;
        long long ans = 0;
        cin >> x;
        while (x != 0)
        {
            int temp = x % 10;
            ans += x - temp;
            x = temp + (x - temp) / 10;
            if (x < 10)
            {
                ans += x;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}