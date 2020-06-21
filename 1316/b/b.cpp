#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        int n, k = 0;
        cin >> n >> s;
        string ans = s;
        for (int i = 0; i < n; i++)
        {
            string bak = s.substr(i);
            string frn = s.substr(0, i);
            if ((n - i) % 2 != 0)
                reverse(frn.begin(), frn.end());
            bak = bak + frn;
            if (bak < ans)
            {
                ans = bak;
                k = i;
            }
        }
        cout << ans << endl
             << k + 1 << endl;
    }
    return 0;
}