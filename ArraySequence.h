#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

#include "DynamicArray.h"
#include "Sequence.h"

template <typename T>
class ArraySequence : public Sequence<T> {
public:
    ArraySequence();
    ArraySequence(T* items, int count);
    ArraySequence(const ArraySequence<T>& array);

    T GetFirst() const override;
    T GetLast() const override;
    T Get(int index) const override;
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) const override;
    int GetLength() const override;

    void Append(const T& item) override;
    void Prepend(const T& item) override;
    void InsertAt(const T& item, int index) override;
    Sequence<T>* Concat(const Sequence<T>* list) const override;

private:
    DynamicArray<T> array;
};

#endif // ARRAYSEQUENCE_H
