#include <iostream>
#include <vector>
using namespace std;

int n;
bool visited[10001] = { false };
vector<pair<int, int>> graph[10001];

void input() {
	int x, y, z;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}
}

pair<int, int> get_max(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) return b;
	else return a;
}

pair<int, int> dfs(int start, int depth) {
	visited[start] = true;
	pair<int, int> _max = {start, depth};
	for (pair<int, int> child : graph[start]) {
		if (!visited[child.first]) {
			visited[child.first] = true;
			_max = get_max(_max, dfs(child.first, depth + child.second));
		}
	}
	return {_max.first, _max.second};
}

void solve() {
	pair<int, int> point = dfs(1, 0);
	for (auto item : graph) item.clear();
	fill(visited, visited + 10001, false);

	cout << dfs(point.first, 0).second << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
