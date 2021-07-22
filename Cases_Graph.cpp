#include <bits/stdc++.h>
using namespace std;

// function used for i/o in sublime text
void input() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
	freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


vector<array<int, 3>> generate_graph(bool IS_DIRECTED, bool IS_CONNECTED, int BASE, int nodes, int MAX_WEIGHT) {
	int MIN_EDGES = nodes - 1;
	int MAX_EDGES = (nodes * (nodes - 1));

	if (!IS_DIRECTED) MAX_EDGES /= 2;
	int edges_count = MIN_EDGES + rand() % (MAX_EDGES - MIN_EDGES + 1);

	vector<array<int, 3>> edges(edges_count);		// final selected edges
	vector<array<int, 3>> possible_edges(MAX_EDGES);	// possible edges
	set<pair<int, int>> present;					// already included edges

	// List of all unique possible edges except self edge
	for (int i = BASE, ind = 0; i < BASE + nodes; i++)
		for (int j = (IS_DIRECTED) ? BASE : i + 1; j < BASE + nodes; j++)
			if (i != j) possible_edges[ind++] = {i, j, 1 + rand() % MAX_WEIGHT};

	unsigned seed = std::chrono::system_clock:: now().time_since_epoch().count();
	shuffle(possible_edges.begin(), possible_edges.end(), default_random_engine(seed));

	int index = edges_count;		// index variable for final selected edges

	// For connected graph, n-1 minimum edges for connecting the graph randomly at first
	if (IS_CONNECTED) {
		int size_connec = 1, size_single = nodes - 1;
		vector<int> single(size_single, BASE);		// to be connected nodes

		vector<int> connec(nodes);					// connected nodes
		connec[0] = BASE + nodes - 1;

		for (int i = 0; i < size_single; i++)
			single[i] += i;

		unsigned seed = 0;
		shuffle(single.begin(), single.end(), default_random_engine(seed));

		for (int i = 1; i < nodes; i++) {
			int x = connec[rand() % size_connec];
			int y = single[--size_single];
			connec[size_connec++] = y;

			if (!IS_DIRECTED and x > y) swap(x, y);
			edges[--index] = {x, y, 1 + rand() % MAX_WEIGHT};
			present.insert({x, y});
		}
	}

	// If connected, select remaining edges randomly from possible edges
	// Else, select all edges randomly from possible edges
	int remaining = (IS_CONNECTED ? edges_count - nodes + 1 : edges_count);
	for (int i = 0; index--; i++) {
		if (IS_CONNECTED)
			while (present.count({possible_edges[i][0], possible_edges[i][1]}))
				i++;
		edges[index] = possible_edges[i];
	}

	sort(edges.begin(), edges.end());
	return edges;
}


// Can also be done by: select a vertex x randomly(or iterate) & select y randomly and join them
// But Eg: n=1000 and edges = n*(n-1) - 10, Then at last, {x,y} will be already existing and it would take very long to complete
int main() {
	input();
	ios_base::sync_with_stdio(false); cin.tie(0);
	srand(time(0));

	int BASE = 1;       // nodes starting from 0 or 1   // 0 or 1   (or even higher)
	int MAX_CASES = 1;
	int MAX_NODES = 10;
	int MAX_WEIGHT = 100;
	bool IS_WEIGHTED = 0;
	bool IS_DIRECTED = 0;
	bool IS_CONNECTED = 1;

	int test_cases;
	test_cases = 1 + rand() % MAX_CASES;
	// cout << test_cases << "\n";

	while (test_cases--) {
		int nodes = 1 + rand() % MAX_NODES;
		auto graph = generate_graph(IS_DIRECTED, IS_CONNECTED, BASE, nodes, MAX_WEIGHT);

		// cout << "Total Nodes: ";
		cout << nodes << "\n";
		// cout << "Total Edges: ";
		cout << graph.size() << "\n";

		for (auto edge : graph) {
			cout << edge[0] << " " << edge[1];
			if (IS_WEIGHTED) cout << " " << edge[2];
			cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}