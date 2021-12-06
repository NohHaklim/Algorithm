/*
	unordered_map
		: hash table과 bucket을 활용하는 구조.
		1. 많은 자료를 저장하고, 검색이 빨라야 한다.
		2. 자료의 삽입, 삭제가 적어야 한다.

		begin		첫 번째 원소의 랜덤 접근 반복자를 반환
		clear		저장한 모든 원소를 삭제
		empty		저장한 요소가 없으면 true 반환
		end			마지막 원소 다음의(미 사용 영역) 반복자를 반환
		erase		특정 위치의 원소나 지정 범위의 원소들을 삭제
		find		Key와 연관된 원소의 반복자 반환, 없으면 end 위치 리턴
		insert		원소 추가
		lower_bound	지정한 Key의 요소가 있다면 해당 위치의 반복자를 반환
		rbegin		역방향으로 첫 번째 원소의 반복자를 반환
		rend		역방향으로 마지막 원소 다음의 반복자를 반환
		size		원소의 개수를 반환
		upper_bound	지정한 Key 요소가 있다면 해당 위치 다음 위치의 반복자 반환
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