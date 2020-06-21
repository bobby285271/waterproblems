#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b;
        cin >> a >> b;
        long long bn = 0, temp = b;
        while (temp != 0)
        {
            temp /= 10;
            bn++;
        }
        bn--;
        if (pow(10, bn + 1) == b + 1)
            cout << a * (bn + 1) << endl;
        else
            cout << a * bn << endl;
    }
    return 0;
}