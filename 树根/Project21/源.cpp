#include<vector>
#include<queue>
#include<string>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 class Solution {
 public:
	 int nums(int n) {
		 int x = 0;
		 char ch[20];
		 itoa(n, ch, 10);
		 string s(ch);
		 while (x == 0 || x>10) {
			 int n = s.size();
			 for (int i = 0; i < n; i++) {
				 x += s[i]-48;
			 }
			 if (x < 10)
				 return x;
			 itoa(x, ch, 10);
			 s=ch;
			 x = 0;
		 }
		 return 0;
	 }
 };
int main()
{
	string nss;
	cin >> nss;
	int num;
	Solution s;
	while (cin >> num) {
		cout<<s.nums(num)<<endl;
	}
	return 0;
}