#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, s, k;
        cin >> n >> s >> k;
        int a[k + 1];
        memset(a, 0, sizeof(a));
        a[0] = 0;
        a[k + 1] = n + 1;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
        }
        sort(a, a + k + 1);
        for (int i = 0;; i++)
        {        
            
            if ((a[lower_bound(a, a + k + 2, s + i) - a] != s + i && s + i <= n) || (a[lower_bound(a, a + k + 2, s - i) - a] != s - i && s - i > 0))
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
