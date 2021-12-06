#include <cstdio>
#include <cstring>
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
	int delete_front() {
		if (_sz == 0) return -1;
		Node *temp = front;
		int ret = front->value;
		if (_sz > 1) {
			front = front->right;
			front->left = NULL;
		}
		else if (_sz == 1) {
			front = back = NULL;
		}
		_sz--;
		delete(temp);
		return ret;
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
	int delete_back() {
		if (_sz == 0) return -1; // 이 문제에서는 -1이 안들어오므로, 오류값으로 설정해도 된다.
		Node *temp = back;
		int ret = back->value;
		if (_sz > 1) {
			back = back->left;
			back->right = NULL;
		}
		else if (_sz == 1) {
			front = back = NULL;
		}
		_sz--;
		delete(temp);
		return ret;
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
	bool empty() {
		if (_sz) return false;
		else return true;
	}
	~DLinkedList() {
		Node *cur = front;
		while (cur != NULL)
			delete_front();
	}
};

int ctoi(char *str) {
	int res = 0;
	for (int i = 0; str[i];) {
		res += str[i] - '0';
		if (str[++i]) res *= 10;
	}
	return res;
}

int main() {
	int N;
	char buf[30];
	DLinkedList *list = new DLinkedList();
	scanf("%d", &N); getchar();
	while (N--) {
		fgets(buf, 30, stdin);
		char *token[2] = { NULL };
		char *temp = strdup(buf);
		token[0] = strtok(temp, " \n");
		token[1] = strtok(NULL, " \n");

		if (token[1] != NULL) {
			int value = ctoi(token[1]);
			if (strcmp(token[0], "push_back") == 0) {
				list->insert_back(value);
			}
			else if (strcmp(token[0], "push_front") == 0) {
				list->insert_front(value);
			}
		}
		else {
			if (strcmp(token[0], "pop_front") == 0) {
				if (!list->empty()) {
					int ret = list->delete_front();
					printf("%d\n", ret);
				}
				else {
					printf("-1\n");
				}
			}
			else if (strcmp(token[0], "pop_back") == 0) {
				if (!list->empty()) {
					int ret = list->delete_back();
					printf("%d\n", ret);
				}
				else {
					printf("-1\n");
				}
			}
			else if (strcmp(token[0], "size") == 0) {
				printf("%d\n", list->size());
			}
			else if (strcmp(token[0], "empty") == 0) {
				if (list->empty()) printf("1\n");
				else printf("0\n");
			}
			else if (strcmp(token[0], "front") == 0) {
				Node *temp = list->iter_front();
				if (temp == NULL) printf("-1\n");
				else printf("%d\n", temp->value);
			}
			else if (strcmp(token[0], "back") == 0) {
				Node *temp = list->iter_back();
				if (temp == NULL) printf("-1\n");
				else printf("%d\n", temp->value);
			}
		}
	}
}