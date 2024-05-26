#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Lklist {
	struct Lnode{
		T data;
		Lnode* next;
	};
	Lnode* rear;
public:
	Lklist() {
		rear = new Lnode();
		rear->next = rear;
	}

	bool get(int i, T& e) {
		if (i <= 0) {
			cout << "´íÎóÎ»ÖÃÊäÈë" << endl;
			return false;
		}
		Lnode* p = rear;
		int j = -1;
		while(p && j < i ) {
			p = p->next;
			j++;
		}
		if (!p) {
			cout << "´íÎóÎ»ÖÃÊäÈë" << endl;
			return false;
		}
		e = p->data;
		return true;
	}

	bool Set(int i, T elem) {
		if (i <= 0) {
			cout << "´íÎóÎ»ÖÃÊäÈë" << endl;
			return false;
		}
		Lnode* p = rear;
		int j = -1;
		while (p && j < i) {
			p = p->next;
			j++;
		}
		if (!p) {
			cout << "´íÎóÎ»ÖÃÊäÈë" << endl;
			return false;
		}
		p->data = elem;
		return true;
	}

	bool Insert(int i, T elem) {
		if (i <= 0) {
			cout << "²åÈëÎ»ÖÃ´íÎó" << endl;
			return false;
		}
		int j = 0;
		Lnode* p = rear;
		while (p && j < i) {
			p = p->next;
			j++;
		}
		if (!p) {
			cout << "²åÈëÎ»ÖÃ´íÎó" << endl;
			return false;
		}
		Lnode* node = new Lnode();
		if (!node) {
			cout << "½Úµã´´½¨Ê§°Ü" << endl;
			return false;
		}
		node->data = elem;
		node->next = p->next;
		p->next = node;
		return true;
	}

	bool Insert_front(T elem) {
		Lnode* node = new Lnode();
		if (!node) {
			cout << "½Úµã´´½¨Ê§°Ü" << endl;
			return false;
		}
		node->data = elem;
		node->next = rear->next->next;
		rear->next->next = node;
		return true;
	}

	bool Remove(int i) {
		if (i <= 0) {
			cout << "ÒÆ³ýÎ»ÖÃ´íÎó" << endl;
			return false;
		}
		Lnode* p = rear;
		int j = 0;
		while (p && j < i) {
			p = p->next;
			j++;
		}
		if (!(p->next)) {
			cout << "ÒÆ³ýÎ»ÖÃ´íÎó" << endl;
			return false;
		}
		Lnode* node = p->next;
		p->next = node->next;
		delete node;
		return true;
	}

	bool Remove_front() {
		Lnode* p = rear->next->next;
		rear->next->next = p->next;
		delete p;
		return true;
	}

	bool Push_back(T elem) {
		Lnode* node = new Lnode(), *p = rear;
		if (!node) {
			cout << "½Úµã´´½¨Ê§°Ü" << endl;
			return false;
		}
		node->data = elem;
		node->next = p->next;
		p->next = node;
		rear = node;
		return true;
	}

	bool Pop_back(T& elem) {
		Lnode* p = rear, *q;
		elem = rear->data;
		while (p->next != rear) {
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		rear = p;
		delete q;
		return true;
	}
	
	void Traverse(void (*Function) (T& elem)) {
		Lnode* p = rear->next->next;
		while (p != rear) {
			Function(p->data);
			p = p->next;
		}
		cout << endl;
		return;
	}
};

template <typename T>
void print(T& elem) {
	cout << elem << " ";
	return;
}

int main()
{
	Lklist<char> list;
	list.Insert_front('E');
	list.Insert_front('D');
	list.Insert_front('C');
	list.Insert_front('B');
	list.Insert_front('A');
	list.Push_back('F');
	list.Insert(3, 'M');
	list.Traverse(print);
	char n;
	list.get(2, n);
	cout << n << endl;
	list.Pop_back(n);
	cout << n << endl;
	list.Traverse(print);
	list.Remove(4);
	list.Traverse(print);
	list.Remove_front();
	list.Traverse(print);
	list.Set(3, 'K');
	list.Traverse(print);

	Lklist<string> list2;
	list2.Insert_front("zeno");
	list2.Insert_front("jacy");
	list2.Insert_front("tim");
	list2.Insert_front("jony");
	list2.Insert_front("sam");
	list2.Insert_front("lisa");
	list2.Traverse(print);

	return 0;
}
