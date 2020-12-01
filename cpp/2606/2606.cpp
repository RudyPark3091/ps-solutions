#include <iostream>
using namespace std;

int n, m;
int res = 0;
bool graph[101][101];
bool visited[101];

void input() {
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
}

void solve(int start) {
	visited[start] = true;

	for (int i = 1; i <= n; i++) {
		if (graph[start][i] && !visited[i]) {
			res++;
			solve(i);
		}
	}
}

int main() {
	input();
	solve(1);

	cout << res << '\n';
	return 0;
}
