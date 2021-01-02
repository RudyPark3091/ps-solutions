#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
typedef pair<int, int> coord;

int n, m;
int a, b, c;
vector<coord> graph[501];
vector<long long> dist(501, INF);

void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}
}

void bf() {
	dist[1] = 0;
	for (int v = 0; v < n; v++) {
		for (int i = 1; i <= n; i++) {
			for (int e = 0; e < graph[i].size(); e++) {
				int _old = graph[i][e].first;
				int _cost = graph[i][e].second;

				if (dist[_old] > dist[i] + _cost) {
					dist[_old] = dist[i] + _cost;
				}
			}
		}
	}

	vector<bool> visited(n + 1, false);
	queue<int> q;
	visited[1] = true;
	q.push(1);

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		for (int i = 0; i < graph[p].size(); i++) {
			int next = graph[p][i].first;
		  
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int _old = graph[i][j].first;
			int _cost = graph[i][j].second;
			if (visited[i] && dist[_old] > dist[i] + _cost) {
				cout << -1 << '\n';
				return;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (visited[i]) cout << dist[i] << '\n';
		else cout << -1 << '\n';
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	bf();

	return 0;
}
