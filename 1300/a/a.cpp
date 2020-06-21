#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (a[i] == 0)
                flag++;
        }
        if (flag == 0 && sum != 0)
        {
            cout << "0" << endl;
            continue;
        }
        if (sum == 0 && flag == 0)
        {
            cout << "1" << endl;
            continue;
        }
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                a[i]++;
                ans++;
                sum++;
            }
        }
        if (sum == 0)
        {
            ans++;
            cout << ans << endl;
        }
        else
            cout << ans << endl;
    }
    return 0;
}