#include <iostream>

using namespace std;

template <typename T>
class SQlist {
	T* data;
	int head, rear, size;
public:
	SQlist(int n) {
		data = new T[n];
		if (!data) throw "内存分配失败";
		size = n;
		head = rear = 0;
	}

	bool Push_back(T elem) {
		if ((rear + 1) % size == head) Reset();
		data[rear] = elem;
		rear = (rear + 1) % size;
		return true;
	}

	T& Pop_back() {
		if (head == rear) throw "队列为空";
		T elem = data[head];
		head = (head + 1) % size;
		return elem;
	}

	T& Seek_elem(int pos) {
		if (pos < 0 || pos >= size) throw "位置非法";
		T elem = data[pos];
		return elem;
	}

	T& Front_Elem() {
		if (head == rear) throw "队列为空";
		T elem = data[head];
		return elem;
	}

	T& Last_elem() {
		if (head == rear) throw "队列为空";
		T elem = data[rear - 1];
		return elem;
	}

	int Count() {
		int count = (rear - head + size) % size;
		return count;
	}

	bool Empty_list() {
		return head == rear;
	}

	bool Reset() {
		T* p = new T[size * 2];
		if (!p) return false;
		for (int i = 0; i < size; i++) {
			p[i] = data[i];
		}
		delete[]data;
		data = p;
		size *= 2;
		return true;
	}

	~SQlist() {
		delete[]data;
	}
};

int main() {
	SQlist<int> list(3);
	list.Push_back(3);
	list.Push_back(4);
	list.Push_back(5);
	cout << list.Front_Elem() << endl;
	cout << list.Seek_elem(1) << endl;
	cout << list.Last_elem() << endl;
	cout << list.Count() << endl;
	while (!(list.Empty_list())) {
		cout << list.Pop_back() << "  ";
	}
	cout << endl;
	cout << list.Count() << endl;
}