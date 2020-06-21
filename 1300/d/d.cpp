#include <bits/stdc++.h>
using namespace std;

int a[100020];
int b[100020];

int main()
{
    int n;
    cin >> n;
    if (n % 2 != 0)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    a[n] = a[0];
    b[n] = a[0];
    int p1 = 0, p2 = n / 2;
    int flag = 0;
    while (1)
    {
        if (a[p1] - a[p1 + 1] != a[p2 + 1] - a[p2])
        {
            flag = 1;
            break;
        }
        if (b[p1] - b[p1 + 1] != b[p2 + 1] - b[p2])
        {
            flag = 1;
            break;
        }
        p1++;
        p2++;
        if (p2 + 1 == n)
        {
            break;
        }
    }
    if (flag == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}