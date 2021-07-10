/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
using namespace std;

string s;
bool is_java = false, is_c = false;
vector<int> undsc, upper;

void to_java() {
	int idx = 0;
	bool up = false;
	for (int i = 0; i < s.length(); i++) {
		if (i == undsc[idx]) {
			idx += 1;
			up = true;
		} else {
			if (up) {
				cout << (char) (s[i] - 32);
				up = false;
			} else cout << s[i];
		}
	}
	cout << '\n';
}

void to_c() {
	int idx = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i == upper[idx]) {
			idx += 1;
			cout << '_' << (char) (s[i] + 32);
		} else {
			cout << s[i];
		}
	}
	cout << '\n';
}

int main() {
	cin >> s;
	if (s[0] == '_' || (int) s[0] <= 90 || s[s.length() - 1] == '_') {
		cout << "Error!" << '\n';
		return 0;
	}

	for (int i = 0; i < s.length(); i++) {
		if ((int) s[i] <= 90) {
			is_java = true;
			upper.push_back(i);
		}
		if (s[i] == '_') {
			if (s[i - 1] == '_') is_java = true;
			is_c = true;
			undsc.push_back(i);
		}

		if (is_java && is_c) {
			cout << "Error!" << '\n';
			return 0;
		}
	}

	if (!is_java && !is_c) cout << s << '\n';
	else is_c ? to_java() : to_c();
	return 0;
}
