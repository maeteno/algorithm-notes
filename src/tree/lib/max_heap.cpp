#include "../include/max_heap.h"

MaxHeap::MaxHeap(int capacity) {
    this->data = new int[capacity + 1];
    this->count = 0;
}

int MaxHeap::size() {
    return this->count;
}

MaxHeap::~MaxHeap() {
    delete[]this->data;
}