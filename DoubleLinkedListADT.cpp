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
	
	return 0;
}
