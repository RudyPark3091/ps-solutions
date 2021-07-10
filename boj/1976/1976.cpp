#include <iostream>
using namespace std;

int n, m;
int x, y;
int parent[201];

int find_parent(int x) {
	if (parent[x] != x) parent[x] = find_parent(parent[x]);
	return parent[x];
}

void _union(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			if (x == 1) {
				_union(i, j);
			}
		}
	}

	cin >> x;
	int p = find_parent(x);
	for (int i = 0; i < m - 1; i++) {
		cin >> x;
		if (find_parent(x) != p) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}
