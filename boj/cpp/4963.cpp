#include <iostream>
using namespace std;

int w, h;
int graph[51][51];
bool visited[51][51] = { false };
int moves[8][2] = {
	{0, 1}, {0, -1},
	{1, 0}, {-1, 0},
	{1, 1}, {-1, -1},
	{1, -1}, {-1, 1},
};

bool input() {
	cin >> w >> h;
	if (w == 0 && h == 0) return true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> graph[i][j];
		}
	}
	return false;
}

void clear_visited() {
	fill(&visited[0][0], &visited[50][51], false);
}

void dfs(int x, int y) {
	if (visited[x][y] || !graph[x][y])
		return;
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + moves[i][0];
		int ny = y + moves[i][1];

		bool bdry = 0 <= nx && nx < h && 0 <= ny && ny < w;
		if (!bdry) continue;
		if (!visited[nx][ny] && graph[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

void solve() {
	while (true) {
		int ans = 0;
		clear_visited();
		bool is_end = input();
		if (is_end) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (graph[i][j] && !visited[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}
