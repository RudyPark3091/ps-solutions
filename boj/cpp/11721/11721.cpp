#include <iostream>
using namespace std;

int main() {
	int offset = 0;
	string s;
	cin >> s;

	while (offset < s.size()) {
		cout << s.substr(offset, 10) << '\n';
		offset += 10;
	}
	return 0;
}
