#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;
typedef pair<int, int> coord;

int T;
int n, m, t;
int s, g, h;
int a, b, d;
int x;

vector<coord> graph[2001];
vector<int> dest;
priority_queue<coord> q;

void input() {
	cin >> n >> m >> t;
	cin >> s >> g >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		graph[a].push_back({b, d});
		graph[b].push_back({a, d});
	}
	for (int i = 0; i < t; i++) {
		cin >> x;
		dest.push_back(x);
	}
	sort(dest.begin(), dest.end());
}

vector<int> dijkstra(int start) {
	vector<int> dist(n+1);
	fill(dist.begin(), dist.end(), INF);
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

	return dist;
}

void solve(int _s, int _g, int _h) {
	vector<int> d_dist = dijkstra(_s);
	vector<int> g_dist = dijkstra(_g);
	vector<int> h_dist = dijkstra(_h);

	int sg = d_dist[_g];
	int sh = d_dist[_h];
	int gh = 0;
	for (int i = 0; i < graph[_g].size(); i++) {
		if (graph[_g][i].first == _h)
			gh = graph[_g][i].second;
	}
	for (int i = 0; i < dest.size(); i++) {
		bool yes =
			d_dist[dest[i]] == sg + gh + h_dist[dest[i]] ||
			d_dist[dest[i]] == sh + gh + g_dist[dest[i]];
		if (yes) cout << dest[i] << ' ';
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		input();
		solve(s, g, h);
		for (int i = 0; i < 2001; i++) {
			graph[i].clear();
		}
		dest.clear();
		cout << '\n';
	}
	return 0;
}
