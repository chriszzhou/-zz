#include<iostream>
using namespace std;
#define SIZE 10
class Node {
public:
	int date;
	Node * ptr;
};
class sList {
public:
	sList(int a)
	{
		head = new Node;
		head->ptr = NULL;
		head->date = a;
	}
	~sList() {
		Node *p;
		while (head) {
			p = head;
			head = head->ptr;
			delete p;
		}
		head = NULL;

	}
	void pushfront(int  a) {
		Node * jd = new Node;
		jd->date = a;
		jd->ptr = head;
		head = jd;
	}
	void popfront() {
		if (head == NULL) {
			return;
		}
		else if (head->ptr == NULL) {
			delete head;
			head = NULL;
		}
		else {
			Node* temp = head;
			head = head->ptr;
			delete temp;
			temp = NULL;
		}
	}
	Node*  find(int  a) {
		Node* temp = head;
		while (temp->date != a && temp->ptr != NULL) {
			temp=temp->ptr;
			if (temp->date == a) {
				return temp;
		}
		}
	}
	void earse(int a) {
		if (head->date == a) {
			popfront();
		}
		Node* temp = head;
		if (temp->ptr != NULL) {
			while (temp->ptr->ptr != NULL) {
				if (temp->ptr->date == a) {
					temp->ptr = temp->ptr->ptr;
				}
				temp = temp->ptr;
			}
		}
	}
	void print() {
		Node* temp = head;
		while (temp->ptr != NULL) {
			cout << temp->date << "->";
			temp = temp->ptr;
		}
		cout <<temp->date<< endl;
		return ;
	}
private:
	Node * head;
};
int main() {
	sList a1(5);
	return 0;
}
