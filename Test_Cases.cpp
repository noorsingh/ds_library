#include <bits/stdc++.h>
#define int             long long
#define inf             LLONG_MAX
#define ninf            LLONG_MIN
// #define inf          INT_MAX
// #define ninf         INT_MIN
#define pss             ' '
#define ptt             '\t'
#define endl            '\n'
#define endd            cout<<'\n'
#define fpr(i,a,b)      for(auto i=(a); i<(b); i++)
#define fnr(i,a,b)      for(auto i=(a); i>=(b); i--)
#define pb              push_back
#define pf              push_front
#define ppb             pop_back
#define ppf             pop_front
#define in              insert
#define er              erase
#define ff              first
#define ss              second
#define auto(i, a)      for(auto& i : a)
#define iter(i, a)      for(auto i = a.begin(); i!=a.end(); i++)
#define nter(i, a)      for(auto i = a.rbegin(); i!=a.rend(); i++)
#define all(v)          v.begin(),v.end()
#define mset(val,a)     memset(a, val, sizeof(a))
#define aa(n)           array<int, n>
#define bb(n)           bitset<n>
#define pque            priority_queue
#define uom             unordered_map
#define uos             unordered_set
#define vv              vector
#define pi              3.1415926535897932384626433832795

using namespace std;
typedef     long long               lli;
typedef     long double             lld;
typedef     vector<int>             vii;
typedef     vector<vector<int> >    vvi;
typedef     vector<lli>             vll;
typedef     vector<vector<lli> >    vvl;
typedef     pair<int, int>          pii;
typedef     map<int, int>           mii;
typedef     pair<lli, lli>          pll;
typedef     map<lli, lli>           mll;

void input() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
	freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


void testcases() {
	int i, j, t, n, m, maxlen, mod;
	maxlen = 20;
	mod = 1000;
	n = 1 + rand() % maxlen;
	// m = 1 + rand() % maxlen;
	// n = 1;

	// cout << n << endl;
	fpr(i, 0, n) {
		cout << rand() % mod << pss;
	}

	// cout << n << pss << m << endl;
	// fpr(i, 0, n)
	// {
	// fpr(j, 0, m)
	// {
	// cout << rand() % mod << pss;
	// }
	// cout<<endl;
	// }
}


////////////////// Program for self use: Debugging, Stress Testing
signed main() {
	input();
	srand(time(0));
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc = 1;
	// int tc = rand() % 10;
	while (tc--)
		testcases();

	return 0;
}