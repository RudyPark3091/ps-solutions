#include <iostream>
using namespace std;

int t, n, m, k;
bool graph[50][50];
int moves[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void input() {
	int a, b;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		graph[a][b] = true;
	}
}

bool solve(int dx, int dy) {
	bool bdry = 0 <= dx && dx < n && 0 <= dy && dy < m;
	if (!bdry) return false;

	if (graph[dx][dy]) {
		graph[dx][dy] = false;

		for (int i = 0; i < 4; i++) {
			solve(dx + moves[i][0], dy + moves[i][1]);
		}
		return true;
	}

	return false;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		int res = 0;
		input();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (solve(i, j)) {
					res++;
				}
			}
		}

		cout << res << '\n';
	}
	return 0;
}
