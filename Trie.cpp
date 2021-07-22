#include <bits/stdc++.h>
using namespace std;

// function used for i/o in sublime text
void input() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
	freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


const int arr_size = 26;	// Use bigger size if string has both small & capital(or even more characters)
const char ref_char = 'a';	// If letters are in small or Capital case

struct trienode {
	struct trienode *arr[arr_size];
	bool isEndOfWord;
};


struct Trie {
	trienode* root;

	Trie() {
		root = getnode();
	}

	trienode* getnode() {
		trienode* new_node = new trienode;
		new_node -> isEndOfWord = false;
		memset(new_node->arr, 0, sizeof(new_node->arr));
		return new_node;
	}

	void insert(string str) {
		trienode* temp = root;	// temp is trienode for i'th character(i.e at i'th level)

		for (char &ch : str) {
			int index = ch - ref_char;		// index of array for i'th character

			if (!(temp -> arr[index]))
				temp -> arr[index] = getnode();

			temp = temp -> arr[index];
		}

		temp -> isEndOfWord = true;
	}

	bool search(string str) {
		trienode* temp = root;

		for (char &ch : str) {
			int index = ch - ref_char;

			if (!temp -> arr[index])
				return false;

			temp = temp -> arr[index];
		}

		return temp -> isEndOfWord;
	}
};


int main() {
	input();
	ios_base::sync_with_stdio(false); cin.tie(0);

	Trie tr;
	tr.insert("abc");
	cout << (tr.search("ab") ? "Yes\n" : "No\n");
	cout << (tr.search("abb") ? "Yes\n" : "No\n");
	cout << (tr.search("abc") ? "Yes\n" : "No\n");

	return 0;
}