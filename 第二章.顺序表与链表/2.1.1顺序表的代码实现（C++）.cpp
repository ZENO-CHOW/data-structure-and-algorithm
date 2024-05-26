#include <iostream>
#include <string>

using namespace std;
#define MAX_OP 3

template <typename T>
class SqList {
	T* data;
	int n, count;
public:
	//���캯����ʼ��˳���
	SqList(int cap) {
		data = new T[cap];
		if (!data) throw "SqList�ڴ����ʧ��";
		n = cap;
		count = 0;
	}

	//i��ʾλ�ã���ȡ��λ�õ�Ԫ������
	bool Get(int i, T& elem) {
		if (i < 0 || i >= count) return false;
		elem = data[i];
		return true;
	}

	//i��ʾλ�ã��޸ĸ�λ�õ�Ԫ������
	bool Set(int i, T elem) {
		if (i < 0 || i >= count) return false;
		data[i] = elem;
		return true;
	}


	//��iλ�ò���һ��ֵ
	bool Insert(int i, T elem) {
		if (i < 0 || i > count) return false;
		if (count == n && !realloc()) return false;
		#if 0
		for (int j = count - 1; j >= i; j--) {
			data[j + 1] = data[j];
		}
		data[i] = elem;
		#else 
		//ʹ��ָ����б���
		T* p = data + i;
		for (T* q = data + count - 1; q >= p; q--) *(q + 1) = *q;
		*p = elem;
		#endif
		count++;
		return true;
	}

	//�Ƴ�iλ�õ�Ԫ��
	bool Remove(int i) {
		if (i < 0 || i > count - 1) return false;
		#if 0
		for (int j = i; j < count - 1; j++) {
			data[j] = data[j + 1];
		}
		#else
		//ʹ��ָ����б���
		T* p = data + count - 1;
		for (T* q = data + i; q < p; q++) *q = *(q + 1);
		#endif
		count--;
		return true;
	}

	//��˳���ĩβ����һ���µ�Ԫ��
	bool Push_Back(T elem) {
		if (count == n && !realloc()) return false;
		data[count] = elem;
		count++;
		return true;
	}

	//�Ƴ�˳���ĩβ��һ��Ԫ��
	bool Pop_Back() {
		if (count == 0) return false;
		data[count - 1] = 0;
		count--;
		return true;
	}

	//�Ƴ�˳���ĵ�һ��Ԫ��
	bool Remove_Front() {
		T* p = data + count - 1;
		for (T* q = data; q < p; q++) *q = *(q + 1);
		count--;
		return true;
	}

	//��posλ�ò�����ͬԪ��
	int Find(int pos, bool (*Function) (T& sqlistelem, T elem), T val) {
		if (count == 0) return -1;
		for (int j = pos; j < count; j++) {
			if (Function(data[j], val)) {
				return j;
			}
		}
		return -1;
	}
	//ʹ�ú���ָ���������˳����е�ÿһ��Ԫ��
	void Traverse(void (*Function)(T& elem)) {
		for (int i = 0; i < count; i++) {
			Function(data[i]);
		}
		cout << endl;
	}

	//���ص�ǰ˳����Ԫ�ظ���
	int size() { return count; }

private:
	//˳����ڴ治��ʱ��Ϊ˳����Զ�����ռ�
	bool realloc() {
		T* p = new T[2 * n];
		if (!p) {
			cout << "�ڴ�����쳣" << endl;
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
	list.Push_Back('D');//Ϊ��������ʱ����ֵ����ʧ��
	list.Traverse(Print);
	if (!list.Get(1, ch)) cout << "δ��ȡ��λ�õ�����" << endl;
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
			cout << "�� " << j << " ��Ԫ�����ֵ��ͬ\n";
		}
	}
	cout << endl;
	for (int i = 0; i < list.size(); i++) {
		int j = list.Find(i, Smaller, 'E');
		if (j != -1) {
			i = j;
			cout << "�� " << j << " ��Ԫ��С�ڸ�ֵ\n";
		}
	}
	list.Traverse(Converse);
	list.Traverse(Print);

	for (int i = 0; i < list.size(); i++) {
		int j = list.Find(i, Lager, 'E');
		if (j != -1) {
			i = j;
			cout << "�� " << j << " ��Ԫ�ش��ڸ�ֵ\n";
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
