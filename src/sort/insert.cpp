//
// Created by 傅双亮 on 2019-07-18.
//
#include <iostream>
#include "../include/sort.h"

using namespace std;


void _insert(int data[], int from, int to) {
    int value = data[from];

    for (int i = from; i > to; --i) {
        data[i] = data[i - 1];
    }

    data[to] = value;
}

// 插入排序
void sort::insert(int data[], int len) {
    int value = 0;
    for (int i = 1; i < len; ++i) {
        value = data[i];

        for (int j = i - 1; j >= 0; --j) {
            if (value < data[j]) {
                if (0 == j) {
                    _insert(data, i, j);
                    continue;
                } else if (value >= data[j - 1]) {
                    _insert(data, i, j);
                    continue;
                }
            }
        }
    }
}