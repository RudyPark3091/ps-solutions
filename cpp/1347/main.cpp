/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int n;
string s;
int moves[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

void solve() {
	bool maze[101][101];
	fill(&maze[0][0], &maze[100][101], false);

	int x1 = 50, y1 = 50, x2 = 50, y2 = 50;
	int x = 50, y =50, dir = 0;
	maze[50][50] = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') {
			dir = (dir + 1) % 4;
		} else if (s[i] == 'L') {
			dir = (dir + 3) % 4;
		} else if (s[i] == 'F') {
			x += moves[dir][0];
			y += moves[dir][1];

			x1 = min(x1, x);
			y1 = min(y1, y);
			x2 = max(x2, x);
			y2 = max(y2, y);

			maze[x][y] = true;
		}
	}

	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			cout << (maze[i][j] ? '.' : '#');
		}
		cout << '\n';
	}
}

int main() {
	cin >> n;
	cin >> s;
	solve();

	return 0;
}
