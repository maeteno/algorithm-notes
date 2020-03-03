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

    int count;
    Node *root;

public:
    BST() {
        root = NULL;
        count = 0;
        cout << "BST" << endl;
    };

    ~BST() {
        cout << "~BST" << endl;
    };

    int size() {
        return count;
    }

    void insert(K key, V value) {
        root = insert(root, key, value);
    }

    V *search(K key) {
        return search(root, key);
    }

private:
    Node *insert(Node *node, K key, V value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }

        if (key == node->key) {
            node->value = value;
        } else if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else {
            node->right = insert(node->right, key, value);
        }

        return node;
    }

    V *search(Node *node, K key) {
        if (node == NULL) {
            return NULL;
        }

        if (node->key == key) {
            return &(node->value);
        } else if (key < node->key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }
};

#endif //ALGRITHM_NOTES_BST_H
