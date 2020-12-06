#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> coord;

int n, m, h;
int graph[100][100][100];
queue<coord> one;
int moves[6][3] = {
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1},
	{-1, 0, 0},
	{0, -1, 0},
	{0, 0, -1}
};

void input() {
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0 ; k < m; k++) {
				cin >> graph[i][j][k];
				if (graph[i][j][k] == 1)
					one.push({i, j, k});
			}
		}
	}
}

int solve() {
	int ret = 0;

	while (true) {
		queue<coord> q;

		while (!one.empty()) {
			int dz = get<0>(one.front());
			int dx = get<1>(one.front());
			int dy = get<2>(one.front());
			one.pop();

			for (int i = 0; i < 6; i++) {
				int nz = dz + moves[i][0];
				int nx = dx + moves[i][1];
				int ny = dy + moves[i][2];

				bool bdry = 0 <= nz && nz < h && 0 <= nx && nx < n && 0 <= ny && ny < m;
				if (!bdry) continue;
				if (graph[nz][nx][ny] != 0) continue;

				graph[nz][nx][ny] = 1;
				q.push({nz, nx, ny});
			}
		}

		one = q;
		if (one.empty()) break;
		ret++;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (graph[i][j][k] == 0) ret = -1;
			}
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
