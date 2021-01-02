#include <iostream>
#include <tuple>
#include <queue>
#define INF 1e9
using namespace std;
typedef tuple<int, int, int> edge;

int n, m;
int a, b, c;
edge edges[6001];
bool visited[501];
queue<int> q;

void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		edges[i] = {a, b, c};
	}
}

void is_reachable() {
	visited[1] = true;
	q.push(1);

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (!visited[i] && get<0>(edges[p])) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void bf(int start) {
	long long dist[n+1];
	for (int i = 1; i <= n; i++) {
		if (i == start) dist[i] = 0;
		else dist[i] = INF;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			long long _old = dist[get<1>(edges[j])];
			long long _new = dist[get<0>(edges[j])] + get<2>(edges[j]);
			if (_old > _new) {
				dist[get<1>(edges[j])] = _new;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (visited[get<1>(edges[i])] && dist[get<1>(edges[i])] > dist[get<0>(edges[i])] + get<2>(edges[i])) {
			cout << -1 << '\n';
			return;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (dist[i] == INF) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	is_reachable();
	bf(1);

	return 0;
}
