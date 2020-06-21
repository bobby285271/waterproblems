#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == '0' && i != 0 && i != a.size() - 1)
            {
                int p1 = i - 1;
                int p2 = i + 1;
                int flag1 = 0;
                int flag2 = 0;
                while (1)
                {
                    if (p1 >= 0 && a[p1] == '1')
                    {
                        flag1 = 1;
                    }
                    if (p2 < a.size() && a[p2] == '1')
                    {
                        flag2 = 1;
                    }
                    p1--;
                    p2++;
                    if (p1 < 0 && p2 > a.size())
                    {
                        break;
                    }
                }
                if (flag1 > 0 && flag2 > 0)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}