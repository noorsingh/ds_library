#include <bits/stdc++.h>
using namespace std;

// function used for i/o in sublime text
void input()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
	freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


int lower_bound(vector<int> &v, int x)
{
	int lo = 0, hi = v.size();

	while (lo < hi) {
		int mid = lo + ((hi - lo) >> 1);

		if (x <= v[mid]) {		// check on left side
			hi = mid;
		} else {				// check on right side
			lo = mid + 1;
		}
	}

	return lo;
}


int upper_bound(vector<int> &v, int x)
{
	int lo = 0, hi = v.size();

	while (lo < hi) {
		int mid = lo + ((hi - lo) >> 1);

		if (x < v[mid]) {		// check on left side
			hi = mid;
		} else {				// check on right side
			lo = mid + 1;
		}
	}

	return lo;
}


int main()
{
	input();
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<int> v({1, 2, 4, 5, 8, 9});
	int n = v.size();
	int x = 2;

	int lo = lower_bound(v, x);
	int up = upper_bound(v, x);

	cout << "Lower Bound of " << x << " is: " << lo << "\n";
	cout << "Value at lower bound: " << (lo == n ? "Doesn't exist" : to_string(v[lo])) << "\n\n";

	cout << "Upper Bound of " << x << " is: " << up << "\n";
	cout << "Value at upper bound: " << (lo == n ? "Doesn't exist" : to_string(v[up])) << "\n";

	return 0;
}