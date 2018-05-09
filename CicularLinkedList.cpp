// Thomas Carmichael - Circular Linked List w/ ADT template implementation
#include <iostream>
#include <string>
#define _WIN32 0 // define 1 if windows 32 architecture

template <class T>
struct Node {
    T info;
    Node *next, *prev;
};

template <class T>
class LinkedList {
private:
    Node<T> *first;

public:
    LinkedList() {
        first = nullptr;
    }

    void PrintList() {
        if (first == nullptr) {
            std::cerr << "ERROR: Cannot print, list empty.\n";
            return;
        }
        Node<T> *temp = new Node<T>;
        temp = first;
        do {
            std::cout << temp->info << " ";
            temp = temp->next;
        } while (temp != first);
        std::cout << std::endl;
    }

    void InsertStart(const T &data) {
        Node<T> *temp = new Node<T>;
        temp->info = data;
        temp->next = nullptr;
        temp->prev = nullptr;
        if (first == nullptr) {
            first = temp;
            temp = nullptr;
            return;
        }
        else if (first->next == nullptr) {
            temp->next = first;
            temp->prev = first;
            first->next = temp;
            first->prev = temp;
            first = temp;
            temp = nullptr;
            return;
        }
        temp->next = first;
        temp->prev = first->prev;
        first->prev->next = temp;
        first->prev = temp;
        first = temp;
    }

    void InsertEnd(const T &data) {
        Node<T> *temp = new Node<T>;
        temp->info = data;
        temp->next = nullptr;
        temp->prev = nullptr;
        if (first == nullptr) {
            first = temp;
            temp = nullptr;
            return;
        }
        else if (first->next == nullptr) {
            temp->next = first;
            temp->prev = first;
            first->next = temp;
            first->prev = temp;
            temp = nullptr;
            return;
        }
        temp->next = first;
        temp->prev = first->prev;
        first->prev->next = temp;
        first->prev = temp;
    }
    
    // TODO
    // various other insert and delete methods
    // traverse/print from specific node
    // sort circular linked list
    // searching algs on sorted list

};

// demo
int main() {
    LinkedList<int> test;
    test.InsertStart(0); test.InsertStart(2);
    test.InsertStart(4); test.InsertStart(6);
    test.InsertStart(8); test.InsertStart(10);
    test.PrintList();

    // architecture specific output:
#if _WIN32 
    std::cout << "Press any key to continue." << std::endl;
    system("pause");
#else
    std::cout << "Press enter to continue." << std::endl;
    std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
#endif

    return 0;
}
