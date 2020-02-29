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

    while (!maxHeap.isEmpty()){
        cout << maxHeap.extractMax() << "\t";
    }

    cout << endl;
}