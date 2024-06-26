#ifndef LISTSEQUENCE_H
#define LISTSEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"

template <typename T>
class ListSequence : public Sequence<T> {
public:
    ListSequence();
    ListSequence(T* items, int count);
    ListSequence(const ListSequence<T>& list);

    T GetFirst() const override;
    T GetLast() const override;
    T Get(int index) const override;
    ListSequence<T>* GetSubsequence(int startIndex, int endIndex) const override;
    int GetLength() const override;

    void Append(const T& item) override;
    void Prepend(const T& item) override;
    void InsertAt(const T& item, int index) override;
    Sequence<T>* Concat(const Sequence<T>* list) const override;

private:
    LinkedList<T> list;
};

#endif // LISTSEQUENCE_H
