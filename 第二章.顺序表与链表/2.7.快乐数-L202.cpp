class Solution {
public:
    int GetNext(int x) {
        int d, y = 0;
        while (x) {
            d = x % 10;
            y += d * d;
            x = x / 10;
        }
        return y;
    }

    bool isHappy(int n) {
        int p = n, q = n;
        while (q != 1) {
            p = GetNext(p);
            q = GetNext(GetNext(q));
            if (p == q && p != 1) return false;
        }
        return true;
    }
};