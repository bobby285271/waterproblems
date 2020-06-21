#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        int last = -1;
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 'R')
            {
                ans = max(ans, i - last);
                last = i;
            }
        }
        int temp = a.size() - last;
        ans = max(ans, temp);
        cout << ans << endl;
    }
    return 0;
}