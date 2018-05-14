/*	
	Thomas Carmichael 
	ADT/Template Double Linked Link
	https://github.com/tcarmic/Data-Structures/edit/master/DoubleLinkedListADT.cpp
*/

template <class T>
struct Node {
    T info;
    Node *next, *prev;
};

template <class T>
class LinkedList {
private:
    Node<T> *head, *tail;
public:
	
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
	
    void PrintList() {
        if (head == nullptr) {
            std::cerr << "ERROR: Cannot print, list empty.\n";
            return;
        }
        Node<T> *temp = new Node<T>;
        temp = head;
        while (temp != nullptr) {
            std::cout << temp->info << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void InsertStart(const T &data) {
        Node<T> *temp = new Node<T>;
        temp->info = data;
        temp->next = nullptr;
        temp->prev = nullptr;
        if (head == nullptr) {
            head = temp;
            tail = temp;
            temp = nullptr;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
	
    void InsertEnd(const T &data) {
        Node<T> *temp = new Node<T>;
        temp->info = data;
        temp->next = nullptr;
        temp->prev = nullptr;
        if (head == nullptr) {
            head = temp;
            tail = temp;
            temp = nullptr;
            return;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
	
    void DeleteFirst() {
        if (head == nullptr) {
            std::cerr << "ERROR: Cannot delete, list empty.\n";
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp = nullptr;
    }
	
    void DeleteLast() {
        if (head == nullptr) {
            std::cerr << "ERROR: Cannot delete, list empty.\n";
            return;
        }
        Node<T> *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        temp = nullptr;
    }
	
    void DeleteFullList() {
        if (head == nullptr) {
            std::cerr << "ERROR: Cannot delete, list empty.\n";
            return;
        }
        Node<T> *temp = head;
        Node<T> *tempNext;
        while (temp != nullptr) {
            tempNext = temp->next;
            temp = nullptr;
            temp = tempNext;
        }
        tempNext = nullptr;
        head = nullptr;
        tail = nullptr;
    }
	
    void DeleteByValue(const T& data) {
        if (head == nullptr) {
            std::cerr << "ERROR: Cannot delete, list empty.\n";
            return;
        }
        Node<T> *temp = head;
        Node<T> *tempNext = nullptr;
        if (temp->next == nullptr) {
			
            if (temp->info == data) {
                head = nullptr;
                temp = nullptr;
                return;
            }
            return;
        }
        while (temp->info == data && temp != nullptr) {
            head = head->next;
            head->prev = nullptr;
            temp = head;
        }
        tempNext = temp->next;
        while (tempNext != nullptr) {
			
            if (tempNext->info == data) {
				
                if (tempNext->next == nullptr) {
                    tail = tail->prev;
                    tail->next = nullptr;
                    temp = nullptr;
                    tempNext = nullptr;
                    return;
                }
                tempNext = tempNext->next;
                temp->next = tempNext->prev = nullptr;
                temp->next = tempNext;
                tempNext->prev = temp;
            }
            else {
                temp = temp->next;
                tempNext = tempNext->next;
            }
        }
    }
};
