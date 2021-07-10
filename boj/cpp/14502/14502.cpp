#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int graph[8][8];
bool visited[8][8] = { false };
int moves[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
vector<pair<int, int>> twos;
vector<pair<int, int>> ones;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2) twos.push_back({i, j});
			if (graph[i][j] == 1) ones.push_back({i, j});
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push({x, y});

	while (!q.empty()) {
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = _x + moves[i][0];
			int ny = _y + moves[i][1];

			bool bdry = 0 <= nx && nx < n && 0 <= ny && ny < m;
			if (!bdry) continue;
			if (!visited[nx][ny] && graph[nx][ny] == 0) {
				q.push({nx, ny});
				visited[nx][ny] = true;
				graph[nx][ny] = 2;
			}
		}
	}
}

int evaluate() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				res++;
			}
		}
	}
	return res;
}

int check(
	int x1,
	int y1,
	int x2,
	int y2,
	int x3,
	int y3
) {
	int res = 0;
	graph[x1][y1] = 1;
	graph[x2][y2] = 1;
	graph[x3][y3] = 1;
	for (auto two : twos) {
		int _x = two.first;
		int _y = two.second;
		bfs(two.first, two.second);
	}

	res = evaluate();
	fill(&graph[0][0], &graph[7][8], 0);
	fill(&visited[0][0], &visited[7][8], false);
	for (auto two : twos) graph[two.first][two.second] = 2;
	for (auto one : ones) graph[one.first][one.second] = 1;
		
	return res;
}

int solve() {
	int ret = 0;

	for (int i = 0; i < n * m; i++) {
		for (int j = i + 1; j < n * m; j++) {
			for (int k = j + 1; k < n * m; k++) {
				int x1 = i / m;
				int y1 = i % m;
				int x2 = j / m;
				int y2 = j % m;
				int x3 = k / m;
				int y3 = k % m;

				bool yes = graph[x1][y1] == 0 && graph[x2][y2] == 0 &&
					graph[x3][y3] == 0;
				if (yes) {
					int res = check(x1, y1, x2, y2, x3, y3);
					if (res > ret) ret = res;
				}
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
