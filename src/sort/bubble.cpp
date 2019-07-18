//
// Created by ssiso on 2019/7/16.
//

#include "bubble.h"
#include <iostream>

using namespace std;


class Bubble;

Bubble::Bubble() {}

Bubble::Bubble(int data) {
    this->data = data;
}

void Bubble::Print() {
    cout << "print 12134123" << endl;
}

//int main(){
//    auto bubble = new sort::Bubble<int>(1);
//    bubble->Print();
//}
