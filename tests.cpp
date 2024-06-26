#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"

void TestDynamicArray() {
    int items[] = {1, 2, 3, 4, 5};
    DynamicArray<int> arr(items, 5);
    assert(arr.Get(0) == 1);
    assert(arr.Get(4) == 5);
    arr.Set(0, 10);
    assert(arr.Get(0) == 10);
    arr.Resize(7);
    assert(arr.GetSize() == 7);
}

void TestLinkedList() {
    int items[] = {1, 2, 3, 4, 5};
    LinkedList<int> list(items, 5);
    assert(list.GetFirst() == 1);
    assert(list.GetLast() == 5);
    list.Append(6);
    assert(list.Get(5) == 6);
    list.Prepend(0);
    assert(list.GetFirst() == 0);
    list.InsertAt(7, 3);
    assert(list.Get(3) == 7);
}

void TestSequence() {
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arrSeq(items, 5);
    ListSequence<int> listSeq(items, 5);
    assert(arrSeq.GetFirst() == 1);
    assert(listSeq.GetFirst() == 1);
    arrSeq.Append(6);
    listSeq.Append(6);
    assert(arrSeq.GetLast() == 6);
    assert(listSeq.GetLast() == 6);
}

int main() {
    TestDynamicArray();
    TestLinkedList();
    TestSequence();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
