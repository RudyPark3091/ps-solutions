/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int n;
int cnt = 0;
int one[26] = { 0 };
int check[26] = { 0 };

bool solve(string _s) {
	int diff = -1;
	int cnt = 0;
	fill(&check[0], &check[26], 0);

	for (int i = 0; i < _s.length(); i++) check[(int) _s[i] - 'A'] += 1;
	for (int i = 0; i < 26; i++) {
		if (one[i] != check[i]) {
			if (diff == -1) diff = i;
			cnt++;

			if (abs(one[i] - check[i]) >= 2) return false;
			if (cnt == 2 && (one[diff] + one[i]) != (check[diff] + check[i])) return false;
			if (cnt >= 3) return false;
		}
	}
	return true;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	string s, ss;

	cin >> n;
	cin >> s;
	for (int i = 0; i < s.length(); i++) one[(int) s[i] - 'A'] += 1;
	for (int i = 0; i < n - 1; i++) {
		cin >> ss;
		if (solve(ss)) cnt++;
	}

	cout << cnt << '\n';
	return 0;
}
