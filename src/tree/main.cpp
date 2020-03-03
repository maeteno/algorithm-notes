#include <iostream>
#include "include/bst.h"
#include "include/max_heap.h"
#include "../include/tools.h"

#define LEN 10

using namespace std;

int main() {
    MaxHeap maxHeap(LEN);
    int *a = randArray(LEN);
    for (int i = 0; i < LEN; i++) {
        maxHeap.insert(a[i]);
    }
    maxHeap.print();
    while (!maxHeap.isEmpty()) {
        cout << maxHeap.extractMax() << "\t";
    }
    cout << endl;

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