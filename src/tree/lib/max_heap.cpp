#include <iostream>
#include "../include/max_heap.h"
#include "../../include/tools.h"

using namespace std;

MaxHeap::MaxHeap(int capacity) {
    this->data = new int[capacity + 1];
    this->count = 0;
    this->capacity = capacity;
}

int MaxHeap::size() {
    return this->count;
}

MaxHeap::~MaxHeap() {
    delete[] this->data;
}

bool MaxHeap::isEmpty() {
    return this->count == 0;
}

void MaxHeap::insert(int item) {
    assert(count + 1 <= this->capacity);

    this->data[this->count + 1] = item;
    this->count++;
    shiftUp(count);
}

// 从最大堆中取出堆顶元素, 即堆中所存储的最大数据
int MaxHeap::extractMax(){
    assert( count > 0 );
    int ret = data[1];

    swap( data[1] , data[count] );
    count --;
    shiftDown(1);

    return ret;
}

void MaxHeap::shiftDown(int k){
    while( 2*k <= count ){
        int j = 2*k; // 在此轮循环中,data[k]和data[j]交换位置
        if( j+1 <= count && data[j+1] > data[j] )
            j ++;
        // data[j] 是 data[2*k]和data[2*k+1]中的最大值

        if( data[k] >= data[j] ) break;
        swap( data[k] , data[j] );
        k = j;
    }
}


void MaxHeap::shiftUp(int k) {
    while( k > 1 && data[k/2] < data[k] ){
        swap( data[k/2], data[k] );
        k /= 2;
    }
}

void MaxHeap::print() {
    printArray(this->data, this->count+1);
}
