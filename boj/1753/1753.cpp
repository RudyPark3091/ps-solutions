#include <cstdio>
#include <vector>
#include <queue>
#define INF 3000001
using namespace std;
typedef pair<int, int> coord;

int v, e;
int start;
vector<coord> graph[20001];
priority_queue<coord> q;

void solve(int start) {
	int dist[v+1];
	fill(dist, dist + v+1, INF);
	q.push({0, start});
	dist[start] = 0;

	while (!q.empty()) {
		int d = -q.top().first;
		int now = q.top().second;
		q.pop();

		if (dist[now] < d) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = d + graph[now][i].second;

			if (cost < dist[graph[now][i].first]) {
				dist[graph[now][i].first] = cost;
				q.push({-cost, graph[now][i].first});
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) {
			printf("INF\n");
			continue;
		}
		printf("%d\n", dist[i]);
	}
}

int main() {
	int s, d, value;
	scanf("%d %d", &v, &e);
	scanf("%d", &start);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &s, &d, &value);
		graph[s].push_back({d, value});
	}

	solve(start);

	return 0;
}
