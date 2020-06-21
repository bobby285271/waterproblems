#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    if (n % 2 != 0)
    {
        cout << "-1" << endl;
        return 0;
    }

    int cnt[n + 10];
    cnt[0] = 0;
    int last0 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '(')
            cnt[i + 1] = cnt[i] + 1;
        if (a[i] == ')')
            cnt[i + 1] = cnt[i] - 1;
        if (cnt[i + 1] == 0 && cnt[i] == -1)
        {
            ans += i + 1 - last0;
        }
        if (cnt[i + 1] == 0)
            last0 = i + 1;
    }

    if (last0 != n)
        cout << "-1" << endl;
    else
        cout << ans << endl;
    return 0;
}