#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> coord;
typedef tuple<ll, int, int> edge;

int n, m;
coord coords[1001];
priority_queue<edge, vector<edge>, greater<edge>> edges;
int parent[1001] = { 0 };

ll dist(coord x, coord y) {
	ll x1 = x.first;
	ll y1 = x.second;

	ll x2 = y.first;
	ll y2 = y.second;
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
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

void input() {
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		coords[i] = {x, y};
	}
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x -= 1;
		y -= 1;
		edges.push({dist(coords[x], coords[y]), x, y});
		if (find_parent(x) != find_parent(y)) _union(x, y);
	}
}

void solve() {
	long double res = 0.0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i != j) edges.push({dist(coords[i], coords[j]), i, j});
		}
	}

	while (!edges.empty()) {
		ll cost = get<0>(edges.top());
		int a = get<1>(edges.top());
		int b = get<2>(edges.top());
		edges.pop();

		if (find_parent(a) != find_parent(b)) {
			_union(a, b);
			res += sqrt(cost);
		}
	}
	cout << fixed << setprecision(2) << (res) << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
