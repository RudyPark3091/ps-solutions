## Problem
[acmicpc.net/problem/9370]  
  
## Example
생략  
  
## Logic
목적지 후보들을 주고, 지나가야 하는 경로를 하나 준다.  
지나가야 하는 경로는 g-h이다.  
s-g-h 또는 s-h-g 를 거쳐 목적지 후보로 가는 경로가 s에서 목적지 후보까지의 최단 경로라면 택한다.  
정점의 개수가 최대 2000개로 크기 때문에 다익스트라 알고리즘을 사용한다.  
먼저 s에서 목적지 후보들까지의 최단거리를 구한다.  
이때 최종 결과에서 가능한 목적지를 오름차순으로 출력해야 하므로 미리 목적지 후보를 오름차순으로 정렬한다.  
그리고 s-g, s-h까지의 최단거리를 구한 뒤 g-h사이의 거리를 더해준다.  
다익스트라 알고리즘은 시작점에서 다른 모든 점까지의 최단 거리를 계산한다.  
따라서 최단거리 계산 함수를 배열을 반환하는 형태로 구성한다.  
각각 h, g에서 목적지 후보까지의 거리가 처음에 구한 최단거리와 같다면 가능한 도착지가 된다.  
s에서 목적지 후보들, g, h까지를 계산하는 다익스트라, h, g에서 각각 목적지 후보들까지를 계산하는 다익스트라로 총 3회의 다익스트라 알고리즘 연산을 수행한다.  
  
## Source Code
``` cpp
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
```
  
## Review
문제를 장황하게 써놨지만 핵심은 특정 경로를 거쳐 최단경로를 탐색하는 알고리즘이었다.  
또한 제한시간이 3초이지만 테스트케이스가 최대 100개로 시간이 빡빡하기 때문에 효율적인 코드를 써야했다.  

[acmicpc.net/problem/9370]: https://acmicpc.net/problem/9370
