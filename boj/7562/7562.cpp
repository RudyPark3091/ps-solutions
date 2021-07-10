#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int t;
int l;
int x, y;
int tx, ty;
int moves[8][2] = {
	{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
	{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
};
bool visited[301][301];

int bfs(int _x, int _y) {
	queue<tuple<int, int, int>> q;
	q.push({_x, _y, 0});
	visited[_x][_y] = true;

	while (!q.empty()) {
		int px = get<0>(q.front());
		int py = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();

		if (px == tx && py == ty) {
			return c;
		}

		for (int i = 0; i < 8; i++) {
			int nx = px + moves[i][0];
			int ny = py + moves[i][1];

			bool bdry =
				0 <= nx && nx < l && 0 <= ny && ny < l;
			if (!bdry) continue;
			if (!visited[nx][ny]) {
				q.push({nx, ny, c + 1});
				visited[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; i++) {
		fill(&visited[0][0], &visited[300][301], false);
		cin >> l;
		cin >> x >> y;
		cin >> tx >> ty;
		cout << bfs(x, y) << '\n';
	}
	return 0;
}
