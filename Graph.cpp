#include <bits/stdc++.h>
using namespace std;

void input() {
#ifndef ONLINE_JUDGE
    freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
    freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


struct Graph
{
    int nodes, edges;
    vector<int> parent;         // can be used for Directed Graphs
    vector<vector<int>> adj;    // adjacency list

    Graph(bool IS_DIRECTED , int n, int e) {
        nodes = n;
        edges = e;

        // parent.assign(nodes + 1, -1);
        adj.resize(nodes + 1);

        for (int i = 0; i < edges; i++) {
            int x, y;
            cin >> x >> y;

            // parent[y] = x;
            adj[x].push_back(y);
            if (!IS_DIRECTED)
                adj[y].push_back(x);
        }
    }
};

int main() {
    input();
    ios_base::sync_with_stdio(false); cin.tie(0);

    int nodes, edges;
    cin >> nodes >> edges;

    bool IS_DIRECTED = 0;

    Graph g(IS_DIRECTED , nodes, edges);
    for (int &i : g.adj[3]) cout << i << " ";

    return 0;
}

/*
8 6
1 2
2 3
2 4
3 5
3 6
1 7
*/