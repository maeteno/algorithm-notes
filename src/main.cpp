#include <iostream>
#include "include/sort.h"

using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5, 67, 34, 6432, 543, 1213};

    int len = sizeof(a) / sizeof(a[0]);
    cout << len << endl;
    sort::bubble(a, 10);
}