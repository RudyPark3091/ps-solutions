#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<string> hear;
vector<string> v;
string s;

void input() {
	cin >> n >> m;
	hear.reserve(n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		hear.push_back(s);
	}
}

void solve() {
	sort(hear.begin(), hear.end());

	v.reserve(m);
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (binary_search(hear.begin(), hear.end(), s)) {
			v.push_back(s);
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
