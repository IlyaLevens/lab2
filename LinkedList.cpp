#include "LinkedList.h"
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList(T* items, int count) : head(nullptr), tail(nullptr), length(0) {
    for (int i = 0; i < count; ++i) {
        Append(items[i]);
    }
}

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), length(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr), length(0) {
    Node* current = other.head;
    while (current) {
        Append(current->data);
        current = current->next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
T LinkedList<T>::GetFirst() const {
    if (length == 0) {
        throw std::out_of_range("List is empty");
    }
    return head->data;
}

template <typename T>
T LinkedList<T>::GetLast() const {
    if (length == 0) {
        throw std::out_of_range("List is empty");
    }
    return tail->data;
}

template <typename T>
T LinkedList<T>::Get(int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= length || startIndex > endIndex) {
        throw std::out_of_range("Index out of range");
    }
    LinkedList<T>* subList = new LinkedList<T>();
    Node* current = head;
    for (int i = 0; i < startIndex; ++i) {
        current = current->next;
    }
    for (int i = startIndex; i <= endIndex; ++i) {
        subList->Append(current->data);
        current = current->next;
    }
    return subList;
}

template <typename T>
int LinkedList<T>::GetLength() const {
    return length;
}

template <typename T>
void LinkedList<T>::Append(T item) {
    Node* newNode = new Node{item, nullptr};
    if (length == 0) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    ++length;
}

template <typename T>
void LinkedList<T>::Prepend(T item) {
    Node* newNode = new Node{item, head};
    if (length == 0) {
        head = tail = newNode;
    } else {
        head = newNode;
    }
    ++length;
}

template <typename T>
void LinkedList<T>::InsertAt(T item, int index) {
    if (index < 0 || index > length) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        Prepend(item);
        return;
    }
    if (index == length) {
        Append(item);
        return;
    }
    Node* newNode = new Node{item, nullptr};
    Node* current = head;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    ++length;
}

template <typename T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list) {
    LinkedList<T>* newList = new LinkedList<T>();
    Node* current = head;
    while (current) {
        newList->Append(current->data);
        current = current->next;
    }
    current = list->head;
    while (current) {
        newList->Append(current->data);
        current = current->next;
    }
    return newList;
}
