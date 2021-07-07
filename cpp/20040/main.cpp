/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int parents[500001] = { -1 };
int n, m;

int find_parent(int x) {
	if (parents[x] != x) parents[x] = find_parent(parents[x]);
	return parents[x];
}

bool _union(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a > b) parents[a] = b;
	else if (a < b) parents[b] = a;
	else return false;

	return true;
}

void solve() {
	int x, y;
	bool cycle = false;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (!cycle && !_union(x, y)) {
			cout << i + 1 << '\n';
			cycle = true;
		}
	}

	if (!cycle) cout << 0 << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}
