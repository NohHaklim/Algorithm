/*
	1. 최소힙을 구성한다.
	2. 가장 작은 두 수를 뽑아 더한 값을 total에 넣고, 그 수 또한 힙에 다시 넣는다.
	3. 힙에 1개의 수가 남을 때까지 2번을 반복한다.
*/

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

int main() {
	int N, sum = 0;
	scanf("%d", &N);
	MinHeap<int> mh(N);

	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		mh.push(temp);
	}

	while (mh.size() != 1) {
		int a, b;
		a = mh.top(); mh.pop();
		b = mh.top(); mh.pop();
		sum += a + b;
		mh.push(a + b);
	}

	printf("%d", sum);
}