#include<bits/stdc++.h>
using namespace std;

// function used for i/o in sublime text
void input() {
#ifndef ONLINE_JUDGE
    freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
    freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


const int max_size = 1e2;
const int max_sum = 1e3;

vector<int> arr;
vector<vector<int>> dpr;
vector<vector<bool>> dpi;

bool is_dp_sum_recur(int n, int sum)
{
    if (!sum)
        return 1;
    if (n < 0 or sum < 0)
        return 0;
    if (dpr[n][sum] != -1)
        return dpr[n][sum];

    return dpr[n][sum] = is_dp_sum_recur(n - 1, sum) or is_dp_sum_recur(n - 1, sum - arr[n]);
}

bool is_dp_sum_iter(int n, int sum) {
    for (int i = 0; i <= n; i++)
        dpi[i][0] = true;

    for (int i = 1; i <= sum; i++)
        dpi[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1])
                dpi[i][j] = dpi[i - 1][j];
            else
                dpi[i][j] = dpi[i - 1][j] or dpi[i - 1][j - arr[i - 1]];
        }
    }

    return dpi[n][sum];
}

int main() {
    input();
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, sum;
    n = 6, sum = 9;
    // cin >> n >> sum;

    arr.resize(n);
    dpi.resize(n + 1, vector<bool>(sum + 1));
    dpr.assign(n + 1, vector<int>(sum + 1, -1));

    arr = {3, 34, 4, 12, 5, 6};
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    cout << sum << " sum present: ";
    if (is_dp_sum_recur(n - 1, sum))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

