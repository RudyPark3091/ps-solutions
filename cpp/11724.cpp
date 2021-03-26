#include <iostream>
#include <set>
using namespace std;

int n, m;
int parent[1001];

int find_parent(int x) {
	if (parent[x] != x) parent[x] = find_parent(parent[x]);
	return parent[x];
}

void _union(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

void solve() {
	int x, y;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	set<int> s;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		_union(x, y);
	}
	for (int i = 1; i <= n; i++) {
		s.insert(find_parent(i));
	}
	cout << s.size() << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}

