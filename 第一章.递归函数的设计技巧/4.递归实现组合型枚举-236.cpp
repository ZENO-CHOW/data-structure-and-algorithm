#include <iostream>

using namespace std;

int arry[10];

void print_one_result(int m) {
    //ʵ�ֶ�������ض��±�ķ�Χ������Ԫ�ش�ӡ
    for (int i = 0; i < m; i++) {
        if (i) cout << " ";
        cout << arry[i];
    }
    cout << endl;
    return;
}

void f(int i, int j, int n, int m) {
    if (i > m) return;
    //��iλ��������Сjֵ
    for (int k = j; k <= n && m - i - 1 <= n - k; k++) {
        arry[i] = k;
        //����iλ�ú��i+1λ�õ���д
        f(i + 1, k + 1, n, m);
    }
    if (i == m) {
        //ÿ����һ��ֵ���ӡ���һ��
        print_one_result(m);
    }
    return;
}


int main() {
    int n, m;
    cin >> n >> m;

    f(0, 1, n, m);
    return 0;
}
