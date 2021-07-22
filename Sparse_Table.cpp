#include <bits/stdc++.h>
using namespace std;

// function used for i/o in sublime text
void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


// Sparse Table
struct sp_table {
    vector<vector<int>>table;

    void build(vector<int> &a) {
        int cols = a.size();
        int rows = log2(cols);
        table.assign(rows, vector<int> (cols));

        for (int i = 0; i < cols; i++)
            table[0][i] = a[i];

        int len = 1;    // length of range: 2^row(calculated by two 2^(r-1) ranges of previous row)
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j + (1 << i) <= cols; j++)
                table[i][j] = merge(table[i - 1][j], table[i - 1][j + len]);
            len <<= 1;
        }
    }

    // Query only for function which can be combined for diff lens in O(1)
    int merge(int a, int b) {
        return min(a, b);
    }

    // returns Query [l,r]
    int get(int l, int r) {
        int i = log2(r - l + 1);
        return merge(table[i][l], table[i][r - (1 << i) + 1]);
    }
};


int main() {
    input();
    ios_base::sync_with_stdio(false); cin.tie(0);

    vector<int> a({1, 2, 3, 4, 5});
    sp_table sp;
    sp.build(a);

    cout << sp.get(1, 3);

    return 0;
}