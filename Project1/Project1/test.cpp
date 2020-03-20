#include<iostream>
using namespace std;
void strinsert(int*a, int size) {
	int i, j, cur;
	for (i = 1; i < size; i++) {
		if (a[i] < a[i - 1]) {
			cur = a[i];
			for (j = i - 1; j >= 0 && a[j] > cur; j--) {
				a[j + 1] = a[j];
			}
			a[j + 1] = cur;
		}
	}
}
void shell(int *a, int size, int d) {
	int i, j, cur;
	for (i = d; i < size; i++) {
		if (a[i] < a[i - d]) {
			cur = a[i];
			for (j = i - d; j >= 0 && a[j] > cur; j -= d) {
				a[j + d] = a[j];
			}
			a[j + d] = cur;
		}
	}
}
void shellsort(int *a, int size) {
	for (int i = size / 2; i >= 1; i /= 2) {
		shell(a, size, i);
	}
}
void msort(int*a, int size) {
	int i, j;
	int flag = 0;
	for (i = 0; i < size - 1; i--) {
		flag = 0;
		for (j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				flag++;
			}
		}
		if (flag == 0)
			break;
	}
}
void ssort(int *a, int size) {
	int i, j, min;
	for (i = 0; i < size; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (a[min] != a[i]) {
			swap(a[i], a[min]);
		}
	}
}
int partation(int* a, int left, int right) {
	int cur = a[left];
	while (left < right) {
		while (left < right&&cur <= a[right]) {
			right--;
		}
		a[left] = a[right];
		while (left < right&&cur >= a[left]) {
			left++;
		}
		a[right] = a[left];
	}
	a[left] = cur;
	return left;
}
void quicksort(int *a, int left, int right) {
	if (left < right) {
		int middle = partation(a, left, right);
		quicksort(a, left, middle - 1);
		quicksort(a, middle + 1, right);
	}
}
int main() {
	int a[10];
	for (auto& e : a) {
		cin >> e;
	}
	for (auto e : a) {
		cout << e << "  ";
	}
	cout << endl;
	strinsert(a, 10);
	for (auto e : a) {
		cout << e << "  ";
	}
	cout << endl;
	shellsort(a, 10);
	for (auto e : a) {
		cout << e << "  ";
	}
	cout << endl;
	msort(a, 10);
	for (auto e : a) {
		cout << e << "  ";
	}
	cout << endl;
	ssort(a, 10);
	for (auto e : a) {
		cout << e << "  ";
	}
	cout << endl;
	quicksort(a, 0, 9);
	for (auto e : a) {
		cout << e << "  ";
	}
	cout << endl;
}