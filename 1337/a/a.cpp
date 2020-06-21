#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long e, f, g;
        e = b;
        g = c;
        f = max(c - b + 1, b);
        if (f >= c)
            f = c;
        cout << e << " " << f << " " << g << endl;
    }
    return 0;
}