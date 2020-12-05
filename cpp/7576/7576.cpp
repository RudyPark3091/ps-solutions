#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> coord;

int m, n;
int graph[1000][1000];
queue<coord> one;
int moves[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void input() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				one.push({i, j});
		}
	}
}

int solve() {
	int ret = 0;

	while (true) {
		queue<coord> q;

		while (!one.empty()) {
			int dx = one.front().first;
			int dy = one.front().second;
			one.pop();

			for (int i = 0; i < 4; i++) {
				int nx = dx + moves[i][0];
				int ny = dy + moves[i][1];

				bool bdry = 0 <= nx && nx < n && 0 <= ny && ny < m;
				if (!bdry) continue;
				if (graph[nx][ny] != 0) continue;

				graph[nx][ny] = 1;
				q.push({nx, ny});
			}
		}

		one = q;
		if (one.empty()) break;
		ret++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) ret = -1;
		}
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	cout << solve() << '\n';

	return 0;
}
