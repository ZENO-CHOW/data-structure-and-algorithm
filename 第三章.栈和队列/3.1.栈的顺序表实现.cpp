#include <iostream>

using namespace std;

template <typename T>
class SQstack {
	T* data;
	int top, size;
public:
	SQstack(int n) {
		data = new T[n];
		if (!data) throw "À≥–Ú’ª≥ı ºªØ ß∞‹";
		size = n;
		top = -1;
	}
	bool Push_back(T elem) {
		if (top == size - 1) {
			T* v = new T[2 * size];
			for (int i = 0; i < size; i++) v[i] = data[i];
			size *= 2;
			delete[] data;
			data = v;
		}
		top += 1;
		data[top] = elem;
		return true;
	}

	bool Pop_back() {
		if (top == -1) return false;
		top -= 1;
		return true;
	}

	T& Top() {
		if (top == -1) throw "’ªŒ™ø’";
		T elem = data[top];
		return elem;
	}

	int Count() {
		return top + 1;
	}

	bool Empty_list() {
		return top == -1;
	}

	bool Clear() {
		top = -1;
		return true;
	}

	~SQstack() {
		delete[]data;
	}
};

int main() {
	SQstack<int> list(3);
	list.Push_back(3);
	list.Push_back(4);
	list.Push_back(5);
	list.Push_back(6);
	cout << list.Count() << endl;
	while (!(list.Empty_list())) {
		cout << list.Top() << "  ";
		list.Pop_back();
	}
	cout << endl;
	cout << list.Count() << endl;
	list.Push_back(7);
	cout << list.Top() << endl;
	cout << list.Count() << endl;
	list.Clear();
	cout << list.Count() << endl;
}