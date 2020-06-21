#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 10];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}