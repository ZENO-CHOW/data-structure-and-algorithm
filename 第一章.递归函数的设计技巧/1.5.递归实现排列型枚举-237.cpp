#include <iostream>

using namespace std;

int arry[10];
int v[11] = { 0 };

void print_one_result(int n) {
    //ʵ�ֶ�������ض��±�ķ�Χ������Ԫ�ش�ӡ
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << arry[i];
    }
    cout << endl;
    return;
}

void f(int i, int n) {
    if (i == n) {
        //ÿ����һ��ֵ���ӡ���һ��
        print_one_result(n);
        return;
    }
    for (int k = 1; k <= n; k++) {
        if (v[k] == 0) {
            //��iλ��������Сjֵ
            arry[i] = k;
            v[k] = 1;
            //����iλ�ú��i+1λ�õ���д
            f(i + 1, n);
            //����һ�׶κ���������ɺ󣬱㽫λ��ʹ�õ����ͷ�
            v[k] = 0;
        }
    }
    return;
}


int main() {
    int n;
    cin >> n;

    f(0, n);
    return 0;
}
