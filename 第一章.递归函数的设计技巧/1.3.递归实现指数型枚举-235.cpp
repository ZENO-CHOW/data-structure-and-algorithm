#include <iostream>

using namespace std;

int arry[10];

void print_one_result(int n) {
    //ʵ�ֶ�������ض��±�ķ�Χ������Ԫ�ش�ӡ
    for (int i = 0; i <= n; i++) {
        if (i) cout << " ";
        cout << arry[i];
    }
    cout << endl;
    return;
}

void f(int i, int j, int n) {
    if (j > n) return;   //�߽�����
    //��iλ��������Сjֵ
    for (int k = j; k <= n; k++) {
        arry[i] = k;
        //ÿ����һ��ֵ���ӡ���һ��
        print_one_result(i);
        //����iλ�ú��i+1λ�õ���д
        f(i + 1, k + 1, n);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    f(0, 1, n);
    return 0;
}
