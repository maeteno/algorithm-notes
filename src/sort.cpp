#include <iostream>
#include "include/sort.h"
#include "include/tools.h"

#define LEN 100

using namespace std;

int main() {

    int *a = randArray(LEN);
    int *b = copyArray(a, LEN);
    int *c = copyArray(a, LEN);

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
}