/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
bool arr[101][101];
int moves[4][2] = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

void setup() {
	fill(&arr[0][0], &arr[100][101], false);
	int x1, y1, x2, y2;

	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				arr[j][i] = true;
			}
		}
	}
}

int dfs(int x, int y) {
	if (arr[x][y]) return 0;
	int ret = 1;
	arr[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + moves[i][0];
		int ny = y + moves[i][1];

		bool bdry = 0 <= nx && nx < m && 0 <= ny && ny < n;
		if (bdry && !arr[nx][ny]) {
			ret += dfs(nx, ny);
		}
	}
	return ret;
}

void solve() {
	int ans = 0;
	vector<int> v;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!arr[i][j]) {
				ans++;
				v.push_back(dfs(i, j));
			}
		}
	}

	cout << ans << '\n';
	sort(v.begin(), v.end());
	for (int item: v) {
		cout << item << ' ';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
