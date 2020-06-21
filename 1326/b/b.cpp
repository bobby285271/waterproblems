#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int b[n + 10];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << b[0] << " ";
    int temp = b[0];
    for (int i = 1; i < n; i++)
    {
        if (b[i] > 0)
        {
            cout << temp + b[i] << " ";
            temp = temp + b[i];
        }
        if (b[i] <= 0)
        {
            cout << temp + b[i] << " ";
        }
    }

    return 0;
}