#include <iostream>

using namespace std;

template <typename T>
class LKlist {
	struct Lnode {
		T data;
		Lnode* next;
	};
	Lnode* head, * rear;
public:
	bool Push_back(T elem) {
		Lnode* node = new Lnode;
		if (!node) return false;
		node->data = elem;
		node->next = NULL;
		if (head == NULL) {
			head = rear = node;
			return true;
		}
		rear->next = node;
		rear = node;
		return true;
	}

	T& Pop_front() {
		if (head == NULL) throw "链表为空";
		T val = head->data;
		Lnode* p = head;
		head = p->next;
		delete p;
		return val;
	}

	T& Seek_elem(int pos) {
		if (pos < 1) throw "位置非法";
		Lnode* p = head;
		int i = 1;
		while (i < pos && p != NULL) {
			p = p->next;
			i++;
		}
		if (p == NULL) throw "位置非法";
		T elem = p->data;
		return elem;
	}

	T& Front_Elem() {
		if (head == NULL) throw "队列为空";
		T elem = head->data;
		return elem;
	}

	T& Last_elem() {
		if (head == NULL) throw "队列为空";
		T elem = rear->data;
		return elem;
	}

	int Count() {
		if (head == NULL) return 0;
		int count = 1;
		Lnode* p = head;
		while (p != rear) {
			p = p->next;
			count++;
		}
		return count;
	}

	bool Empty_list() {
		return head == NULL;
	}

	~LKlist() {
		if (head != NULL) {
			Lnode* p = head, * q;
			while (p != rear) {
				q = p;
				p = p->next;
				delete q;
			}
			delete rear;
		}
	}
};

int main() {
	LKlist<int> list;
	list.Push_back(3);
	list.Push_back(4);
	list.Push_back(5);
	cout << list.Front_Elem() << endl;
	cout << list.Seek_elem(2) << endl;
	cout << list.Last_elem() << endl;
	cout << list.Count() << endl;
	while (!(list.Empty_list())) {
		cout << list.Pop_front() << "  ";
	}
	cout << endl;
	cout << list.Count() << endl;
}