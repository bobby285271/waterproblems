#include <bits/stdc++.h>
using namespace std;

int pref[10000010], c;

string solve(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    c = 0;
    for (int i = 1; i < a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
        cout << ansa;
        if (a.size() > 2 * bk1)
        {
            string s = a.substr(bk1, a.size() - 2 * bk1);
            // cout << s << endl;
            ansb = solve(s);
            reverse(s.begin(), s.end());
            ansc = solve(s);
            if (ansb.size() < ansc.size())
                cout << ansc;
            else
                cout << ansb;
        }
        reverse(ansa.begin(), ansa.end());
        cout << ansa << endl;
    }
    return 0;
}