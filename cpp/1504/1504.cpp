#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, e;
int v1, v2;
long long graph[801][801];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> n >> e;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	cin >> v1 >> v2;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}

	long long res = min(
		graph[1][v1] + graph[v1][v2] + graph[v2][n],
		graph[1][v2] + graph[v2][v1] + graph[v1][n]
	);
	if (res >= INF) cout << -1 << '\n';
	else cout << res << '\n';
	return 0;
}
