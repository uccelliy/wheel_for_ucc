#include <iostream>
#include "array.h"


int main() {
    MyArrayList<int> arr(3);
    arr.display();
    arr.addLast(1);
    arr.display();
    arr.add(1, 3);
    arr.display();
}