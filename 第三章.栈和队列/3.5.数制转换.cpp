#include <iostream>
#include "SQ.h"

#if 0
int main() {
	SQstack<int> list(10);
	int num, m, d;
	cin >> num >> d;
	while (num) {
		m = num % d;
		num /= d;
		list.Push_back(m);
	}

	while (!list.Empty_list()) {
		cout << list.Top() << "  ";
		list.Pop_back();
	}

	return 0;
}
#endif