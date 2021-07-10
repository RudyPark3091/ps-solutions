#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool apple[101][101];
int l;
queue<pair<int, bool> > ops;
int d = 0;

deque<pair<int, int> > snake;
bool body[101][101];
int moves[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool is_left(char c) {
	return (int)c - 'A' > 9;
}

void input() {
	int x, y;
	char c;

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		apple[x][y] = true;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		ops.push(make_pair(x, is_left(c)));
	}
}

void turn_right() {
	d = (d + 1) % 4;
}

void turn_left() {
	d = (d + 3) % 4;
}

bool check(int _x, int _y) {
	bool bdry = 1 <= _x && _x <= n && 1 <= _y && _y <= n;
	if (!bdry) return false;
	if (body[_x][_y]) return false;

	return true;
}

void solve() {
	int x = 1;
	int y = 1;

	snake.push_front(make_pair(1, 1));
	body[1][1] = true;

	for (int i = 1; ; i++) {
		pair<int, bool> op = ops.front();

		int nx = x + moves[d][0];
		int ny = y + moves[d][1];

		if (!check(nx, ny)) {
			cout << i << '\n';
			break;
		}

		snake.push_front(make_pair(nx, ny));
		body[nx][ny] = true;

		if (apple[nx][ny]) {
			apple[nx][ny] = false;
		} else {
			body[snake.back().first][snake.back().second] = false;
			snake.pop_back();
		}

		x = nx;
		y = ny;

		if (op.first == i) {
			ops.pop();
			op.second ? turn_left() : turn_right();
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
