//
// Created by ssiso on 2019/7/19.
//
#include <iostream>
#include <time.h>
#include "../include/tools.h"

using namespace std;

int *randArray(int count) {
    int *a = new int[count];
    srand((unsigned) time(nullptr));
    for (int i = 0; i < count; i++) {
        a[i] = rand();
    }

    return a;
}

int *copyArray(const int *data, int len) {
    int *a = new int[len];

    for (int i = 0; i < len; i++) {
        a[i] = data[i];
    }

    return a;
}

void printArray(int *data, int len) {
    for (int i = 0; i < len; i++) {
        cout << data[i] << "\t";
    }

    cout << endl;
}