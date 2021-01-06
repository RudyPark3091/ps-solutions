#include <iostream>
#include <tuple>
#include <map>
using namespace std;

int a, b;
int n, m;
tuple<int, int, char> robots[101];
tuple<int, char, int> orders[101];
int coord[101][101];
map<char, pair<int, int>> moves;
char directions[] = {'N', 'E', 'S', 'W'};

void input() {
	int _x, _y;
	char _c;
	cin >> b >> a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> _x >> _y >> _c;
		robots[i] = {_y, _x, _c};
		coord[_y][_x] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> _x >> _c >> _y;
		orders[i] = {_x, _c, _y};
	}
	moves['W'] = {0, -1};
	moves['E'] = {0, 1};
	moves['S'] = {-1, 0};
	moves['N'] = {1, 0};
}

void solve() {
	for (auto order: orders) {
		int name = get<0>(order);
		int &_x = get<0>(robots[name]);
		int &_y = get<1>(robots[name]);
		char &_dir = get<2>(robots[name]);

		if (get<1>(order) == 'F') {
			int amt = get<2>(order);
			int nx = _x + moves[_dir].first * amt;
			int ny = _y + moves[_dir].second * amt;

			if (_dir == 'W' || _dir == 'E') {
				for (int j = _y + moves[_dir].second;
						j != ny + moves[_dir].second;
						j += moves[_dir].second) {
					if (coord[_x][j]) {
						cout << "Robot " << name << " crashes into robot "
							<< coord[_x][j] << '\n';
						return;
					} else if (j < 1 || b < j) {
						cout << "Robot " << name << " crashes into the wall\n";
						return;
					}
				}
			} else if (_dir == 'N' || _dir == 'S') {
				for (int j = _x + moves[_dir].first;
						j != nx + moves[_dir].first;
						j += moves[_dir].first) {
					if (coord[j][_y]) {
						cout << "Robot " << name << " crashes into robot "
							<< coord[j][_y] << '\n';
						return;
					} else if (j < 1 || a < j) {
						cout << "Robot " << name << " crashes into the wall\n";
						return;
					}
				}
			}

			coord[_x][_y] = 0;
			coord[nx][ny] = name;
			_x = nx;
			_y = ny;
		} else if (get<1>(order) == 'R') {
			int iter = get<2>(order);
			iter %= 4;

			if (_dir == 'N') _dir = directions[(0 + iter) % 4];
			else if (_dir == 'E') _dir = directions[(1 + iter) % 4];
			else if (_dir == 'S') _dir = directions[(2 + iter) % 4];
			else if (_dir == 'W') _dir = directions[(3 + iter) % 4];
		} else if (get<1>(order) == 'L') {
			int iter = get<2>(order);
			iter %= 4;

			if (_dir == 'N') _dir = directions[(4 - iter) % 4];
			else if (_dir == 'E') _dir = directions[(5 - iter) % 4];
			else if (_dir == 'S') _dir = directions[(6 - iter) % 4];
			else if (_dir == 'W') _dir = directions[(7 - iter) % 4];

		}
	}
	cout << "OK" << '\n';
}

int main() {
	input();
	solve();
	return 0;
}
