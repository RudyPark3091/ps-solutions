#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> coord;

int n, m;
bool wall[1000][1000];
int visited[1000][1000][2];
queue<coord> q;
int moves[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void input() {
	string s;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			wall[i][j] = s[j] - '0';
		}
	}
}

int solve(int x, int y, int destx, int desty) {
	visited[x][y][0] = 1;
	q.push({x, y, 0});

	while (!q.empty()) {
		int dx = get<0>(q.front());
		int dy = get<1>(q.front());
		int broken = get<2>(q.front());
		q.pop();

		if (dx == destx && dy == desty) {
			return visited[dx][dy][broken];
		}

		for (int i = 0; i < 4; i++) {
			int nx = dx + moves[i][0];
			int ny = dy + moves[i][1];

			bool bdry = 0 <= nx && nx < n && 0 <= ny && ny < m;
			if (!bdry) continue;
			// 벽이 아니면 방문여부확인 후 탐색
			if (!wall[nx][ny] && visited[nx][ny][broken] == 0) {
				visited[nx][ny][broken] = visited[dx][dy][broken] + 1;
				q.push({nx, ny, broken});
			}
			// 벽이면 이미 부쉈는지 확인
			// 안 부쉈으면
			if (wall[nx][ny] && !broken) {
				visited[nx][ny][broken+1] = visited[dx][dy][broken] + 1;
				q.push({nx, ny, broken+1});
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	cout << solve(0, 0, n-1, m-1) << '\n';

	return 0;
}
