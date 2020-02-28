#ifndef ALGRITHM_NOTES_MAX_HEAP_H
#define ALGRITHM_NOTES_MAX_HEAP_H

/**
 * 最大堆
 */
class MaxHeap{
private:
    int* data;
    int count;

public:
    MaxHeap(int capacity);
    int size();
    ~MaxHeap();
};
#endif //ALGRITHM_NOTES_MAX_HEAP_H
