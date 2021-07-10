#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
typedef pair<long long, long long> coord;

int n, e;
int v1, v2;
vector<coord> graph[801];
priority_queue<coord> q;

int solve(int start, int dest) {
	int dist[n + 5];
	fill(dist, dist + n+1, INF);
	q.push({0, start});
	dist[start] = 0;

	while (!q.empty()) {
		int d = -q.top().first;
		int now = q.top().second;
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = d + graph[now][i].second;

			if (cost < dist[graph[now][i].first]) {
				dist[graph[now][i].first] = cost;
				q.push({-cost, graph[now][i].first});
			}
		}
	}

	return (dist[dest] == INF ? -1 : dist[dest]);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	cin >> v1 >> v2;

	int cost = solve(1, v1) + solve(v1, v2) + solve(v2, n);
	int cost2 = solve(1, v2) + solve(v2, v1) + solve(v1, n);
	int res = min(cost, cost2);

	if (res == -3) cout << -1 << '\n';
	else cout << res << '\n';

	return 0;
}
