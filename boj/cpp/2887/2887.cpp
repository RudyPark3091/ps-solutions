#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int, int> coord;
typedef tuple<int, int, ll> edge;

int n;
int x, y, z;
vector<coord> coords;
vector<edge> edges;
vector<int> parent(100001);

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		coords.push_back({i, x, y, z});
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

bool byCoordX(coord a, coord b) {
	return get<1>(a) < get<1>(b);
}

bool byCoordY(coord a, coord b) {
	return get<2>(a) < get<2>(b);
}

bool byCoordZ(coord a, coord b) {
	return get<3>(a) < get<3>(b);
}

bool cmp(edge a, edge b) {
	return get<2>(a) < get<2>(b);
}

void solve() {
	ll sum = 0;
	sort(coords.begin(), coords.end(), byCoordX);
	for (int i = 1; i < n; i++) {
		int a = get<0>(coords[i - 1]);
		int b = get<0>(coords[i]);
		ll cost = get<1>(coords[i]) - get<1>(coords[i - 1]);
		edges.push_back({a, b, cost});
	}

	sort(coords.begin(), coords.end(), byCoordY);
	for (int i = 1; i < n; i++) {
		int a = get<0>(coords[i - 1]);
		int b = get<0>(coords[i]);
		ll cost = get<2>(coords[i]) - get<2>(coords[i - 1]);
		edges.push_back({a, b, cost});
	}

	sort(coords.begin(), coords.end(), byCoordZ);
	for (int i = 1; i < n; i++) {
		int a = get<0>(coords[i - 1]);
		int b = get<0>(coords[i]);
		ll cost = get<3>(coords[i]) - get<3>(coords[i - 1]);
		edges.push_back({a, b, cost});
	}

	sort(edges.begin(), edges.end(), cmp);
	for (int i = 0; i < edges.size(); i++) {
		edge e = edges[i];
		int a = get<0>(e);
		int b = get<1>(e);
		ll cost = get<2>(e);

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
