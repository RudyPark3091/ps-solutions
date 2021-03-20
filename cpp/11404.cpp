#include <iostream>
#define INF 1e9
using namespace std;

int n, m;
int graph[101][101];

void input() {
	int a, b, c;
	cin >> n >> m;
	fill(&graph[0][0], &graph[100][101], INF);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}
	for (int i = 0; i <= n; i++) {
		graph[i][i] = 0;
	}
}

void solve() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] != INF) cout << graph[i][j] << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
