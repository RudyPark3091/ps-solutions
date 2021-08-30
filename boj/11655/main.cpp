/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

string s;

bool isNumber(char c) {
  return 48 <= (int) c && (int) c <= 57;
}

void solve() {
  getline(cin, s);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ' || isNumber(s[i])) continue;
    if (s[i] <= 90 && s[i] + 13 > 90) s[i] = 65 + (s[i] + 13) % 91;
    else if (s[i] <= 122 && s[i] + 13 > 122) s[i] = 97 + (s[i] + 13) % 123;
    else s[i] += 13;
  }
  cout << s << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	solve();
	return 0;
}
