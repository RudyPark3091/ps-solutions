#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, m;
stack<pair<int, int>> s;
vector<int> v;

void solve() {
	cin >> n;
	v.reserve(n);

	for (int i = 0; i < n; i++) {
		cin >> m;
		if (!s.empty() && s.top().first < m) {
			while (!s.empty() && s.top().first < m) {
				v[s.top().second] = m;
				s.pop();
			}
		}
		s.push({m, i});
	}

	while (!s.empty()) {
		v[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);

	solve();

	return 0;
}
