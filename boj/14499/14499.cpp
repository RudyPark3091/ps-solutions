#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, x, y;
int arr[21][21];
int ops[1001];
int dice[6] = { 0 };
int moves[4][2] = {
	{0, 1}, {0, -1}, {-1, 0}, {1, 0}
};

void input() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> ops[i];
	}
}

void roll(int d) {
	int _dice[6];
	copy(dice, dice + 6, _dice);
	switch(d) {
		case 0:
			dice[0] = _dice[3];
			dice[3] = _dice[5];
			dice[5] = _dice[2];
			dice[2] = _dice[0];
			break;
		case 1:
			dice[0] = _dice[2];
			dice[3] = _dice[0];
			dice[5] = _dice[3];
			dice[2] = _dice[5];
			break;
		case 2:
			dice[0] = _dice[4];
			dice[4] = _dice[5];
			dice[5] = _dice[1];
			dice[1] = _dice[0];
			break;
		case 3:
			dice[0] = _dice[1];
			dice[4] = _dice[0];
			dice[5] = _dice[4];
			dice[1] = _dice[5];
			break;
	}
}

void solve() {
	for (int i = 0; i < k; i++) {
		int op = ops[i] - 1;
		int nx = x + moves[op][0];
		int ny = y + moves[op][1];

		bool bdry =
			0 <= nx && nx < n && 0 <= ny && ny < m;
		if (!bdry) continue;

		roll(op);
		if (arr[nx][ny] == 0) {
			arr[nx][ny] = dice[5];
		} else {
			dice[5] = arr[nx][ny];
			arr[nx][ny] = 0;
		}
		x = nx;
		y = ny;
		cout << dice[0] << '\n';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
