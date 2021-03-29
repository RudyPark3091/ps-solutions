#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int v;
bool visited[MAX] = { false };
vector<pair<int, int>> graph[MAX];

void input() {
	int x, y, z;
	cin >> v;
	for (int i = 0; i < v; i++) {
		cin >> x;
		while (cin >> y, y != -1) {
			cin >> z;
			graph[x].push_back({y, z});
		}
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
	return _max;
}

void solve() {
	pair<int, int> point = dfs(1, 0);
	fill(visited, visited + MAX, false);

	cout << dfs(point.first, 0).second << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
