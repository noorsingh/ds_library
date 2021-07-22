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


node* buildTree(string str) {
    vector<string> arr;
    istringstream iss(str);
    while (iss >> str)
        arr.push_back(str);

    int size = arr.size();

    node* root = new node(stoi(arr[0]));
    queue<node*> q;
    q.push(root);
    int index = 1;

    while (index < size) {
        node* currnode = q.front();
        q.pop();

        string currVal = arr[index++];
        if (currVal != "N") {
            currnode->left = new node(stoi(currVal));
            q.push(currnode->left);
        }

        if (index >= arr.size())
            break;

        currVal = arr[index++];
        if (currVal != "N") {
            currnode->right = new node(stoi(currVal));
            q.push(currnode->right);
        }
    }

    return root;
}


void inorder(node* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


int main() {
    input();

    string tree;
    getline(cin, tree);

    node* root = buildTree(tree);
    inorder(root);

    return 0;
}

// 1 2 3 N N N 4 5 N 6 7 N 8 9 N N N 10 N