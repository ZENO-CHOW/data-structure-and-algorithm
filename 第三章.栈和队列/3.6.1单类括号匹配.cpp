#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;
	int lnum = 0;

	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case '(':
			lnum++;
			break;
		case ')':
			lnum--;
			break;
		}
		if (lnum < 0) {
			std::cout << s << "非法序列1";
			break;
		}
	}
	if (lnum > 0) std::cout << s << "非法序列2";
	else if (lnum == 0) std::cout << s << "正确序列";

	return 0;

}