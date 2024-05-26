#include <iostream>
#include <string>

using namespace std;
#define MAX_OP 3

template <typename T>
class SqList {
	T* data;
	int n, count;
public:
	//构造函数初始化顺序表
	SqList(int cap) {
		data = new T[cap];
		if (!data) throw "SqList内存分配失败";
		n = cap;
		count = 0;
	}

	//i表示位置，获取该位置的元素内容
	bool Get(int i, T& elem) {
		if (i < 0 || i >= count) return false;
		elem = data[i];
		return true;
	}

	//i表示位置，修改该位置的元素内容
	bool Set(int i, T elem) {
		if (i < 0 || i >= count) return false;
		data[i] = elem;
		return true;
	}


	//向i位置插入一个值
	bool Insert(int i, T elem) {
		if (i < 0 || i > count) return false;
		if (count == n && !realloc()) return false;
		#if 0
		for (int j = count - 1; j >= i; j--) {
			data[j + 1] = data[j];
		}
		data[i] = elem;
		#else 
		//使用指针进行遍历
		T* p = data + i;
		for (T* q = data + count - 1; q >= p; q--) *(q + 1) = *q;
		*p = elem;
		#endif
		count++;
		return true;
	}

	//移除i位置的元素
	bool Remove(int i) {
		if (i < 0 || i > count - 1) return false;
		#if 0
		for (int j = i; j < count - 1; j++) {
			data[j] = data[j + 1];
		}
		#else
		//使用指针进行遍历
		T* p = data + count - 1;
		for (T* q = data + i; q < p; q++) *q = *(q + 1);
		#endif
		count--;
		return true;
	}

	//向顺序表末尾插入一个新的元素
	bool Push_Back(T elem) {
		if (count == n && !realloc()) return false;
		data[count] = elem;
		count++;
		return true;
	}

	//移除顺序表末尾的一个元素
	bool Pop_Back() {
		if (count == 0) return false;
		data[count - 1] = 0;
		count--;
		return true;
	}

	//移除顺序表的第一个元素
	bool Remove_Front() {
		T* p = data + count - 1;
		for (T* q = data; q < p; q++) *q = *(q + 1);
		count--;
		return true;
	}

	//从pos位置查找相同元素
	int Find(int pos, bool (*Function) (T& sqlistelem, T elem), T val) {
		if (count == 0) return -1;
		for (int j = pos; j < count; j++) {
			if (Function(data[j], val)) {
				return j;
			}
		}
		return -1;
	}
	//使用函数指针遍历操作顺序表中的每一个元素
	void Traverse(void (*Function)(T& elem)) {
		for (int i = 0; i < count; i++) {
			Function(data[i]);
		}
		cout << endl;
	}

	//返回当前顺序表的元素个数
	int size() { return count; }

private:
	//顺序表内存不足时，为顺序表自动扩大空间
	bool realloc() {
		T* p = new T[2 * n];
		if (!p) {
			cout << "内存分配异常" << endl;
			return false;
		}
		for (int i = 0; i < n; i++) p[i] = data[i];
		delete[] data;
		data = p;
		n *= 2;
		return true;
	}
};

template <typename T>
void Print(T& elem) {
	cout << elem << " ";
	return;
}

template <typename T>
void Converse(T& elem) {
	if (elem >= 'A' || elem <= 'Z') elem += ('a' - 'A');
	return;
}

template <typename T>
bool Equel(T& sqlistelem, T elem) {
	if (sqlistelem == elem) return true;
	return false;
}

template <typename T>
bool Lager(T& sqlistelem, T elem) {
	if (sqlistelem > elem) return true;
	return false;
}

template <typename T>
bool Smaller(T& sqlistelem, T elem) {
	if (sqlistelem < elem) return true;
	return false;
}

struct Student {
	string name;
	int score;
	Student(string n = "no name", int m = 0) : name(n), score(m) {}
};

ostream& operator<<(ostream& mycout, const Student& elem) {
	mycout << endl;
	mycout << "student's name : " << elem.name << endl;
	mycout << "student's score : " << elem.score << endl;
	return mycout;
}

int main()
{
	#if 0;
	SqList<char> list(MAX_OP);
	char ch;
	list.Push_Back('A');
	list.Traverse(Print);
	list.Push_Back('B');
	list.Traverse(Print);
	list.Push_Back('C');
	list.Traverse(Print);
	list.Push_Back('D');//为重新扩容时，该值插入失败
	list.Traverse(Print);
	if (!list.Get(1, ch)) cout << "未获取该位置的数据" << endl;
	else cout << ch << endl;
	list.Set(1, 'C');
	list.Traverse(Print);
	list.Insert(2, 'E');
	list.Traverse(Print);
	list.Remove(3);
	list.Traverse(Print);
	list.Pop_Back();
	list.Traverse(Print);
	list.Remove_Front();
	list.Traverse(Print);
	list.Push_Back('E');
	list.Set(2, 'C');
	list.Push_Back('E');
	list.Traverse(Print);

	for (int i = 0; i < list.size(); i++) {
		int j = list.Find(i, Equel, 'E');
		if (j != -1) {
			i = j;
			cout << "第 " << j << " 个元素与该值相同\n";
		}
	}
	cout << endl;
	for (int i = 0; i < list.size(); i++) {
		int j = list.Find(i, Smaller, 'E');
		if (j != -1) {
			i = j;
			cout << "第 " << j << " 个元素小于该值\n";
		}
	}
	list.Traverse(Converse);
	list.Traverse(Print);

	for (int i = 0; i < list.size(); i++) {
		int j = list.Find(i, Lager, 'E');
		if (j != -1) {
			i = j;
			cout << "第 " << j << " 个元素大于该值\n";
		}
	}
	#endif

	SqList<int> listint(MAX_OP);
	listint.Push_Back(16);
	listint.Push_Back(26);
	listint.Push_Back(36);
	listint.Push_Back(46);
	listint.Push_Back(56);
	listint.Traverse(Print);

	SqList<Student> students(MAX_OP);
	students.Push_Back(Student("zeno", 100));
	students.Push_Back(Student("lisa", 90));
	students.Push_Back(Student("jacy", 60));
	students.Traverse(Print);

	return 0;
}
