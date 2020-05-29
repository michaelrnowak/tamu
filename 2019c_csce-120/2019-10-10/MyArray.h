#ifndef MYARRAY_H
#define MYARRAY_H
struct MyArray {
    int *arr = nullptr;
    unsigned int capacity = 0; // no elements can store
    unsigned int size = 0; // no elements currently held
};
#endif