#include <cstdio>
using namespace std;

class Node {
public:
	int data;
	Node *ptr;
};

class List {
private:
	int _size = 0;
	Node *front;
	Node *back;
public:
	~List() {
		Node *curr = front;
		while (curr != NULL) {
			Node *node = curr;
			curr = curr->ptr;
			delete(node);
		}
	}
	void push_back(int data) {
		Node *node = new Node();
		node->data = data;
		node->ptr = NULL;
		if (_size == 0) {
			front = back = node;
		}
		else {
			back->ptr = node;
			back = node;
		}
		_size++;
	}
	int pop_front() {
		int data = front->data;
		Node *node = front;
		if (_size == 1) {
			front = back = NULL;
		}
		else {
			front = front->ptr;
		}
		_size--;
		delete(node);
		return data;
	}
	int size() {
		return _size;
	}
};

List L;

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		L.push_back(i);

	while (L.size() != 1) {
		L.pop_front();
		if (L.size() == 1) break;

		int data = L.pop_front();
		L.push_back(data);
		if (L.size() == 1) break;
	}

	printf("%d", L.pop_front());
}