#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long a[5], n, temp1;
        cin >> a[0] >> a[1] >> a[2] >> n;
        sort(a, a + 3);
        //cout << n - (a[2] - a[0]) - (a[2] - a[1]) << endl;
        if (n - (a[2] - a[0]) - (a[2] - a[1]) >= 0 && (n - (a[2] - a[0]) - (a[2] - a[1])) % 3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}