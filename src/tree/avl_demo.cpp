#ifdef _UNIX
#include <cstdio>
#include <sys/malloc.h>
#include <cstdlib>
#endif

#ifdef linux
#include <malloc.h>
#endif

struct AVLNode {
    int value;
    int balance;
    AVLNode *left;
    AVLNode *right;
    AVLNode *parent;
};

struct AVLTree {
    AVLNode *root;
} tree;

int height(AVLNode *a) {
    if (a == 0) {
        return 0;
    }
    int rightHeight = height(a->right);
    int leftHeight = height(a->left);
    return rightHeight > leftHeight ? (rightHeight + 1) : (leftHeight + 1);
}

struct AVLNode *select(int value, AVLNode *root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->value == value) {
        return root;
    }
    if (root->value > value) {
        if (root->left)
            return select(value, root->left);
        else
            return root;
    }
    if (root->value < value) {
        if (root->right)
            return select(value, root->right);
        else
            return root;
    }

    return nullptr;
}

void setBalance(AVLNode *a) {
    if (a)
        a->balance = height(a->right) - height(a->left);
}

struct AVLNode *turnLeft(AVLNode *a) {
    AVLNode *b = a->right;
    if (a->parent != nullptr) {
        if (a->parent->right == a) {
            a->parent->right = b;
        } else {
            a->parent->left = b;
        }
    }
    b->parent = a->parent;
    a->parent = b;
    a->right = b->left;
    b->left = a;
    if (a->right != 0)
        a->right->parent = a;
    setBalance(a);
    setBalance(b);
    return b;
}

struct AVLNode *turnRight(AVLNode *a) {
    AVLNode *b = a->left;
    if (a->parent != 0) {
        if (a->parent->right == a) {
            a->parent->right = b;
        } else {
            a->parent->left = b;
        }
    }
    b->parent = a->parent;
    a->parent = b;
    a->left = b->right;
    if (a->left != 0)
        a->left->parent = a;
    b->right = a;
    setBalance(a);
    setBalance(b);
    return b;
}

struct AVLNode *turnLeftThenRight(AVLNode *a) {
    a->left = turnLeft(a->left);
    return turnRight(a);
}

struct AVLNode *turnRightThenLeft(AVLNode *a) {
    a->right = turnRight(a->right);
    return turnLeft(a);
}

void rebalance(AVLNode *a) {
    setBalance(a);
    if (a->balance == -2) {
        if (a->left->balance <= 0) {
            a = turnRight(a);
        } else {
            a = turnLeftThenRight(a);
        }
    } else if (a->balance == 2) {
        if (a->right->balance >= 0) {
            a = turnLeft(a);
        } else {
            a = turnRightThenLeft(a);
        }
    }
    if (a->parent) {
        rebalance(a->parent);
    } else {
        tree.root = a;
    }
}

void insert(int value, AVLNode *root) {
    AVLNode *node = select(value, root);
    if (node == 0) {
        tree.root = (AVLNode *) malloc(sizeof(AVLNode));
        tree.root->value = value;
        tree.root->left = tree.root->right = 0;
        tree.root->parent = 0;
        tree.root->balance = 0;
    } else if (node->value != value) {
        if (node->value > value) {
            node->left = (AVLNode *) malloc(sizeof(AVLNode));
            node->left->value = value;
            node->left->left = node->left->right = 0;
            node->left->parent = node;
            node->left->balance = 0;
            rebalance(node);
        } else if (node->value < value) {
            node->right = (AVLNode *) malloc(sizeof(AVLNode));
            node->right->value = value;
            node->right->left = node->right->right = 0;
            node->right->parent = node;
            node->right->balance = 0;
            rebalance(node);
        }
    }
}

void delnodeifhas1childornot(AVLNode *a) {
    if (a->parent == 0) {
        if (a->left) {
            tree.root = a->left;
            a->left->parent = 0;
        } else {
            tree.root = a->right;
            a->right->parent = 0;
        }
    } else {
        if (a->parent->left == a) {
            if (a->left) {
                a->parent->left = a->left;
                a->left->parent = a->parent;
            } else {
                a->parent->left = a->right;
                if (a->right)
                    a->right->parent = a->parent;
            }
        } else {
            if (a->left) {
                a->parent->right = a->left;
                a->left->parent = a->parent;
            } else {
                a->parent->right = a->right;
                if (a->right)
                    a->right->parent = a->parent;
            }
        }
        rebalance(a->parent);
    }
}

struct AVLNode *getMin(AVLNode *a) {
    if (a->left)
        getMin(a->left);
    else
        return a;

    return nullptr;
}

void delNodeIfHas2Child(AVLNode *a) {
    AVLNode *after = getMin(a->right);
    a->value = after->value;
    delnodeifhas1childornot(after);
}

void del(int value, AVLNode *root) {
    AVLNode *node = select(value, root);
    if (node->value == value) {
        if (node->left && node->right) {
            delNodeIfHas2Child(node);
        } else {
            delnodeifhas1childornot(node);
        }
    }
}

void insertNodeTest() {
    insert(5, tree.root);
    insert(6, tree.root);
    insert(7, tree.root);
    insert(3, tree.root);
    insert(4, tree.root);
    insert(4, tree.root);
    insert(5, tree.root);
    insert(5, tree.root);
    insert(3, tree.root);
    insert(8, tree.root);
    insert(9, tree.root);
    insert(10, tree.root);
    insert(11, tree.root);
    insert(12, tree.root);
}

void delNodeTest() {
    del(6, tree.root);
    del(11, tree.root);
    del(12, tree.root);
    del(3, tree.root);
    del(3, tree.root);
    del(5, tree.root);
    del(9, tree.root);
    del(12, tree.root);
}

// https://www.cnblogs.com/coding-nerver-die/p/10975599.html
int main() {
    insertNodeTest(); // 测试构建AVL树
    delNodeTest();    // 测试删除AVL树节点
}