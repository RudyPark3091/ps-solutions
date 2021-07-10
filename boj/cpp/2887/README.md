## Problem
[acmicpc.net/problem/2887]  

## Example
input ->  
5  
11 -15 -15  
14 -5 -15  
-1 -1 -5  
10 -4 -1  
19 -4 19  
  
output ->  
4  
  
## Logic
각각의 정점이 3차원 좌표값으로 주어진다.  
각 정점마다 다른 모든 정점과 간선으로 이을 수 있다.  
이때의 간선의 개수는 `N(N-1)/2` 개이고 N은 최대 100,000이므로 모든 경우의 수를 고려하려면 시간이 부족하다.  
다만 이 문제에서 간선의 가중치는 두 정점 사이의 X, Y, Z축상의 거리 중 최솟값에 해당한다.  
좌표값을 기준으로 정렬했을 때, 한 정점에 대해 인접하지 않은 정점과의 간선은 무시할 수 있다.  
따라서 `N(N-1)/2` 개가 아니라 X, Y, Z축 각각 `N-1`개 씩 `3 * (N-1)` 개의 간선만 고려하면 된다.  
모든 정점 정보를 입력받은 뒤 X, Y, Z축 각각에 대해 정렬해준다.  
정렬한 간선을 바탕으로 3차원 좌표상에서 유효한 간선들을 모아 다시 정렬한다.  
정렬된 간선정보로 크루스칼 알고리즘을 이용해 모든 행성을 연결하는데 필요한 최소 비용을 구한다.  

## Source Code
``` cpp
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
```

[acmicpc.net/problem/2887]: https://acmicpc.net/problem/2887
