#include <iostream>
#include "../include/sort.h"

using namespace std;

// 选择排序
void sort::select(int data[], int len) {
    int tmp, index;
    for (int i = 0; i < len - 1; i++) {
        tmp = data[i];
        index = i;
        for (int j = i; j < len; ++j) {
            if (data[j] < tmp) {
                tmp = data[j];
                index = j;
            }
        }

        if (index != i) {
            data[index] = data[i];
            data[i] = tmp;
        }
    }
}