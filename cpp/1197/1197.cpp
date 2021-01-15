#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;

int v, e;
int a, b, c;
vector<ll> parent;
vector<tuple<int, int, ll>> graph;

void input() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		graph.push_back({a, b, c});
	}
}

int find_parent(int x) {
	if (parent[x] != x) parent[x] = find_parent(parent[x]);
	return parent[x];
}

void _union(int _a, int _b) {
	_a = find_parent(_a);
	_b = find_parent(_b);
	if (_a > _b) parent[_a] = _b;
	else parent[_b] = _a;
}

void solve() {
	ll sum = 0;
	for (auto edge : graph) {
		int a = get<0>(edge) - 1;
		int b = get<1>(edge) - 1;
		ll cost = get<2>(edge);
		
		if (find_parent(a) != find_parent(b)) {
			_union(a, b);
			sum += cost;
		}
	}
	cout << sum << '\n';
}

bool cmp(tuple<int, int, ll> a, tuple<int, int, ll> b) {
	return get<2>(a) < get<2>(b);
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	parent.reserve(v);
	for (int i = 0; i < v; i++) {
		parent[i] = i;
	}
	sort(graph.begin(), graph.end(), cmp);
	solve();
	return 0;
}
