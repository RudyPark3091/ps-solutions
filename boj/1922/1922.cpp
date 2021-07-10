#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> edge;

int n, m;
vector<edge> edges;
vector<int> parent;

void input() {
	int a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
	}
	for (int i = 0; i <= n; i++) {
		parent.push_back(i);
	}
}

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

bool cmp(edge a, edge b) {
	return get<2>(a) < get<2>(b);
}

void solve() {
	sort(edges.begin(), edges.end(), cmp);
	long long sum = 0;
	for (edge e : edges) {
		int a = get<0>(e);
		int b = get<1>(e);
		int cost = get<2>(e);

		if (find_parent(a) != find_parent(b)) {
			_union(a, b);
			sum += cost;
		}
	}
	cout << sum << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
