#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<int, long long> m;
    cin >> n;
    long long ans = -1;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x;
        m[x - i] += x;
    }
    for (map<int, long long>::iterator i = m.begin(); i != m.end(); i++)
    {
        ans = max(ans, i->second);
    }
    cout << ans << endl;
    return 0;
}