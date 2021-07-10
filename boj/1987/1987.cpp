#include <iostream>
using namespace std;

int r, c;
char arr[21][21];
bool used[26] = { false };
int moves[4][2] = {
	{0, 1}, {0, -1},
	{1, 0}, {-1, 0},
};

void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
}

int index(char c) {
	return (int) c - 'A';
}

int dfs(int x, int y, int cnt) {
	int ret = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + moves[i][0];
		int ny = y + moves[i][1];

		bool bdry = 0 <= nx && nx < r && 0 <= ny && ny < c;
		if (!bdry) continue;
		if (!used[index(arr[nx][ny])]) {
			used[index(arr[nx][ny])] = true;
			ret = max(ret, dfs(nx, ny, cnt + 1));
			used[index(arr[nx][ny])] = false;
		}
	}
	return ret;
}

void solve() {
	used[index(arr[0][0])] = true;
	cout << dfs(0, 0, 1) << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
