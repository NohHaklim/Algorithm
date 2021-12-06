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
	Node *iter_front() {
		return front;
	}
	Node *iter_back() {
		return back;
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
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		DLinkedList *list = new DLinkedList();
		char buf[100001];
		int n;
		bool reversed = false;
		bool error = false;
		scanf("%s", buf);
		scanf("%d", &n);

		getchar();
		for (int i = 0; i < n; i++) {
			int value;
			getchar(); scanf("%d", &value);
			list->insert_back(value);
		} getchar(); getchar();

		for (int i = 0; buf[i]; i++) {
			switch (buf[i]) {
			case 'R':
				if (reversed) reversed = false;
				else reversed = true;
				break;
			case 'D':
				if (list->size() > 0) {
					if (reversed) {
						list->delete_back();
					}
					else {
						list->delete_front();
					}
				}
				else error = true;
				break;
			}
		}

		if (error) {
			printf("error\n");
		}
		else {
			if (reversed) {
				Node *cur = list->iter_back();
				printf("[");
				for (; cur != NULL; cur = cur->left) {
					printf("%d", cur->value);
					if (cur->left != NULL) printf(",");
				}
				printf("]\n");
			}
			else {
				Node *cur = list->iter_front();
				printf("[");
				for (; cur != NULL; cur = cur->right) {
					printf("%d", cur->value);
					if (cur->right != NULL) printf(",");
				}
				printf("]\n");
			}
		}	
	}
}