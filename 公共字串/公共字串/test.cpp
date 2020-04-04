#include<iostream>
#include<string>
using namespace std;
int main() {
	int i;
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	char a[256] = { 0 };
	for (i = 0; i < s2.size(); i++) {
		a[s2[i]]++;
	}
	//string ret;
	//for (i = 0; i < s1.size(); i++) {
	//	if (a[s1[i]] == 0) {
	//		ret.push_back(s1[i]);
	//	}
	//}
	string::iterator it = s1.begin();
	while(it!=s1.end()) {
		if (a[*it] == 1) {
			it=s1.erase(it);
		}
		else {
			++it;
		}
	}
	cout << s1;
	return 0;
}