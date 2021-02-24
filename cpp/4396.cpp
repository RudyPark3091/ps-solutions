#include <iostream>
using namespace std;

int n;
char arr1[10][10];
char arr2[10][10];
bool open_flag;
int offset[8][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
	{1, 1},
	{-1, -1},
	{1, -1},
	{-1, 1},
};

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr1[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr2[i][j];
		}
	}
}

void open(int x, int y) {
	int sum = 0;
	if (arr1[x][y] == '*') open_flag = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + offset[i][0];
		int ny = y + offset[i][1];
		bool bdry =
			0 <= nx && nx < n && 0 <= ny && ny < n;
		if (!bdry) continue;
		if (arr1[nx][ny] == '*') sum++;
	}
	arr2[x][y] = (char) sum + '0';
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr2[i][j] == 'x') {
				open(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (open_flag && arr1[i][j] == '*') {
				cout << '*';
			} else {
				cout << arr2[i][j];
			}
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
