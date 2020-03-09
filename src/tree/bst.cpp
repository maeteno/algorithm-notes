#include <iostream>
#include "include/bst.h"

using namespace std;

int main() {
    auto bst = new BST<int, int>();

    bst->insert(4, 1);
    bst->insert(2, 2);
    bst->insert(3, 3);
    bst->insert(7, 4);
    bst->insert(5, 4);
    bst->insert(2, 4);
    bst->insert(6, 4);

    cout << *bst->search(2) << endl;

    delete bst;
}