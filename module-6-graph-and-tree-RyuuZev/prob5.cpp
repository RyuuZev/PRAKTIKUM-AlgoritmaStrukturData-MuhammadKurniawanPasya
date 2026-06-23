#include <iostream>
#include <vector>
#include <string>
#include "RedBlackTree.h"

using namespace std;

void preorder(
    const RedBlackTree::Node* node,
    const RedBlackTree::Node* nil,
    vector<int>& result) {

    if (node == nil || node->isNil)
        return;

    result.push_back(node->key);

    preorder(node->left, nil, result);
    preorder(node->right, nil, result);
}

void inorder(
    const RedBlackTree::Node* node,
    const RedBlackTree::Node* nil,
    vector<int>& result) {

    if (node == nil || node->isNil)
        return;

    inorder(node->left, nil, result);

    result.push_back(node->key);

    inorder(node->right, nil, result);
}

void postorder(
    const RedBlackTree::Node* node,
    const RedBlackTree::Node* nil,
    vector<int>& result) {

    if (node == nil || node->isNil)
        return;

    postorder(node->left, nil, result);
    postorder(node->right, nil, result);

    result.push_back(node->key);
}

void printTraversal(
    const string& title,
    const vector<int>& data) {

    cout << "[" << title << "] :";

    for (int x : data) {
        cout << " " << x;
    }

    cout << '\n';
}

int main() {
    int N;
    cin >> N;

    RedBlackTree tree;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (!tree.contains(x))
            tree.insert(x);
    }

    int Q;
    cin >> Q;

    if (tree.empty()) {
        cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
        return 0;
    }

    while (Q--) {
        string query;
        cin >> query;

        vector<int> pre;
        vector<int> in;
        vector<int> post;

        if (query == "PREORDER") {
            preorder(tree.root(), tree.nil(), pre);
            printTraversal("Preorder", pre);
        }
        else if (query == "INORDER") {
            inorder(tree.root(), tree.nil(), in);
            printTraversal("Inorder", in);
        }
        else if (query == "POSTORDER") {
            postorder(tree.root(), tree.nil(), post);
            printTraversal("Postorder", post);
        }
        else if (query == "ALL") {
            preorder(tree.root(), tree.nil(), pre);
            inorder(tree.root(), tree.nil(), in);
            postorder(tree.root(), tree.nil(), post);

            printTraversal("Preorder", pre);
            printTraversal("Inorder", in);
            printTraversal("Postorder", post);
        }
    }

    return 0;
}