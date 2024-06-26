#include "ListSequence.h"

template <typename T>
ListSequence<T>::ListSequence() : list() {}

template <typename T>
ListSequence<T>::ListSequence(T* items, int count) : list(items, count) {}

template <typename T>
ListSequence<T>::ListSequence(const ListSequence<T>& list) : list(list.list) {}

template <typename T>
T ListSequence<T>::GetFirst() const {
    if (this->list.GetSize() == 0) {
        throw std::out_of_range("ListSequence is empty");
    }
    return this->list.GetFirst();
}

template <typename T>
T ListSequence<T>::GetLast() const {
    if (this->list.GetSize() == 0) {
        throw std::out_of_range("ListSequence is empty");
    }
    return this->list.GetLast();
}

template <typename T>
T ListSequence<T>::Get(int index) const {
    return this->list.Get(index);
}

template <typename T>
ListSequence<T>* ListSequence<T>::GetSubsequence(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= this->list.GetSize() || startIndex > endIndex) {
        throw std::out_of_range("Invalid start or end index");
    }
    int count = endIndex - startIndex + 1;
    T* items = new T[count];
    for (int i = 0; i < count; i++) {
        items[i] = this->list.Get(startIndex + i);
    }
    ListSequence<T>* subsequence = new ListSequence<T>(items, count);
    delete[] items;
    return subsequence;
}

template <typename T>
int ListSequence<T>::GetLength() const {
    return this->list.GetSize();
}

template <typename T>
void ListSequence<T>::Append(const T& item) {
    this->list.Append(item);
}

template <typename T>
void ListSequence<T>::Prepend(const T& item) {
    this->list.Prepend(item);
}

template <typename T>
void ListSequence<T>::InsertAt(const T& item, int index) {
    this->list.InsertAt(item, index);
}

template <typename T>
Sequence<T>* ListSequence<T>::Concat(const Sequence<T>* list) const {
    ListSequence<T>* result = new ListSequence<T>(*this);
    for (int i = 0; i < list->GetLength(); i++) {
        result->Append(list->Get(i));
    }
    return result;
}

// Explicit template instantiation
template class ListSequence<int>;
