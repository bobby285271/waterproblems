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
        if (n % 2 == 0)
        {
            n /= 2;
            while (n--)
            {
                cout << "1";
            }
            cout << endl;
        }
        else
        {
            n -= 3;
            cout << "7";
            n /= 2;
            while (n--)
            {
                cout << "1";
            }
            cout << endl;
        }
    }
    return 0;
}