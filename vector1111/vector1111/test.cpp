#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
	vector<int>::iterator it = nums.begin();
	while (it != nums.end()-1) {
		if (*it == *(it + 1)) {
			it = nums.erase(it);
		}
		else {
			it++;
		}
	}
	return nums.size();
}
int main() {
	vector<int> v1;
	v1.reserve(100);
	vector<int>::iterator it = v1.begin();
	it = v1.insert(it, 10);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(5);
	it = find(it, v1.end(), 2);
	it=v1.erase(it);
	//while (it != v1.end() ) {
	//	if (*it % 2 == 0)
	//		it = v1.erase(it);
	//	else
	//		++it;
	//}
	while (it != v1.end()-1) {
		if (*it == *(it + 1)) {
			it = v1.erase(it);
		}
		else {
			it++;
		}
	}
	cout << v1.size();

	return 0;
}