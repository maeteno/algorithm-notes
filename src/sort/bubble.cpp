//
// Created by ssiso on 2019/7/16.
//

#include "bubble.h"
#include <iostream>

using namespace std;

template<typename T>
Bubble<T>::Bubble() {}

template<typename T>
Bubble<T>::Bubble(T data) {
    this->data = data;
}

template<typename T>
void Bubble<T>::Print() {
    cout << "print 12134123" << endl;
}

//int main(){
//    auto bubble = new sort::Bubble<int>(1);
//    bubble->Print();
//}
