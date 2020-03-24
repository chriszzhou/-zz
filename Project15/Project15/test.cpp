#include <iostream>
using namespace std;
#include <vector>
class Solution1 {
public:
	int reverse(int x) {
		int max = 0x7fffffff, min = 0x80000000;
		long sum = 0;
		while (x) {
			sum = sum * 10 + x % 10;
			x /= 10;
		}
		if (sum>max || sum < min)
			return 0;
		return sum;
	}
};
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x == 0)
			return true;
		int a = x;
		int sum = 0, size = 0;
		for (; a; a = a / 10) {
			sum = sum * 10 + a % 10;
			size++;
		}
		for (int i = 1; i <= size; i++) {
			if (sum % 10 != x % 10) {
				return false;
			}
			sum /= 10;
			x /= 10;
		}
		return true;
	}
};
int main()
{
	Solution a;
	//a.reverse(2147483648);
	cout<<a.isPalindrome(2147483647)<<endl;
	return 0;
}
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		vector<int> x(2,0);
//		for (int i = 0; i < nums.size(); i++) {
//			//search(nums,target,i);
//			x[0]=i;
//			for (int j = i + 1; j < nums.size(); j++) {
//				if (nums[j] + nums[i] == target) {
//					x[1]=j;
//					return x;
//				}
//			}
//		}
//	}
//};
//int main() {
//	Solution a;
//	vector<int> nums{1,2,3,4,5};
//	cout << a.twoSum(nums, 9)[0] <<"     "<<a.twoSum(nums, 9)[1]<<endl;
//}