/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve() {
	int n;
	string s;
	map<string, int> m;
	vector<pair<int, int>> v;
	vector<string> vs;
	string ans[1001];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m.insert({s, i});
	}

	for (int i = 0; i < n; i++) {
		cin >> s;
		auto res = m.find(s);
		v.push_back({i, res -> second});
	}

	for (int i = 0; i < n; i++) {
		cin >> s;
		vs.push_back(s);
	}

	for (pair<int, int> item : v) {
		ans[item.second] = vs[item.first];
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

	return 0;
}
