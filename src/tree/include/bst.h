#ifndef ALGRITHM_NOTES_BST_H
#define ALGRITHM_NOTES_BST_H

#include <iostream>

using namespace std;

/**
 * 二分搜索树
 *
 * @tparam K
 * @tparam V
 */
template<typename K, typename V>
class BST {
private:
    struct Node {
        K key;
        V value;
        Node *left;
        Node *right;

        Node(K key, V value) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    Node *root;

public:
    BST() {
        cout << "BST" << endl;
    };

    ~BST() {
        cout << "~BST" << endl;
    };
};

#endif //ALGRITHM_NOTES_BST_H
