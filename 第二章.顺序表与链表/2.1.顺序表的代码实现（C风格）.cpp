#include <iostream>

using namespace std;

//�������ݱ�
struct Vector {
	int size, count;
	int* data;
};

//˳���ĳ�ʼ��
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

//˳�������ٲ���
void Clear(Vector* v) {
	if (v == NULL) return;
	free(v->data);
	free(v);
	return;
}

//˳�������ݲ���
int Expand(Vector* v) {
	if (v == NULL) return 0;
	cout << "Expand v from " << v->size << " to " << 2 * v->size << endl;
	int* p = (int*)realloc(v->data, sizeof(int) * 2 * v->size);
	if (p == NULL) return 0;
	v->data = p;
	v->size *= 2;
	return 1;
}

//˳���Ĳ������
int Insert(Vector* v, int pos, int val) {
	if (pos < 0 || pos > v->count) return 0;
	if (v->size == v->count && !Expand(v)) {
		return 0;
	}
	//�����ƶ�˳���������
	for (int i = v->count - 1; i >= pos; i--) {
		v->data[i + 1] = v->data[i];
	}
	v->data[pos] = val;
	//���������������
	v->count += 1;
	return 1;
}

//˳����ɾ������
int Erase(Vector* v, int pos) {
	if (pos < 0 || pos >= v->count) return 0;
	int a = v->data[pos];
	//�����ƶ�˳���������
	for (int i = pos; i < v->count - 1; i++) {
		v->data[i] = v->data[i + 1];
	}
	//���������������
	v->count -= 1;
	return 1;
}

//���˳����ڰ���������
void OutPut_Vector(Vector* v) {
	int len = 0;
	//�������0~19���֣�ÿ�����ּ��5���ո�
	for (int i = 0; i < v->size; i++) {
		cout << i << "    ";
		len += 5;//��¼����
	}
	cout << endl;
	for (int i = 0; i < len; i++) cout << "-";
	cout << endl;
	//����������ڴ洢������
	for (int i = 0; i < v->count; i++) {
		cout << v->data[i] << "    ";
	}
	cout << "\n\n\n";

	return;
}

int main()
{
	int m;
	//������Ҫ��˳�����в����Ĵ���
	cin >> m;
	//��˳�������������ɾ���������ܹ���������Ϊ20��
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
			cout << "( " << i << " )" << "insert " << val << " at " << pos << " to Vector = " << Insert(v, pos, val) << endl;  //�����ͬʱ��ɲ������
			OutPut_Vector(v);  //�����Ӧ�������˳�������
			pos += 1;
			break;
		case 3:
			//pos = rand() % (v->count + 2);
			pos -= 1;
			if (pos < 0) pos = 0;
			cout << "( " << i << " )" << "erase item at " << pos << " in Vector = " << Erase(v, pos) << endl;   //�����ͬʱ���ɾ������
			OutPut_Vector(v);   //�����Ӧ�������˳�������
			break;

		}

	}
	Clear(v);

	return 0;
}
