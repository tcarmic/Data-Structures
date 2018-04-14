// @Thomas - Double Linked List w/ ADT template implementation
#include<iostream>
using namespace std;

template <class T>
struct node {
	T info;
	node *next, *prev;
};

template <class T>
class linkedList {
private:
	node<T> *head, *tail;
public:
	
	linkedList(){
		head = NULL;
		tail = NULL;
	}

	void printList(){
		node<T> *temp = new node<T>;
		temp = head;
		while (temp != NULL){
			cout << temp->info << " ";
			temp = temp->next;
		}
	}
	
	void insertStart(T data){
		node<T> *temp = new node<T>;
		temp->info = data;
		temp->next = NULL;
		temp->prev = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
			return;
		}
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

	void insertEnd(T data) {
		node<T> *temp = new node<T>;
		temp->info = data;
		temp->next = NULL;
		temp->prev = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
			return;
		}
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}

	void deleteFirst(){
		if (head == NULL){
			cerr << "ERROR: Cannot delete, list empty.\n";
			return;
		}
		node<T> *temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
	}

	void deleteLast(){
		if (head == NULL) {
			cerr << "ERROR: Cannot delete, list empty.\n";
			return;
		}
		node<T> *temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
	}
	
	void deleteFullList(){
		// next: add function to delete each node of linkedlist
	}
};

int main(){
/*
	// DEMO
	linkedList<int> sampleLinkedList;
	sampleLinkedList.insertStart(50);
	sampleLinkedList.insertStart(61);
	sampleLinkedList.insertStart(25);
	sampleLinkedList.insertStart(73);
	sampleLinkedList.insertStart(92);
	sampleLinkedList.insertEnd(48);
	cout << "Linked List Before: ";
	sampleLinkedList.printList();
	cout << "\nInserting Node at End.\n";
	sampleLinkedList.insertEnd(17);
	sampleLinkedList.printList();
	cout << "\nInserting Node at Start.\n";
	sampleLinkedList.insertStart(23);
	sampleLinkedList.printList();
	cout << "\nDeleting Node at Start.\n";
	sampleLinkedList.deleteFirst();
	sampleLinkedList.printList();
	cout << "\nDeleting Node at End.\n";
	sampleLinkedList.deleteLast();
	sampleLinkedList.printList();
	cout << "\n";
*/
	//system("pause"); // uncomment if windows
	return 0;
}
