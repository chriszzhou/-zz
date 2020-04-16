#include<iostream>
#include<vector>
#include <algorithm>
#include<stack>
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		//��ջ�ͳ�ջ��Ԫ�ظ���������ͬ
		if (pushV.size() != popV.size())
			return false;

		// ��s��ģ����ջ���ջ�Ĺ���
		int outIdx = 0;
		int inIdx = 0;
		stack<int> s;

		while (outIdx < popV.size())
		{
			// ���s�ǿգ�����ջ��Ԫ�����ջ��Ԫ�ز���ȣ�����ջ
			while (s.empty() || s.top() != popV[outIdx])
			{
				if (inIdx < pushV.size())
					s.push(pushV[inIdx++]);
				else
					return false;
			}

			// ջ��Ԫ�����ջ��Ԫ����ȣ���ջ
			s.pop();
			outIdx++;
		}

		return true;
	}
};
int  main() {
	Solution s;
	vector<int> a1;
	a1.push_back(5);
	a1.push_back(4);
	a1.push_back(3);
	a1.push_back(2);
	a1.push_back(1);
	vector<int> a2(a1);
	reverse(a2.begin(),a2.end());
	a1[1] = 5;
	a1[0] = 4;
	cout<<s.IsPopOrder(a2,a1)<<endl;
	return 0;
}