#include <iostream>
using namespace std;

int n, m;
int r, c, d;
bool graph[51][51];
bool visited[51][51];
int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void input() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> graph[i][j];
	}
}

void turn_left() {
	d = (d + 3) % 4;
}

bool check_back() {
	int nd = (d + 2) % 4;
	int nx = r + moves[nd][0];
	int ny = c + moves[nd][1];
	if (graph[nx][ny] == 1) {
		return false;
	}
	return true;
}

void move_back() {
	int nd = (d + 2) % 4;
	r = r + moves[nd][0];
	c = c + moves[nd][1];
}

void solve() {
	int ans = 0;
	while (true) {
		if (!graph[r][c] && !visited[r][c]) {
			visited[r][c] = true;
			ans++;
		}

		for (int i = 0; i <= 4; i++) {
			int nd = (d + 3) % 4;
			int nx = r + moves[nd][0];
			int ny = c + moves[nd][1];

			if (!graph[nx][ny] && !visited[nx][ny]) {
				turn_left();
				r = nx;
				c = ny;
				break;
			} else if (graph[nx][ny] || visited[nx][ny]) {
				if (i == 4) {
					if (check_back()) {
						move_back();
						break;
					} else {
						cout << ans << '\n';
						return;
					}
				}
				turn_left();
			}
		}

	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
