#include <iostream>

using namespace std;

int arry[10];

void print_one_result(int n) {
    //实现对输入的特定下标的范围的数组元素打印
    for (int i = 0; i <= n; i++) {
        if (i) cout << " ";
        cout << arry[i];
    }
    cout << endl;
    return;
}

void f(int i, int j, int n) {
    if (j > n) return;   //边界条件
    //对i位置填入最小j值
    for (int k = j; k <= n; k++) {
        arry[i] = k;
        //每填入一个值后打印输出一次
        print_one_result(i);
        //继续i位置后的i+1位置的填写
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
