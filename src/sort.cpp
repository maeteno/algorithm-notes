#include <iostream>
#include "include/sort.h"

using namespace std;

int main() {
    int a[] = {13, 23, 3, 4, 52, 67, 34, 62, 43, 123};
    int b[] = {13, 23, 3, 4, 52, 67, 34, 62, 43, 123};

    sort::bubble(a, 10);

    for (int i : a) {
        cout << i << "\t";
    }

    cout << endl;

    sort::select(b, 10);
}