#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    double ans = 0;
    for (int i = 1; i <= T; i++)
    {
        ans += 1.0 / i;
    }
    cout << ans << endl;
    return 0;
}
