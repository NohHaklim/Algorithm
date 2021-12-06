#include <iostream>
#include <cstdio>

using namespace std;

template <typename T>
class MinHeap {
private:
	int _sz;
	T *heapArr;

	int min(int a, int b) {
		return a < b ? a : b;
	}

public:
	MinHeap(int n) {
		_sz = 0;
		heapArr = new int[n + 1];
	}
	~MinHeap() {
		delete[] heapArr;
	}

	int empty() {
		return !_sz;
	}
	int size() {
		return _sz;
	}
	T top() {
		return !_sz ? -1 : heapArr[1];
	}

	void push(int val) {
		int i;
		i = ++_sz;

		while ((i != 1) && (val < heapArr[i / 2])) {
			heapArr[i] = heapArr[i / 2];
			i /= 2;
		}
		heapArr[i] = val;
	}

	void pop() {
		int parent, child;
		int temp = heapArr[_sz--];

		parent = 1; child = 2;
		while (child <= _sz) {
			if (child < _sz && heapArr[child] > heapArr[child + 1])
				child++;
			if (temp < heapArr[child])
				break;
			heapArr[parent] = heapArr[child];
			parent = child;
			child = parent * 2;
		}
		heapArr[parent] = temp;
	}
};

int main()
{
	int size;
	cin >> size;
	MinHeap<int> pq(size);

	int arr[] = { 2,4,11,12,8,10,14,12,20 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		pq.push(arr[i]);

	pq.push(30);
	pq.push(15);

	pq.pop();
	pq.pop();

	cout << "최종적으로 min_heap에서의 root 값 :: " << pq.top() << endl;

	return 0;
}