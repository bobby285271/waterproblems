#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> a;

int solve(vector<int> &c, int loc);

int main()
{
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < a.size(); i++)
	{
		cin >> a[i];
	}
	cout << solve(a, 30) << endl;
}

int solve(vector<int> &c, int loc)
{
	if (a.size() == 0 || loc < 0)
		return 0;
	vector<int> l, r;
	for (int i = 0; i < c.size(); i++)
	{
		if ((c[i] >> loc) % 2 == 0)
			l.push_back(c[i]);
		else
			r.push_back(c[i]);
	}

	if (l.size() == 0)
		return solve(r, loc - 1);
	if (r.size() == 0)
		return solve(l, loc - 1);
	return min(solve(l, loc - 1), solve(r, loc - 1)) + (1 << loc);
}