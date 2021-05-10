/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[101][101];
bool visited[101][101];
bool h[101];
int moves[4][2] = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1},
};
int _max = 0;

void setup() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			h[arr[i][j]] = true;
			_max = max(_max, arr[i][j]);
		}
	}
}

bool dfs(int x, int y, int h) {
	if (visited[x][y]) return false;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + moves[i][0];
		int ny = y + moves[i][1];

		bool bdry = 0 <= nx && nx < n && 0 <= ny && ny <= n;
		if (!bdry) continue;

		if (!visited[nx][ny] && arr[nx][ny] > h) {
			dfs(nx, ny, h);
		}
	}
	return true;
}

int search(int h) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] <= h) continue;
			if (dfs(i, j, h)) ret++;
		}
	}
	return ret;
}

void solve() {
	int ans = 1;
	for (int i = 1; i <= _max; i++) {
		fill(&visited[0][0], &visited[100][101], false);
		if (!h[i]) continue;
		else {
			ans = max(search(i), ans);
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
