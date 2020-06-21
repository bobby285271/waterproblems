#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        int l = a.size();
        int flag = 0;
        for (int i = 0; i < l; i++)
        {
            if (a[i] != c[i] && b[i] != c[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}