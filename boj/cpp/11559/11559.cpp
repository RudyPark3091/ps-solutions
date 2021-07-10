#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

string field[12];
bool visited[12][6] = { false };
int moves[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void input() {
	string s;
	for (int i = 0; i < 12; i++) {
		cin >> s;
		field[i] = s;
	}
}

int bfs(int x, int y) {
	if (field[x][y] == '.') return 0;
	queue<pair<int, int>> q;
	queue<pair<int, int>> del;
	int n = 0;
	if (!visited[x][y]) {
		visited[x][y] = true;
		q.push({x, y});
		del.push({x, y});
		n = 1;
	}

	while (!q.empty()) {
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = _x + moves[i][0];
			int ny = _y + moves[i][1];
			bool bdry =
				0 <= nx && nx < 12 && 0 <= ny && ny < 6;
			if (!bdry) continue;
			if (!visited[nx][ny] && field[nx][ny] == field[_x][_y]) {
				q.push({nx, ny});
				del.push({nx, ny});
				visited[nx][ny] = true;
				n++;
			}
		}
	}
	if (n > 3) {
		while (!del.empty()) {
			int _x = del.front().first;
			int _y = del.front().second;
			del.pop();
			field[_x][_y] = '.';
		}
	}
	return n;
}

int solve() {
	int res = 0;
	while (true) {
		fill(&visited[0][0], &visited[11][6], false);
		bool flag = true;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (int _n = bfs(i, j)) {
					if (_n > 3) flag = false;
				}
			}
		}

		for(int i = 0; i < 6; i++) {
			int idx = 11;
			for (int j = 11; j >= 0; j--) {
				if (field[j][i] != '.') {
					char p = field[j][i];
					field[j][i] = '.';
					field[idx][i] = p;
					idx--;
				}
			}
		}
		if (flag) break;
		res++;
	}
	return res;
}

int main() {
	input();
	cout << solve() << '\n';
	return 0;
}
