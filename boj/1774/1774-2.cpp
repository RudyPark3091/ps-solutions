#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;
typedef tuple<int, int, double> edge;
typedef pair<int, int> coord;

int n, m;
int x, y;
int parent[1001];
coord coords[1001];
vector<edge> edges;

double dist(coord x, coord y) {
	ll x1 = x.first;
	ll y1 = x.second;

	ll x2 = y.first;
	ll y2 = y.second;

	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
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
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		coords[i] = {x, y};
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x -= 1;
		y -= 1;
		edges.push_back({x, y, dist(coords[x], coords[y])});
		if (find_parent(x) != find_parent(y)) _union(x, y);
	}
}

bool cmp(edge a, edge b) {
	return get<2>(a) < get<2>(b);
}

void solve() {
	double res = 0.0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i != j) edges.push_back({i, j, dist(coords[i], coords[j])});
		}
	}
	sort(edges.begin(), edges.end(), cmp);

	for (edge e : edges) {
		int a = get<0>(e);
		int b = get<1>(e);
		double cost = get<2>(e);

		if (find_parent(a) != find_parent(b)) {
			_union(a, b);
			res += cost;
		}
	}
	cout << fixed << setprecision(2) << res << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
