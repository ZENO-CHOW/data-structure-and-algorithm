#include <iostream>
#include <vector>
using namespace std;


int f(int i, vector<int>& arry, int n)
{
    if (i > n) return 0;
    return f(i + arry[i - 1], arry, n) + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arry;
    arry.reserve(n);

    for (int j = 0, a; j < n; j++) {
        cin >> a;
        arry.emplace_back(a);
    }
    cout << f(1, arry, n) << endl;
}
