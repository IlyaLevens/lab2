#include "UI.h"
#include <iostream>

void UI::Start() {
    int choice;
    do {
        ShowMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                HandleArraySequence();
                break;
            case 2:
                HandleListSequence();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

void UI::ShowMenu() {
    std::cout << "\nMain Menu:\n";
    std::cout << "1. Work with ArraySequence\n";
    std::cout << "2. Work with ListSequence\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

void UI::HandleArraySequence() {
    int size;
    std::cout << "Enter the size of the ArraySequence: ";
    std::cin >> size;

    int* items = new int[size];
    std::cout << "Enter the elements of the ArraySequence:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> items[i];
    }

    ArraySequence<int> seq(items, size);
    delete[] items;

    PerformOperations(&seq);
}

void UI::HandleListSequence() {
    int size;
    std::cout << "Enter the size of the ListSequence: ";
    std::cin >> size;

    int* items = new int[size];
    std::cout << "Enter the elements of the ListSequence:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> items[i];
    }

    ListSequence<int> seq(items, size);
    delete[] items;

    PerformOperations(&seq);
}

void UI::PerformOperations(Sequence<int>* seq) {
    int choice;
    do {
        std::cout << "\nOperations Menu:\n";
        std::cout << "1. Get first element\n";
        std::cout << "2. Get last element\n";
        std::cout << "3. Get element at index\n";
        std::cout << "4. Get subsequence\n";
        std::cout << "5. Append element\n";
        std::cout << "6. Prepend element\n";
        std::cout << "7. Insert element at index\n";
        std::cout << "8. Concatenate with another sequence\n";
        std::cout << "9. Print sequence\n";
        std::cout << "0. Back to main menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        int index, startIndex, endIndex, value;
        switch (choice) {
            case 1:
                std::cout << "First element: " << seq->GetFirst() << std::endl;
                break;
            case 2:
                std::cout << "Last element: " << seq->GetLast() << std::endl;
                break;
            case 3:
                std::cout << "Enter index: ";
                std::cin >> index;
                std::cout << "Element at index " << index << ": " << seq->Get(index) << std::endl;
                break;
            case 4:
                std::cout << "Enter start index: ";
                std::cin >> startIndex;
                std::cout << "Enter end index: ";
                std::cin >> endIndex;
                {
                    Sequence<int>* subseq = seq->GetSubsequence(startIndex, endIndex);
                    std::cout << "Subsequence: ";
                    for (int i = 0; i < subseq->GetLength(); i++) {
                        std::cout << subseq->Get(i) << " ";
                    }
                    std::cout << std::endl;
                    delete subseq;
                }
                break;
            case 5:
                std::cout << "Enter value to append: ";
                std::cin >> value;
                seq->Append(value);
                break;
            case 6:
                std::cout << "Enter value to prepend: ";
                std::cin >> value;
                seq->Prepend(value);
                break;
            case 7:
                std::cout << "Enter index: ";
                std::cin >> index;
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                seq->InsertAt(value, index);
                break;
            case 8:
                {
                    int size;
                    std::cout << "Enter the size of the second sequence: ";
                    std::cin >> size;

                    int* items = new int[size];
                    std::cout << "Enter the elements of the second sequence:\n";
                    for (int i = 0; i < size; i++) {
                        std::cin >> items[i];
                    }

                    ArraySequence<int> secondSeq(items, size);
                    delete[] items;

                    seq->Concat(&secondSeq);
                }
                break;
            case 9:
                std::cout << "Sequence: ";
                for (int i = 0; i < seq->GetLength(); i++) {
                    std::cout << seq->Get(i) << " ";
                }
                std::cout << std::endl;
                break;
            case 0:
                std::cout << "Returning to main menu...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}
