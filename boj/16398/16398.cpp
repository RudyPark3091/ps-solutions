#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n;
int e = 0;
vector<tuple<int, int, int>> edges;
vector<int> parent(1001);

void input() {
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (j > i) {
				edges.push_back({i, j, x});
				e++;
			}
		}
	}
}

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

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	return get<2>(a) < get<2>(b);
}

void solve() {
	long long res = 0;
	sort(edges.begin(), edges.end(), cmp);
	for (int i = 0; i < e; i++) {
		auto edge = edges[i];
		int a = get<0>(edge);
		int b = get<1>(edge);
		long long cost = get<2>(edge);

		if (find_parent(a) != find_parent(b)) {
			_union(a, b);
			res += cost;
		}
	}
	cout << res << '\n';
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	solve();
	return 0;
}
