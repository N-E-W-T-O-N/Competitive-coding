#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll countAns;

void fn(ll a[], ll n, vector<ll> probAns, ll curr_sum, ll b, ll idx)
{
	if (curr_sum == b)
	{
		countAns++;
		cout << "(";
		for (ll i = 0; i < probAns.size() - 1; i++)
		{
			cout << probAns[i] << " ";
		}
		cout << probAns[probAns.size() - 1] << ")";
		return;
	}

	if (curr_sum > b)
	{
		return;
	}

	for (ll i = idx; i < n; i++)
	{
		if (i != idx and a[i] == a[i - 1])
		{
			continue;
		}
		probAns.PB(a[i]);
		fn(a, n, probAns, curr_sum + a[i], b, i + 1);
		probAns.pop_back();
	}
}

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ll b;
	cin >> b;

	vector<ll> probAns;
	sort(a, a + n);
	fn(a, n, probAns, 0, b, 0);
	if (countAns == 0)
	{
		cout << "Empty";
	}

	cout << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--)
	{

		countAns = 0;
		solve();
	}
	return 0;
}