#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

public:
    // Constructors
    DynamicArray(T* items, int count);
    DynamicArray(int size);
    DynamicArray(const DynamicArray<T>& array);

    // Destructor
    ~DynamicArray();

    // Other member functions
    T Get(int index) const;
    void Set(int index, T value);
    int GetSize() const;
    void Resize(int newSize);
};

// Include implementation file
#include "DynamicArray.hpp"

#endif // DYNAMICARRAY_H
