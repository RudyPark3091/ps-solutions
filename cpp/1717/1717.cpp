#include <iostream>
#include <vector>
using namespace std;

int n, m;
int op, a, b;
vector<int> parent;

int find_parent(int x) {
	if (parent[x] != x) parent[x] = find_parent(parent[x]);
	return parent[x];
}

void merge_team(int _a, int _b) {
	_a = find_parent(_a);
	_b = find_parent(_b);
	if (_a > _b) parent[_a] = _b;
	else parent[_b] = _a;
}

void check_team(int _a, int _b) {
	if (find_parent(_a) == find_parent(_b)) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> op >> a >> b;
		if (op == 0) {
			merge_team(a, b);
		} else if (op == 1) {
			check_team(a, b);
		}
	}
	return 0;
}
