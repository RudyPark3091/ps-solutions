#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	string s1, s2;
	int c[26] = { 0 };

	cin >> t;
	while (t--) {
		fill(&c[0], &c[26], 0);
		cin >> s1 >> s2;
		for (int i = 0; i < s1.length(); i++) {
			int idx = (int)s1[i] - 'a';
			c[idx] += 1;
		}
		for (int i = 0; i < s2.length(); i++) {
			int idx = (int)s2[i] - 'a';
			c[idx] -= 1;
		}
		for (int i = 0; i < 26; i++) {
			if (c[i] != 0) {
				cout << s1 << " & " << s2 << " are NOT anagrams.\n";
				break;
			}
			if (i == 25) cout << s1 << " & " << s2 << " are anagrams.\n";
		}
	}

	return 0;
}
