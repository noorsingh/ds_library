#include <bits/stdc++.h>
using namespace std;

// function used for i/o in sublime text
void input() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
	freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


// Disjoint Set Union
struct Dsu
{
	vector<int> parent, size;

	Dsu(int n)
	{
		size.assign(++n, 1);
		parent.resize(n);
		for (int i = 1; i < n; i++)
			parent[i] = i;
	}

	int get_parent(int a) {
		return parent[a] = (parent[a] == a) ? a : get_parent(parent[a]);
	}

	void merge(int a, int b) {
		a = get_parent(a);
		b = get_parent(b);
		if (a == b) return;

		if (size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
};

int main() {
	input();
	ios_base::sync_with_stdio(false); cin.tie(0);

	Dsu d(100);
	d.merge(1, 2);
	d.merge(3, 4);
	d.merge(1, 4);

	int a = 1, b = 3, c = 5;
	cout << "Parent of " << a << ": " << d.get_parent(a) << "\n";
	cout << "Parent of " << b << ": " << d.get_parent(b) << "\n";
	cout << "Parent of " << c << ": " << d.get_parent(c) << "\n";

	return 0;
}