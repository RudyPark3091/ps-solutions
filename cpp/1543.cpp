#include <iostream>
using namespace std;

int main() {
	string s;
	string target;
	int ans = 0;
	int offset = 0;

	getline(cin, s);
	getline(cin, target);

	while (offset < (int) s.length()) {
		for (int i = 0; i < (int) target.length(); i++) {
			if (offset + (int) target.length() > (int) s.length()) {
				offset += 1;
				break;
			}

			if (target[i] != s[offset + i]) {
				offset += 1;
				break;
			}
			if (i == (int) target.length() - 1) {
				ans += 1;
				offset += (int) target.length();
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
