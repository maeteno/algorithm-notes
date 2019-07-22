#include "../include/sort.h"
#include <iostream>

using namespace std;

// 交换 i 和 j 的位置
void swap(int *data, int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

// 返回基准元素排序后的位置
// len 表示排序数据的长度
int partition(int *data, int len, int start) {
    int end = start + len;
    int datum = data[start];
    int index = start;
    for (int i = start + 1; i < end; ++i) {

    }
}


// 快速排序
// len 表示该数组的长度
// index 表示基准数据的下标
void sort::quick(int *data, int len, int start = 0) {
    if (len < 2) {
        return;
    }

    int parting = partition(data, len, start);

    int leftStart = start;
    int leftLen = parting - start;
    sort::quick(data, leftLen, leftStart);

    int rightStart = parting + 1;
    int rightLen = len - parting;
    sort::quick(data, rightLen, leftStart);
}