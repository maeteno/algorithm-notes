#include "../include/sort.h"
#include <iostream>

using namespace std;

// 冒泡排序
void sort::bubble(int data[], int len) {
    for (int i = len - 1; i > 0 ; --i) {
        for (int j = 0; j < i; ++ j) {
            if(data[j] > data[j+1]){
                int tmp = data[j];
                data[j] = data[j +1];
                data[j+1] = tmp;
            }
        }
    }
}