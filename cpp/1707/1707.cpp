#include <iostream>
#include <vector>
using namespace std;

int k, v, e;
int a, b;
vector<int> graph[20001];
int visited[20001];

void input() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void dfs(int x, int color) {
	visited[x] = color;
	for (int i = 0; i < graph[x].size(); i++) {
		int _next = graph[x][i];
		if (!visited[_next]) {
			dfs(_next, 3 - color);
		}
	}
}

bool yes() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int _next = graph[i][j];
			if (visited[_next] == visited[i]) return false;
		}
	}
	return true;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> k;
	for (int i = 0; i < k; i++) {
		if (i != 0) {
			for (int i = 1; i <= v; i++) graph[i].clear();
			fill(visited, visited + v + 1, 0);
		}
		input();
		for (int j = 1; j <= v; j++) {
			if (!visited[j]) dfs(j, 1);
		}
		if (yes()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
