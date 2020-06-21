#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        string ansa, ansb, ansc;
        int bk1, bk2;
        for (int i = 0; i <= a.size() / 2; i++)
        {
            if (i < a.size() - 1 - i && a[i] == a[a.size() - 1 - i])
                ansa.push_back(a[i]);
            else
            {
                bk1 = i;
                bk2 = a.size() - 1 - i;
                break;
            }
        }
        // cout << bk2 << bk1;
        for (int i = bk2 - bk1 + 1; i >= 1; i--)
        {

            string temp = a.substr(bk1, i);
            // cout << temp << endl;
            string temp1 = temp;
            reverse(temp1.begin(), temp1.end());
            // cout << temp1 << endl;
            if (temp == temp1)
            {
                ansb = temp;
                break;
            }
        }
        for (int i = bk2 - bk1 + 1; i >= 1; i--)
        {
            string temp = a.substr(bk2 - i + 1, i);
            string temp1 = temp;
            reverse(temp1.begin(), temp1.end());
            if (temp == temp1)
            {
                ansc = temp;
                break;
            }
        }
        cout << ansa;
        if (ansb.size() > ansc.size())
            cout << ansb;
        else
            cout << ansc;
        reverse(ansa.begin(), ansa.end());
        cout << ansa;
        cout << endl;
    }

    return 0;
}