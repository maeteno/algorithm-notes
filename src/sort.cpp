#include <iostream>
#include "include/sort.h"
#include "include/tools.h"

using namespace std;

int main() {
    int len = 10;
    int *a = randArray(len);
    int *b = copyArray(a, len);

    cout << "RawData:\t";
    printArray(a, len);

    sort::bubble(a, len);
    cout << "Bubble:\t";
    printArray(a, len);

    sort::select(b, len);
    cout << "Select:\t";
    printArray(b, len);
}