#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> edge;

int n, m;
int a, b, c;
vector<edge> edges;
int parent[100001];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
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

bool cmp(edge a, edge b) {
	return get<2>(a) < get<2>(b);
}

void solve() {
	long long res = 0;
	int _max = 0;
	sort(edges.begin(), edges.end(), cmp);
	for (int i = 0; i < m; i++) {
		edge e = edges[i];
		int a = get<0>(e);
		int b = get<1>(e);
		int cost = get<2>(e);

		if (find_parent(a) != find_parent(b)) {
			_union(a, b);
			_max = max(_max, cost);
			res += cost;
		}
	}
	cout << res - _max << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
