#include <iostream>

using namespace std;

template <typename T>
class LKstack {
	struct Lnode {
		T data;
		Lnode* next;
	};
	Lnode* head;
	int count = 0;
public:
	bool Push(T elem) {
		Lnode* node = new Lnode;
		if (node == NULL) throw "节点创建失败";
		node->data = elem;
		node->next = NULL;
		if (head != NULL) {
			node->next = head;
		}
		head = node;
		count++;
		return true;
	}

	bool Pop() {
		if (head == NULL) return false;
		Lnode* p = head;
		head = p->next;
		delete p;
		count--;
		return true;
	}

	T& Top() {
		if (head == NULL) throw "栈为空";
		T elem = head->data;
		return elem;
	}

	int Count() {
		return count;
	}

	bool Empty_list() {
		return head == NULL;
	}

	~LKstack() {
		while (!Empty_list()) {
			this->Pop();
		}
	}
};

int main() {
	LKstack<int> list;
	list.Push(3);
	list.Push(4);
	list.Push(5);
	cout << list.Count() << endl;
	while (!(list.Empty_list())) {
		cout << list.Top() << "  ";
		list.Pop();
	}
	if (list.Empty_list()) cout << "栈为空";
	cout << endl;
	cout << list.Count() << endl;
}