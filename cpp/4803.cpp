#include <iostream>
#include <vector>
#define MAX 501
using namespace std;

int tc = 0;
int n, m;
int x, y;
bool visited[MAX] = { false };
bool visited2[MAX] = { false };
vector<int> graph[MAX];

void graphify() {
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
}

int dfs(int x) {
	int res = 1;
	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		int nx = graph[x][i];
		if (!visited[nx]) res += dfs(nx);
	}
	return res;
}

int dfs2(int x) {
	int res = graph[x].size();
	visited2[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		int nx = graph[x][i];
		if (!visited2[nx]) res += dfs2(nx);
	}
	return res;
}

void solve() {
	graphify();
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int vertex = dfs(i);
			int edges = dfs2(i);

			if (vertex - 1 == edges / 2) ans++;
		}
	}

	cout << "Case " << tc << ": ";
	if (ans == 0) {
		cout << "No trees." << '\n';
	} else if (ans == 1) {
		cout << "There is one tree." << '\n';
	} else {
		cout << "A forest of " << ans << " trees." << '\n';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	while (true) {
		tc++;
		for (int i = 1; i <= n; i++) graph[i].clear();
		fill(visited, visited + MAX, false);
		fill(visited2, visited2 + MAX, false);
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		solve();
	}

	return 0;
}
