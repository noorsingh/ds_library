#include <bits/stdc++.h>
using namespace std;

// function used for i/o in sublime text
void input() {
#ifndef ONLINE_JUDGE
    freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
    freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


void count_sort(vector<int> &suf, vector<int> &rank, int rank_max) {
    int n = suf.size();
    vector<int> cnt(rank_max);

    for (int i : rank)
        cnt[i]++;
    for (int i = 1; i < rank_max; i++)
        cnt[i] += cnt[i - 1];

    vector<int> suf_new(n);
    for (int i = n - 1; i >= 0; i--) {
        int &position = cnt[rank[suf[i]]];
        suf_new[position - 1] = suf[i];
        position--;
    }
    suf = suf_new;
}


void suffix_array(string &str, vector<int> &suf, vector<int> &rank) {
    int n = str.size();
    vector<pair<char, int >> a(n);

    // initial: single character sort
    for (int i = 0; i < n; i++)
        a[i] = {str[i], i};

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
        suf[i] = a[i].second;       // initial sorting

    rank[suf[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first == a[i - 1].first)
            rank[suf[i]] = rank[suf[i - 1]];
        else
            rank[suf[i]] = rank[suf[i - 1]] + 1;
    }
    int rank_max = rank[suf[n - 1]] + 1;    // denotes how many different ranks(suffixes) have been found


    // pairwise(radix  sort)
    int len = 1;            // length of substrings to be sorted
    while (len < n and rank_max < n) {
        for (int i = 0; i < n; i++)
            suf[i] = (suf[i] - len + n) % n;    // expanding len(doubling), moving index backwards(for radix sort) by len units

        count_sort(suf, rank, rank_max);

        vector<int> rank_new(n);
        rank_new[suf[0]] = 0;

        pair<int, int> prev = {rank[suf[0]], rank[(suf[0] + len) % n]};

        for (int i = 1; i < n; i++) {
            pair<int, int> curr = {rank[suf[i]], rank[(suf[i] + len) % n]};
            if (prev == curr)
                rank_new[suf[i]] = rank_new[suf[i - 1]];
            else
                rank_new[suf[i]] = rank_new[suf[i - 1]] + 1;
            prev = curr;
        }

        rank = rank_new;
        rank_max = rank[suf[n - 1]] + 1;
        len <<= 1;
    }

    // for (int i = 0; i < n; i++)
    //     cout << pos[i] + 1 << ' ' << suf[i] + 1 << " \t" << str.substr(suf[i], n - suf[i]) << '\n';
    // cout << "\n";
    // for (int i = 1; i < n; i++)
    //     cout << pos[suf[i]] << ' ' << pos[i] << ' ' << suf[i] << '\t' << str.substr(suf[i], n - suf[i] - 1) << '\n';
    // cout << "\n";
}


// Longest Common Prefix
// lcp[i] contains lcp of suffix with i'th index and (it's pervious suffix in suffix array)
// i.e two adjacent suuffixes of suffix array

// lcp of any i,j of original string is :
// min of lcp[k], where k varies rank[i]+1 to rank[j]
// and rank[i] < rank[j]
// We can calculate this range query using SegTree or SparseTable
void lcprefix(string &str, vector<int> &suf, vector<int> &rank, vector<int> &lcp) {
    int n = str.size();
    int k = 0;

    for (int j = 0; j < n - 1; j++) {
        int i = suf[rank[j] - 1];     // index of previos suffix(of suffix array) in original string
        // i'th and j'th index suffixes(strings of original string) are adjacent in suffix array

        // lcp[i] = lcp(s[i...n-1], s[j...n-1])
        while (str[j + k] == str[i + k])
            k++;

        lcp[rank[j]] = k;
        k--;
        if (k < 0) k = 0;
    }

    // n--;
    // for (int i = 1; i <= n; i++)
    //     cout << lcp[i] << ' ' << p[i] << " \t" << s.substr(p[i], n - p[i]) << '\n';
}


int main() {
    input();
    ios_base::sync_with_stdio(false); cin.tie(0);

    string str;
    cin >> str;
    str += '$';

    int n = str.size();
    vector<int> suf(n), rank(n);

    // Suffix Array denotes suffixes in sorted order
    // i'th suffix(in suffix array) starts from suf[i] index of original string
    // Suffix starting at i'th index has rank(kind of rankition) rank[i] in suffix array

    suffix_array(str, suf, rank);  // can be used to find substring, lcp of suffixes, sorted suffixes

    vector<int> lcp(n);
    lcprefix(str, suf, rank, lcp);

    return 0;
}

// ababba