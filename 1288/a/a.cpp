#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        int x = sqrt(b);
        int flag = 0;
        for (int i = max(0, x - 100); i < x + 100; i++)
        {
            if (i + ceil(b * 1.0 / (i + 1)) <= a)
            {
                cout << "YES" << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "NO" << endl;
    }
    return 0;
}