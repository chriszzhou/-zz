#include <vector>
#include <queue>
#include <stack>
#include<iostream>
using namespace std;
template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;

	BinaryTreeNode(const T& x)
		: _data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};


template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree(T *a, size_t n, const T& invalid)
	{
		size_t index = 0;
		_root = _CreateTree(a, n, invalid, index);
	}

	Node CopyTree(Node* root)
	{
		if (root == NULL)
			return NULL;
		Node* newRoot = new Node(root->_data);
		newRoot->_left = CopyTree(root->_left);
		newRoot->_right = CopyTree(root->_right);

		return newRoot;
	}

	BinaryTree(const BinaryTree<T>& t)
	{
		_root = CopyTree(t._root);
	}

	BinaryTree operator=(BinaryTree<T> t)
	{
		swap(_root, t._root);

		return *this;
	}

	~BinaryTree()
	{
		Destory(_root);
		_root = NULL;
	}

	void Destory(Node* root)
	{
		if (root == NULL)
			return;
		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}

	//前序遍历建树
	Node* _CreateTree(T* a, size_t n, const T& invalid, size_t& index)
	{
		Node* root = NULL;
		if (a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _CreateTree(a, n, invalid, ++index);
			root->_right = _CreateTree(a, n, invalid, ++index);
		}
		return root;
	}

	/*Node* _CirculeCreateTree(T* a, size_t n, const T& invalid, size_t index)
	{
		Node* root = NULL;

		while (a[index] != invalid)
		{
			root = new Node(a[index]);

			root->_left = root;
			index++;
		}
		index++;
	}*/

	//前序遍历访问树

	void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}

	void _PrevOrder(Node* root)
	{
		if (root == NULL)
			return;

		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}

	//中序遍历访问树

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}

	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}

	void _PostOrder(Node* root)
	{
		if (root == NULL)
			return;

		_PostOrder(root->_left);
		_PostOrder(root->_right);

		cout << root->_data << " ";

	}
	//递归实现求二叉树的大小
	int Size()
	{
		size_t size = 0;
		Size(_root, size);
		return size;
	}


	void _Size(Node* root, size_t& size)
	{
		if (root == NULL)
			return;
		_Size(root->_left, size);
		++size;
		_Size(root->_right, size);
	}
	//求所有叶子节点的数量
	size_t LeafSize()
	{
		return _LeafSize(_root);
	}

	size_t _LeafSize(Node* root)
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL && root->_right == NULL)
			return 1;
		return _LeafSize(root->_left) + _LeafSize(root->_right);

	}
	//求树的高度
	size_t Height()
	{
		return _Height(_root);
	}

	size_t _Height(Node* root)
	{
		if (root == NULL)
			return 0;

		size_t leftHeight = _Height(root->_left);
		size_t rightHeight = _Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

	}

	//获取第K层的节点数
	size_t GetKLevel(size_t k)
	{

		size_t Num = _GetKLevel(_root, k);
		cout << Num << endl;
		return Num;
	}

	size_t _GetKLevel(Node* root, size_t k)
	{
		if (root == NULL)
			return 0;
		if (k == 1)
			return 1;
		return _GetKLevel(root->_left, k - 1) + _GetKLevel(root->_right, k - 1);
	}

	//判断是不是完全二叉树
	bool IsCompleteTree()
	{
		queue<Node*> q;

		if (_root)
			q.push(_root);
		bool flag = true;

		while (!q.empty())
		{
			Node* front = q.front();
			q.pop();
			if (front->_left)
			{
				if (flag == false)
					return flag;
				q.push(front->_left);
			}
			else
			{
				flag == false;
			}
			if (front->_right)
			{
				if (flag == false)
					return flag;
				q.push(front->_right);
			}
			else
			{
				flag = false;
			}
		}
		return true;
	}
	//查找指定的节点
	Node* Find(const T& x)
	{
		return _Find(_root, x);
	}

	Node* _Find(Node* root, const T& x)
	{
		if (root == NULL)
			return NULL;
		if (root->_data == x)
			return root;

		Node* cur = _Find(root->_left, x);
		if (cur)
			return cur;
		Node* tem = _Find(root->_right, x);
		if (tem)
			return tem;
		return NULL;
	}

private:
	Node* _root;
};
void TestTree()
{
	int array[] = { 1, 2, 3, '#', '#', 4, 40, '#', '#', '#', 5, 6, '#', '#', '#' };
	BinaryTree<int> t(array, sizeof(array) / sizeof(int), '#');
	t.PrevOrder();
	t.PostOrder();
	t.GetKLevel(1);
	cout << t.Find(44) << endl;
	cout << t.Find(4) << endl;
}
int main() {
	TestTree();
	return 0;
}