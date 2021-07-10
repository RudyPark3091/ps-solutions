#include <iostream>
#include <queue>
using namespace std;

int n;
char arr[101][101];
bool visited[101][101] = { false };
int moves[4][2] = {
	{1, 0}, {0, 1}, {0, -1}, {-1, 0}
};

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

bool bfs(int x, int y) {
	if (visited[x][y]) return false;
	queue<pair<int, int> > q;
	visited[x][y] = true;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = _x + moves[i][0];
			int ny = _y + moves[i][1];

			bool bdry =
				0 <= nx && nx < n && 0 <= ny && ny < n;
			if (!bdry) continue;
			if (!visited[nx][ny] && arr[nx][ny] == arr[x][y]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
	return true;
}

void solve() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (bfs(i, j)) {
				cnt += 1;
			}
			if (arr[i][j] == 'R') arr[i][j] = 'G';
		}
	}
	cout << cnt << ' ';

	fill(&visited[0][0], &visited[100][101], false);
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (bfs(i, j)) {
				cnt += 1;
			}
		}
	}
	cout << cnt << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
