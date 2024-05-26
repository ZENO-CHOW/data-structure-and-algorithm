#include <iostream>

using namespace std;

#define MAX_OP 20

struct Node {
	int data;
	Node* next;
};


//��ʼ������
Node* GetNewNode(int val) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p != NULL) {
		p->data = val;
		p->next = NULL;
		return p;
	}
	return p;
}

//����ṹ�Ĳ������������ֵΪ�����ͷָ��
Node* Insert(Node* head, int pos, int val) {
	//�����½ڵ�
	Node* p = GetNewNode(val);

	if (pos == 0) {
		p->next = head;
		return p;
	}
	//����ͷָ�����������pos-1λ�ýڵ�
	Node* p1 = head;
	for (int i = 1; i < pos; i++) p1 = p1->next;
	p->next = p1->next;
	p1->next = p;
	return head;
}

//����ṹ��ɾ������������ֵΪ�����ͷָ��
Node* LinkList_Delete(Node* head, int pos) {
	Node* p;
	if (pos == 0) {
		p = head->next;
		free(head);
		return p;
	}
	//����ͷָ�����������pos-1λ�ýڵ�
	Node* p1 = head;
	for (int i = 1; i < pos; i++) p1 = p1->next;
	p = p1->next->next;
	free(p1->next);
	p1->next = p;
	return head;
}

//��������
void Clear(Node* head) {
	if (head == NULL) return;
	for (Node* p = head, *q; p; p = q) {
		q = p->next;
		free(p);
	}
	return;
}

//�������������
void Output_Linklist(Node* head) {
	if (head == NULL) return;
	int len = 0;
	for (Node* p1 = head; p1; p1 = p1->next) {
		if (len < 10) cout << len << "  |";
		else cout << len << " |";
		len++;
	}
	cout << endl;
	for (int i = 0; i < len; i++) {
		cout << "----";
	}
	cout << endl;
	for (Node* p = head; p; p = p->next) {
		if (p->data < 10) cout << p->data << "   ";
		else cout << p->data << "  ";
	}
	cout << "\n\n";
}

//��������������
void LinkList_Find(Node* head, int val) {
	if (head == NULL) {
		cout << "����Ϊ������\n";
		return;
	}
	Output_Linklist(head);
	int i = 0, len = 0, findinf[MAX_OP];
	for (Node* p = head; p; p = p->next) {
		if (p->data == val) {
			cout << "^   ";
			i++;
			findinf[len] = 1;
		}
		else cout << "    ";
		len++;
	}
	cout << endl;
	for (int j : findinf) {
		if (j == 1) cout << "|   ";
		else cout << "    ";
	}
	cout << endl;
	cout << "���ҵ� " << i << " ��";
	cout << endl;
	return;
}

int main()
{
	srand(time(0));
	Node* head = NULL;
	for (int i = 0; i < MAX_OP; i++) {
		int pos = rand() % (i + 1), val = rand() % 100;
		cout << "( " << i << " ) insert " << val << " at " << pos << " to linklist\n";
		head = Insert(head, pos, val);
		Output_Linklist(head);
	}

	LinkList_Find(head, 7);
	LinkList_Delete(head, 7);
	cout << endl;
	Output_Linklist(head);

	Clear(head);

	return 0;
}
