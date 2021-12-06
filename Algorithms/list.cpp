#include <cstdio>
using namespace std;

class Node {
public:
	int value;
	Node *left;
	Node *right;
	Node(int value) {
		this->value = value;
		right = left = NULL;
	}
};

class DLinkedList {
private:
	int _sz;
	Node *front;
	Node *back;
public:
	DLinkedList() {
		front = back = NULL;
		_sz = 0;
	}
	void insert_front(int value) {
		Node *temp = new Node(value);
		if (_sz == 0) {
			front = back = temp;
		}
		else {
			front->left = temp;
			temp->right = front;
			front = temp;
		}
		_sz++;
	}
	void delete_front() {
		if (_sz == 0) return;
		Node *temp = front;
		if (_sz > 1) {
			front = front->right;
			front->left = NULL;
		}
		else if (_sz == 1) {
			front = back = NULL;
		}
		_sz--;
		delete(temp);
	}
	void insert_back(int value) {
		Node *temp = new Node(value);
		if (_sz == 0) {
			front = back = temp;
		}
		else {
			back->right = temp;
			temp->left = back;
			back = temp;
		}
		_sz++;
	}
	void delete_back() {
		if (_sz == 0) return;
		Node *temp = back;
		if (_sz > 1) {
			back = back->left;
			back->right = NULL;
		}
		else if (_sz == 1) {
			front = back = NULL;
		}
		_sz--;
		delete(temp);
	}
	void print_front() {
		Node *cur = front;
		for (; cur != NULL; cur = cur->right) {
			printf("%d ", cur->value);
		}
		printf("\n");
	}
	void print_back() {
		Node *cur = back;
		for (; cur != NULL; cur = cur->left) {
			printf("%d ", cur->value);
		}
		printf("\n");
	}
	int size() {
		return _sz;
	}
	~DLinkedList() {
		Node *cur = front;
		while (cur != NULL)
			delete_front();
	}
};

int main() {
	DLinkedList *list = new DLinkedList();
	for (int i = 1; i <= 6; i++) {
		list->insert_front(i);
	}
	list->print_front();
	list->print_back();

	list->delete_front();
	list->print_front();
	list->print_back();
	list->delete_back();

	list->delete_front();
	list->print_front();
	list->print_back();
	list->delete_back();

	list->delete_front();
	list->print_front();
	list->print_back();
	list->delete_back();

	list->delete_front();
	list->print_front();
	list->print_back();
	list->delete_back();
}