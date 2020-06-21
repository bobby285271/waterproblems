#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans1 = a / b;
        ans1 *= b;
        if (ans1 < a)
            ans1 += b;
        int ans = ans1 - a;
        cout << ans << endl;
    }
    return 0;
}