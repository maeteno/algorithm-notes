#include <iostream>
#include "include/bst.h"
#include "include/max_heap.h"

using namespace std;

int main() {
    BST<int, int> *bst = new BST<int, int>();
    delete bst;

    MaxHeap maxHeap(1);

    cout << maxHeap.size() << endl;
}