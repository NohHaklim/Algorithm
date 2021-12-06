/*
	unordered_map
		: hash table�� bucket�� Ȱ���ϴ� ����.
		1. ���� �ڷḦ �����ϰ�, �˻��� ����� �Ѵ�.
		2. �ڷ��� ����, ������ ����� �Ѵ�.

		begin		ù ��° ������ ���� ���� �ݺ��ڸ� ��ȯ
		clear		������ ��� ���Ҹ� ����
		empty		������ ��Ұ� ������ true ��ȯ
		end			������ ���� ������(�� ��� ����) �ݺ��ڸ� ��ȯ
		erase		Ư�� ��ġ�� ���ҳ� ���� ������ ���ҵ��� ����
		find		Key�� ������ ������ �ݺ��� ��ȯ, ������ end ��ġ ����
		insert		���� �߰�
		lower_bound	������ Key�� ��Ұ� �ִٸ� �ش� ��ġ�� �ݺ��ڸ� ��ȯ
		rbegin		���������� ù ��° ������ �ݺ��ڸ� ��ȯ
		rend		���������� ������ ���� ������ �ݺ��ڸ� ��ȯ
		size		������ ������ ��ȯ
		upper_bound	������ Key ��Ұ� �ִٸ� �ش� ��ġ ���� ��ġ�� �ݺ��� ��ȯ
*/

#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<int, float> h1, h2;
	h1.insert(unordered_map<int, float>::value_type(3, 45.6f));
	h1.insert(h1.begin(), unordered_map<int, float>::value_type(1, 50.4f));
	h1.insert(unordered_map<int, float>::value_type(0, 30.2f));
	h1.insert(unordered_map<int, float>::value_type(2, 25.1f));
	h2.insert(h1.begin(), h1.end());

	for (int i = 0; i < h1.size(); i++)
		cout << h1[i] << " ";
	cout << endl;

	unordered_map<int, float>::iterator iter;
	for (iter = h2.begin(); iter != h2.end(); iter++)
		printf("(%d, %.1f)\n", iter->first, iter->second);

	cout << endl << "1:    " << h1[1] << endl;
	cout << endl << "lower_bound(1)" << endl;
	iter = h1.lower_bound(1);
	while (iter != h1.end()) {
		cout << iter->second << " ";
		iter++;
	}

	cout << endl << endl << "upper_bound(1)" << endl;
	iter = h1.upper_bound(1);
	while (iter != h1.end()) {
		cout << iter->second << " ";
		iter++;
	}

	cout << endl << endl;

	iter = h1.find(4);
	if (iter == h1.end())
		printf("%u", iter);
	
	return -1;
}