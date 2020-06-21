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
        string a;
        cin >> a;
        int flag = 0;
        int l1, l2;
        for (int i = 0; i < n; i++)
        {
            if ((a[i] - '0') % 2 != 0 && flag == 0)
            {
                flag = 1;
                l1 = i;
            }
            else if ((a[i] - '0') % 2 != 0 && flag == 1)
            {
                flag = 2;
                l2 = i;
                break;
            }
        }
        if (flag == 2)
            cout << a[l1] << a[l2] << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}