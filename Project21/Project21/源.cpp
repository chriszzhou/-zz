#include<vector>
#include<queue>

#include<iostream>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 class Solution {
 public:
	 vector<vector<int>> levelOrder(TreeNode* root) {
		 if (root==NULL) {
			 return {};
		 }
		 queue<TreeNode> s;
		 s.push(*root);
		 vector<vector<int>>  vv;
		 vector<int>  v;
		 while (!s.empty()) {
			 int n = s.size();
			 while (n) {
				 v.push_back(s.front().val);
				 if (s.front().left != NULL)
					 s.push(*(s.front().left));
				 if (s.front().right!= NULL)
					 s.push(*(s.front().right));
				 s.pop();
				 n--;
			 }
			 vv.push_back(v);
			 v.clear();
		 }
		 reverse(vv);
		 return vv;
	 }
 };
int main()
{
	Solution s;
	//struct TreeNode t(3);
	//struct TreeNode t1(9);
	//struct TreeNode t2(20);
	//struct TreeNode t3(15);
	//struct TreeNode t4(7);
	//t.left = &t1;
	//t.right = &t2;
	//t2.left = &t3;
	//t2.right = &t4;
	struct TreeNode t(1);
	struct TreeNode t1(2);
	t.left = &t1;
	s.levelOrder(&t);
	return 0;
}