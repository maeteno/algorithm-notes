#include <iostream>
#include "../include/sort.h"

using namespace std;

// 将两个有序的数字合并为一个有序的数组
sort::Data _merge(sort::Data data1, sort::Data data2) {
    sort::Data data;
    data.data = new int[data1.len + data2.len];
    data.len = 0;
    int index1 = 0;
    int index2 = 0;

    while (index1 < data1.len || index2 < data2.len) {
        if (index1 >= data1.len) {
            data.data[data.len] = data2.data[index2];
            index2++;
        } else if (index2 >= data2.len) {
            data.data[data.len] = data1.data[index1];
            index1++;
        } else if (data1.data[index1] < data2.data[index2]) {
            data.data[data.len] = data1.data[index1];
            index1++;
        } else if (data1.data[index1] > data2.data[index2]) {
            data.data[data.len] = data2.data[index2];
            index2++;
        }

        data.len++;
    }

    return data;
}

// 分割数据
sort::Data _slice(const sort::Data data, int start, int end) {
    sort::Data newData;
    int len = end - start;
    newData.data = new int[len];
    newData.len = 0;
    for (int i = start; i < end; ++i) {
        newData.data[newData.len++] = data.data[i];
    }

    return newData;
}

sort::Data sort::merge(sort::Data data) {
    if (data.len < 2) {
        return data;
    }

    int middle = data.len / 2;
    auto left = _slice(data, 0, middle);
    auto right = _slice(data, middle, data.len);

    return _merge(sort::merge(left), sort::merge(right));
}