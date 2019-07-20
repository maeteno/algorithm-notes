#include <iostream>
#include "include/sort.h"
#include "include/tools.h"

#define LEN 10

using namespace std;

int main() {

    int *a = randArray(LEN);
    int *b = copyArray(a, LEN);
    int *c = copyArray(a, LEN);
    int *d = copyArray(a, LEN);

    cout << "Raw:\t";
    printArray(a, LEN);

    sort::bubble(a, LEN);
    cout << "Bubble:\t";
    printArray(a, LEN);

    sort::select(b, LEN);
    cout << "Select:\t";
    printArray(b, LEN);

    sort::insert(c, LEN);
    cout << "Insert:\t";
    printArray(c, LEN);

    sort::Data data;
    data.data = d;
    data.len = LEN;
    auto data2 = sort::merge(data);
    cout << "Merge:\t";
    printArray(data2.data, data2.len);
}