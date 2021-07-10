#include <iostream>
#include <vector>
using namespace std;

int n;
int a, b;
int parent[100001];
bool visited[100001];
vector<vector<int>> graph(100001);

void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		int _next = graph[v][i];
		if (!visited[_next]) {
			parent[_next] = v;
			dfs(_next);
		}
	}
}

void solve() {
	dfs(0);
	for (int i = 1; i < n; i++) {
		cout << parent[i] + 1 << '\n';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
