#ifndef UI_H
#define UI_H

#include "ArraySequence.h"
#include "ListSequence.h"
#include <iostream>

class UI {
public:
    void Start();

private:
    void ShowMenu();
    void HandleArraySequence();
    void HandleListSequence();
    void PrintArraySequence(ArraySequence<int>& seq);
    void PrintListSequence(ListSequence<int>& seq);
    void PerformOperations(Sequence<int>* seq);
};

#endif // UI_H
