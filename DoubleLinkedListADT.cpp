// @Thomas - Double Linked List w/ ADT template implementation

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

	linkedList() {
		head = NULL;
		tail = NULL;
	}

	void printList() {
		node<T> *temp = new node<T>;
		temp = head;
		while (temp != NULL) {
			std::cout << temp->info << " ";
			temp = temp->next;
		}
	}

	void insertStart(T data) {
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

	void deleteFirst() {
		if (head == NULL) {
			std::cerr << "ERROR: Cannot delete, list empty.\n";
			return;
		}
		node<T> *temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
	}

	void deleteLast() {
		if (head == NULL) {
			std::cerr << "ERROR: Cannot delete, list empty.\n";
			return;
		}
		node<T> *temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
	}

	void deleteFullList() {
		if (head == NULL) {
			std::cerr << "ERROR: Cannot delete, list empty.\n";
			return;
		}
		node<T> *temp = head;
		node<T> *tempNext;
		while (temp != NULL) {
			tempNext = temp->next;
			delete temp;
			temp = tempNext;
		}
		head = NULL;
		tail = NULL;
	}

	// next: add function to insert/delete a specific element or location in list
};
