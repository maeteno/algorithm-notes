#ifndef ALGRITHM_NOTES_MAX_HEAP_H
#define ALGRITHM_NOTES_MAX_HEAP_H

/**
 * 最大堆
 * 功能：
 * 1. 插入
 * 2. 获取
 */
class MaxHeap{
private:
    int* data;
    int count;
    int capacity;
    void shiftUp(int k);
    void shiftDown(int k);

public:
    explicit MaxHeap(int capacity);
    ~MaxHeap();
    int size();
    void insert(int item);
    bool isEmpty();
    void print();
    int extractMax();
};

#endif //ALGRITHM_NOTES_MAX_HEAP_H
