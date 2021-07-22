#include <bits/stdc++.h>
using namespace std;

// function used for i/o in sublime text
void input() {
#ifndef ONLINE_JUDGE
    freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
    freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


struct node {
    int val;
    node* left;
    node* right;

    node(int x) {
        val = x;
        left = right = nullptr;
    }
};


struct Tree {
    int nodes, edges;
    node* root;
    vector<int> par;            // parent
    vector<node*> addr;     // address
    vector<vector<int>> adj;    // adjacency list

    void build(int n, int e) {
        nodes = n ;
        edges = e;

        // par.assign(n + 1, -1);
        addr.assign(nodes + 1, nullptr);
        adj.resize(nodes + 1);

        for (int i = 0; i < edges; i++) {
            int x, y;
            cin >> x >> y;
            // Assumption: x is the Parent of y

            adj[x].push_back(y);

            if (!addr[x]) addr[x] = new node(x);
            if (!addr[y]) addr[y] = new node(y);

            // par[y] = x;
            if (addr[x]->left) addr[x]->right = addr[y];
            else addr[x]->left = addr[y];
        }

        root = addr[1];     // Assuming value of root as 1
    }

    void inorder() {
        in_order(root);
        cout << endl;
    }

    void in_order(node* temp) {
        if (!temp)
            return;
        in_order(temp->left);
        cout << temp->val << " ";
        in_order(temp->right);
    }

    int levelorder() {  // do traversal, and returns no. of levels
        if (!root)
            return 0;

        int lev = 1;
        queue<node*> que;
        que.push(root);
        que.push(nullptr);
        node* temp;

        while (1) {
            temp = que.front();
            que.pop();

            if (temp == nullptr) {
                if (que.empty()) {
                    cout << "\n";
                    return lev;
                }
                lev++;
                que.push(nullptr);
            }
            else {
                cout << temp->val << " ";
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
            }
        }

        return 0;
    }

    node* findnode(int val) {
        // if (val > nodes) return nullptr;
        // return addr[val];
        return find_node(val, root);
    }

    node* find_node(int val, node* temp) {
        if (!temp)
            return nullptr;
        if (temp->val == val)
            return temp;

        node* left = find_node(val, temp->left);
        if (left)
            return left;
        return find_node(val, temp->right);
    }
};


int main() {
    input();
    ios_base::sync_with_stdio(false); cin.tie(0);

    int nodes, edges;
    cin >> nodes >> edges;

    Tree tr;
    tr.build(nodes, edges);

    tr.inorder();
    int levels = tr.levelorder();
    auto res = tr.findnode(3);
    // cout << res->right->val;

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
