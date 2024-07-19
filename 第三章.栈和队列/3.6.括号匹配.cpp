#include <iostream>
#include "SQ.h"
#include <string>

bool Check_left(const char c) {
	if ('(' == c || '[' == c || '{' == c) return true;
	return false;
}

bool Check_right(const char c) {
	if (')' == c || ']' == c || '}' == c) return true;
	return false;
}
int main() {
	SQstack<char> list(100);
	string s;
	cin >> s;
	int flag = 1;
	for (int i = 0; i < s.size(); i++) {
		if (Check_left(s[i])) list.Push_back(s[i]);
		else if (Check_right(s[i])) {
			switch (s[i]) {
			case ')':
				if (!list.Empty_list() && list.Top() == '(') list.Pop_back();
				else flag = 0;
				break;
			case ']':
				if (!list.Empty_list() && list.Top() == '[') list.Pop_back();
				else flag = 0;
				break;
			case '}':
				if (!list.Empty_list() && list.Top() == '{') list.Pop_back();
				else flag = 0;
				break;
			}
		}
		if (flag == 0) {
			std::cout << s << "非法序列";
			break;
		}
	}
	if (flag == 1 && list.Empty_list()) std::cout << s << "正确序列";
	return 0;
}