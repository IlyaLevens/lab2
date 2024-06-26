#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include "DynamicArray.h"
#include <stdexcept>

// Constructors
template <typename T>
DynamicArray<T>::DynamicArray(T* items, int count) : size(count) {
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = items[i];
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(int size) : size(size) {
    data = new T[size];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& array) : size(array.size) {
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = array.data[i];
    }
}

// Destructor
template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

// Other member functions
template <typename T>
T DynamicArray<T>::Get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
void DynamicArray<T>::Set(int index, T value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
}

template <typename T>
int DynamicArray<T>::GetSize() const {
    return size;
}

template <typename T>
void DynamicArray<T>::Resize(int newSize) {
    T* newData = new T[newSize];
    int minSize = (newSize < size) ? newSize : size;
    for (int i = 0; i < minSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size = newSize;
}

#endif // DYNAMICARRAY_HPP
