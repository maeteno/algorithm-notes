#include <iostream>
#include "include/sort.h"
#include "../include/tools.h"

#define LEN 15

using namespace std;
using namespace sort;

int main() {
    int *a = randArray(LEN);
    int *b = copyArray(a, LEN);
    int *c = copyArray(a, LEN);
    int *d = copyArray(a, LEN);

    cout << "Raw:\t";
    printArray(a, LEN);

    bubble(a, LEN);
    cout << "Bubble:\t";
    printArray(a, LEN);

    select(b, LEN);
    cout << "Select:\t";
    printArray(b, LEN);

    insert(c, LEN);
    cout << "Insert:\t";
    printArray(c, LEN);

    Data data;
    data.data = d;
    data.len = LEN;
    auto data2 = merge(data);
    cout << "Merge:\t";
    printArray(data2.data, data2.len);

    delete d;
    delete c;
    delete b;
    delete a;

    return  0;
}