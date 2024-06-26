#include "ArraySequence.h"
#include <stdexcept>

template <class T>
ArraySequence<T>::ArraySequence(T* items, int count) {
    this->items = new DynamicArray<T>(items, count);
}

template <class T>
ArraySequence<T>::ArraySequence() {
    this->items = new DynamicArray<T>(0);
}

template <class T>
ArraySequence<T>::ArraySequence(DynamicArray<T>& array) {
    this->items = new DynamicArray<T>(array);
}

template <class T>
ArraySequence<T>::~ArraySequence() {
    delete this->items;
}

template <class T>
T ArraySequence<T>::GetFirst() {
    if (this->items->GetSize() == 0) throw std::out_of_range("Index out of range");
    return this->items->Get(0);
}

template <class T>
T ArraySequence<T>::GetLast() {
    if (this->items->GetSize() == 0) throw std::out_of_range("Index out of range");
    return this->items->Get(this->items->GetSize() - 1);
}

template <class T>
T ArraySequence<T>::Get(int index) {
    return this->items->Get(index);
}

template <class T>
Sequence<T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex) {
    if (startIndex < 0 || endIndex >= this->items->GetSize() || startIndex > endIndex) throw std::out_of_range("Index out of range");
    T* subItems = new T[endIndex - startIndex + 1];
    for (int i = startIndex; i <= endIndex; i++) {
        subItems[i - startIndex] = this->items->Get(i);
    }
    Sequence<T>* subsequence = new ArraySequence<T>(subItems, endIndex - startIndex + 1);
    delete[] subItems;
    return subsequence;
}

template <class T>
int ArraySequence<T>::GetLength() {
    return this->items->GetSize();
}

template <class T>
Sequence<T>* ArraySequence<T>::Append(T item) {
    this->items->Resize(this->items->GetSize() + 1);
    this->items->Set(this->items->GetSize() - 1, item);
    return this;
}

template <class T>
Sequence<T>* ArraySequence<T>::Prepend(T item) {
    this->items->Resize(this->items->GetSize() + 1);
    for (int i = this->items->GetSize() - 1; i > 0; i--) {
        this->items->Set(i, this->items->Get(i - 1));
    }
    this->items->Set(0, item);
    return this;
}

template <class T>
Sequence<T>* ArraySequence<T>::InsertAt(T item, int index) {
    if (index < 0 || index > this->items->GetSize()) throw std::out_of_range("Index out of range");
    this->items->Resize(this->items->GetSize() + 1);
    for (int i = this->items->GetSize() - 1; i > index; i--) {
        this->items->Set(i, this->items->Get(i - 1));
    }
    this->items->Set(index, item);
    return this;
}

template <class T>
Sequence<T>* ArraySequence<T>::Concat(Sequence<T>* list) {
    int oldSize = this->items->GetSize();
    this->items->Resize(oldSize + list->GetLength());
    for (int i = 0; i < list->GetLength(); i++) {
        this->items->Set(oldSize + i, list->Get(i));
    }
    return this;
}
