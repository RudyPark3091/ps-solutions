#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string s;
	while (true) {
		cin >> s;
		if (s == "0") break;
		bool flag = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != s[s.size() - i - 1]) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "no" << '\n';
		else cout << "yes" << '\n';
	}
	return 0;
}
