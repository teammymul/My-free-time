#include <bits/stdc++.h>
using namespace std;

struct BinTree {
    int value;
    BinTree *left, *right;
};

BinTree* createNode(int value) {
    BinTree* newNode = new BinTree;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void build(BinTree *&node, int value) {
    if (node == nullptr) {
        node = createNode(value);
        return;
    }
    if (value < node->value) {
        build(node->left, value);
    } else {
        build(node->right, value);
    }
}

void inorder(BinTree* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

void preorder(BinTree* node) {
    if (node == nullptr) return;
    cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(BinTree* node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";
}

void bfs(BinTree *root) {
    if (root == nullptr) return;
    queue<pair<BinTree*, int>> q;
    q.push({root, 0});
    int currentLevel = -1;
    while (!q.empty()) {
        auto [node, level] = q.front(); q.pop();
        if (level != currentLevel) {
            if (currentLevel != -1) cout << endl;
            cout << level << ":";
            currentLevel = level;
        }   
        cout << node->value << " ";
        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }
    cout << endl;
}

void findleavenode(BinTree* node) {
    if (node == nullptr) return;
    if (node->left == nullptr && node->right == nullptr) {
        cout << node->value << " ";
        return;
    }
    findleavenode(node->left);
    findleavenode(node->right);
}

int main() {
    BinTree *root = nullptr;
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        build(root, v[i]);
    }

    int a;
    cin >> a;
    for (int i = 0; i < a; ++i) {
        int p;
        cin >> p;
        if (p == 1) {
            preorder(root);
            cout << endl;
        } 
        if (p == 2) {
            inorder(root);
            cout << endl;
        } 
        if (p == 3) {
            postorder(root);
            cout << endl;
        } 
        if (p == 4) {
            bfs(root);
        }
        if (p == 5) {
            findleavenode(root);
            cout << endl;
        }
    }

    return 0;
}
