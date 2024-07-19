#include <iostream>
#include <string>
#include <vector>

//栈的深入理解，既栈可以处理具有完全包含关系的问题

int main() {
	int n;
	std::cin >> n;
	std::vector<std::string> v(n), s;
	std::string targe;
	for (int i = 0; i < n; i++) std::cin >> v[i];
	std::cin >> targe;
	for (int j = 0; j < n; j++) {
		if (v[j] == targe) {
			s.push_back(v[j]);
			break;
		}
		if (v[j] == "return") s.pop_back();
		else s.push_back(v[j]);
	}

	for (int k = 0; k < s.size(); k++) {
		std::cout << s[k];
		if (k + 1 < s.size()) std::cout << "->";
	}
	std::cout << std::endl;

	return 0;
}