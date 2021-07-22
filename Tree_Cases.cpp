#include <bits/stdc++.h>
using namespace std;

// function used for i/o in sublime text
void input() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
	freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


vector<array<int, 3>> generate_tree(int nodes, int MAX_CHILD, int MAX_WEIGHT) {
	vector<int> val(nodes, 1);	// value of nodes starting from 1

	for (int i = 0; i < nodes; i++)
		val[i] += i;

	// uncommment this to shuffle val array
	// {
	// 	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// 	auto begin = val.begin();
	// 	shuffle(++begin, val.end(), default_random_engine(seed));
	// }

	int ind = 0;		// index of edges vector
	vector<array<int, 3>> edges(nodes - 1);

	int node = val[0];
	int index = 1;	// index of val vector

	queue<int> que;
	que.push(val[0]);

	while (index < nodes) {
		int par = que.front();
		que.pop();

		int child = rand() % (MAX_CHILD + 1);
		if (que.empty() and !child)
			child = 1;
		child = min(child, nodes - index);

		while (child--) {
			que.push(val[index]);
			edges[ind++] = {par, val[index++], 1 + rand() % MAX_WEIGHT};
		}
	}

	// sort(edges.begin(), edges.end());	// can be used if shuffling of val is done

	return edges;
}


int main() {
	input();
	ios_base::sync_with_stdio(false);
	srand(time(0));

	const int MAX_NODES = 15;
	const int MAX_CHILD = 2;
	const int MAX_WEIGHT = 100;

	const int MAX_CASES = 1;
	const bool IS_WEIGHTED = 0;

	int test_cases;
	test_cases = 1 + rand() % MAX_CASES;
	// cout << test_cases << "\n";

	while (test_cases--) {
		int nodes = 1 + rand() % MAX_NODES;
		auto tree = generate_tree(nodes, MAX_CHILD, MAX_WEIGHT);

		cout << nodes << "\n";
		for (auto edge : tree) {
			cout << edge[0] << " " << edge[1];
			if (IS_WEIGHTED) cout << " " << edge[2];
			cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}