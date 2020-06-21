#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        string s;
        cin >> n >> x >> s;
        int ans = 0;
        bool flag = 0;
        int cnt0 = count(s.begin(), s.end(), '0');
        int total = cnt0 - (n - cnt0);
        int bal = 0;
        for (int i = 0; i < n; i++)
        {
            if (total == 0)
            {
                if (bal == x)
                    flag = 1;
            }
            else if (abs(x - bal) % abs(total) == 0)
            {
                ans += ((x - bal) / total >= 0);
            }
            bal += (s[i] == '0') * 2 - 1;
        }
        cout << (flag ? -1 : ans) << endl;
    }

    return 0;
}