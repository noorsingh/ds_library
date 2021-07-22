#include <bits/stdc++.h>
using namespace std;

// function used for i/o in sublime text
void input() {
#ifndef ONLINE_JUDGE
    freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
    freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


// Segment Tree
struct segtree {
    int size;
    int neutral;        // identity value. Eg: 0 for add, 1 for multiply, inf for minimum
    vector<int> tree;

    void build(vector<int> &a, int neut) {
        size = 1;
        neutral = neut;
        int n = a.size();
        while (size < n) size *= 2;

        // tree.resize(2*size);
        tree.assign(2 * size, neutral);

        build_helper(a, 0, 0, size - 1);
    }


    // r is included
    void build_helper(vector<int> &a, int x, int l, int r) {
        if (l == r) {
            if (l < a.size())
                tree[x] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build_helper(a, 2 * x + 1, l, mid);
        build_helper(a, 2 * x + 2, mid + 1, r);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }


    int merge(int a, int b) {       // Defines which query to apply
        return a + b;               // Here range query is SUM
    }


    void set(int ind, int val) {    // set a[ind] = val
        set_helper(ind, val, 0, 0, size - 1);
    }


    void set_helper(int ind, int val, int x, int l, int r) {
        if (l == r) {
            tree[x] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (ind <= mid)
            set_helper(ind, val, 2 * x + 1, l, mid);
        else
            set_helper(ind, val, 2 * x + 2, mid + 1, r);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }


    int get(int lx, int rx) {       // Range Query a[lx, rx]
        return get_helper(0, 0, size - 1, lx, rx);
    }


    int get_helper(int x, int l, int r, int lx, int rx) {
        if (lx > r or rx < l) return neutral;
        if (lx <= l and rx >= r) return tree[x];

        int mid = (l + r) / 2;
        int a = get_helper(2 * x + 1, l, mid, lx, rx);
        int b = get_helper(2 * x + 2, mid + 1, r, lx, rx);

        return merge(a, b);
    }
};


int main() {
    input();
    ios_base::sync_with_stdio(false); cin.tie(0);

    vector<int> a{1, 2, 3, 4, 5};
    segtree st;
    st.build(a, 0);

    cout << st.get(1, 3);

    return 0;
}