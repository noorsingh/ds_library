#include <bits/stdc++.h>
using namespace std;

// function used for i/o in sublime text
void input() {
#ifndef ONLINE_JUDGE
    freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
    freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


vector<int> prime;

bool isprime(int n) {
    if (prime[n] != -1)
        return prime[n];
    if (n == 2)
        return 1;
    if (n % 2 == 0 || n < 2)
        return 0;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return prime[n] = 0;
    }
    return prime[n] = 1;
}

int main() {
    input();
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n = 100;

    prime.assign(n + 1, -1);
    cout << isprime(97);

    return 0;
}