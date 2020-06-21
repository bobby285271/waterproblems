#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n + 100], b[n + 100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    long long cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 && b[i] == 0)
            cnt1++;
        else if (a[i] == 0 && b[i] == 1)
            cnt2++;
    }
    if (cnt1 == 0)
        cout << "-1" << endl;
    else
        cout << cnt2 / cnt1 + 1 << endl;
    return 0;
}