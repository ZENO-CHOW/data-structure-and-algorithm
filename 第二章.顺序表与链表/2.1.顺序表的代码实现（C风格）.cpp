#include <iostream>

using namespace std;

//定义数据表
struct Vector {
	int size, count;
	int* data;
};

//顺序标的初始化
Vector* GetNewVector(int n) {
	Vector* p = (Vector*)malloc(sizeof(Vector));
	if (p != NULL) {
		p->size = n;
		p->count = 0;
		p->data = (int*)malloc(sizeof(int) * n);
		return p;
	}
	return p;
}

//顺序表的销毁操作
void Clear(Vector* v) {
	if (v == NULL) return;
	free(v->data);
	free(v);
	return;
}

//顺序表的扩容操作
int Expand(Vector* v) {
	if (v == NULL) return 0;
	cout << "Expand v from " << v->size << " to " << 2 * v->size << endl;
	int* p = (int*)realloc(v->data, sizeof(int) * 2 * v->size);
	if (p == NULL) return 0;
	v->data = p;
	v->size *= 2;
	return 1;
}

//顺序表的插入操作
int Insert(Vector* v, int pos, int val) {
	if (pos < 0 || pos > v->count) return 0;
	if (v->size == v->count && !Expand(v)) {
		return 0;
	}
	//逆序移动顺序表中数据
	for (int i = v->count - 1; i >= pos; i--) {
		v->data[i + 1] = v->data[i];
	}
	v->data[pos] = val;
	//变更表中数据数量
	v->count += 1;
	return 1;
}

//顺序表的删除操作
int Erase(Vector* v, int pos) {
	if (pos < 0 || pos >= v->count) return 0;
	int a = v->data[pos];
	//逆序移动顺序表中数据
	for (int i = pos; i < v->count - 1; i++) {
		v->data[i] = v->data[i + 1];
	}
	//变更表中数据数量
	v->count -= 1;
	return 1;
}

//输出顺序表内包含的数据
void OutPut_Vector(Vector* v) {
	int len = 0;
	//遍历输出0~19数字，每个数字间隔5个空格
	for (int i = 0; i < v->size; i++) {
		cout << i << "    ";
		len += 5;//记录长度
	}
	cout << endl;
	for (int i = 0; i < len; i++) cout << "-";
	cout << endl;
	//遍历输出表内存储的数据
	for (int i = 0; i < v->count; i++) {
		cout << v->data[i] << "    ";
	}
	cout << "\n\n\n";

	return;
}

int main()
{
	int m;
	//输入想要对顺序表进行操作的次数
	cin >> m;
	//对顺序表作随机插入和删除操作，总共操作次数为20次
	srand(time(0));
	#define MAX_OP 5
	Vector* v = GetNewVector(MAX_OP);
	int pos = 0;
	for (int i = 0; i < m; i++) {
		int op = rand() % 4, val;
		switch (op) {
		case 0:
		case 1:
		case 2:
			//pos = rand() % (v->count + 2);
			val = rand() % 100;
			cout << "( " << i << " )" << "insert " << val << " at " << pos << " to Vector = " << Insert(v, pos, val) << endl;  //输出的同时完成插入操作
			OutPut_Vector(v);  //输出相应操作后的顺序表数据
			pos += 1;
			break;
		case 3:
			//pos = rand() % (v->count + 2);
			pos -= 1;
			if (pos < 0) pos = 0;
			cout << "( " << i << " )" << "erase item at " << pos << " in Vector = " << Erase(v, pos) << endl;   //输出的同时完成删除操作
			OutPut_Vector(v);   //输出相应操作后的顺序表数据
			break;

		}

	}
	Clear(v);

	return 0;
}
