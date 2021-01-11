#include <iostream>
#include <queue>
using namespace std;

int n;
char arr[51][51];
int moves[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

void swap(char &a, char &b) {
	char t = a;
	a = b;
	b = t;
}

int search(int x, int y) {
	int ret = 1;
	char rune = arr[x][y];

	int _x = x - 1;
	while (arr[_x][y] == rune) {
		ret++;
		_x--;
	}
	_x = x + 1;
	while (arr[_x][y] == rune) {
		ret++;
		_x++;
	}
	int v = ret;
	ret = 1;

	int _y = y - 1;
	while (arr[x][_y] == rune) {
		ret++;
		_y--;
	}
	_y = y + 1;
	while (arr[x][_y] == rune) {
		ret++;
		_y++;
	}
	int h = ret;
	return max(v, h);
}

int solve() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != n-1 && arr[i][j] != arr[i+1][j]) {
				swap(arr[i][j], arr[i+1][j]);
				res = max(res, search(i, j));
				res = max(res, search(i+1, j));
				swap(arr[i][j], arr[i+1][j]);
			}
			if (j != n-1 && arr[i][j] != arr[i][j+1]) {
				swap(arr[i][j] , arr[i][j+1]);
				res = max(res, search(i, j));
				res = max(res, search(i, j+1));
				swap(arr[i][j] , arr[i][j+1]);
			}
		}
	}
	return res;
}

int pre_solve() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res = max(res, search(i, j));
		}
	}
	return res;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	cout << max(pre_solve(), solve()) << '\n';
	return 0;
}
