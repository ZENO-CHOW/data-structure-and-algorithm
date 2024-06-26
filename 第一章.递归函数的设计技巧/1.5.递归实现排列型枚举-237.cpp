#include <iostream>

using namespace std;

int arry[10];
int v[11] = { 0 };

void print_one_result(int n) {
    //实现对输入的特定下标的范围的数组元素打印
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << arry[i];
    }
    cout << endl;
    return;
}

void f(int i, int n) {
    if (i == n) {
        //每填入一个值后打印输出一次
        print_one_result(n);
        return;
    }
    for (int k = 1; k <= n; k++) {
        if (v[k] == 0) {
            //对i位置填入最小j值
            arry[i] = k;
            v[k] = 1;
            //继续i位置后的i+1位置的填写
            f(i + 1, n);
            //当下一阶段函数运行完成后，便将位置使用的数释放
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
