#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class LinkedList {
public:
    LinkedList(T* items, int count);
    LinkedList();
    LinkedList(const LinkedList<T>& other);
    ~LinkedList();

    T GetFirst() const;
    T GetLast() const;
    T Get(int index) const;
    LinkedList<T>* GetSubList(int start, int end) const;
    int GetLength() const;

    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    LinkedList<T>* Concat(LinkedList<T>* list);

private:
    // Ваши данные и узлы
};

#include "LinkedList.cpp"

#endif // LINKEDLIST_H
