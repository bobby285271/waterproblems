#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long tempa[n + 10], tempb[n + 10];
    long long a[n + 10], b[n + 10];
    long long pa = 0, pb = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tempa[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tempb[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (tempa[i] - tempb[i] > 0)
        {
            a[pa] = tempa[i] - tempb[i];
            pa++;
        }
        else
        {
            b[pb] = tempa[i] - tempb[i];
            pb++;
        }
    }
    if (pa == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    long long ans = pa * (pa - 1) / 2;
    if (pb == 0)
    {
        cout << ans << endl;
        return 0;
    }
    sort(a, a + pa);
    sort(b, b + pb);
    for (int i = 0; i < pa; i++)
    {
        int l = upper_bound(b, b + pb, -a[i]) - b;
        if (l >= pb)
            l = pb;
        else if (l <= 0)
            l = 0;
        ans += pb - l;
    }
    cout << ans << endl;
    return 0;
}